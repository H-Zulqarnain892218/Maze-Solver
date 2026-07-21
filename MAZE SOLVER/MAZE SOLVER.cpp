//OWNER: Syed Zulqarnain Haider

/* The whole program is divided into modules with also defining their functions almost on every process:


--> Main Function
--> Color Function


1st Module: Menu.
2nd Module: File Reading.
3rd Module: Coordinates Finding.
4th Module: Recursion.
5th Module: Output.

NOTE: 
--> 6 inputs were given for testing as input.txt file...
--> It also shows output in output.txt file too...
--> Recursion log in trace.txt

*/ 

#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>  //Required to show colors on screen
using namespace std;

// *** Global Variables Below ***
char maze_arr[100][100];
int Rows = 0;
int Cols = 0;
int start_Row, start_Col;
int end_Row, end_Col;
int total_steps = 0;

ofstream trace_file("trace.txt");

// *** Function Prototypes ***
void SetColor(int value);
string show_menu();
bool read(string file_name);
void scan_startAndend();
bool find_path(int r, int c);
void saveO(bool found);

//--------------------------------------------------------------
// MAIN FUNCTION 
//-----------------------------\/-------------------------------

int main()
{
	//1. Getting the file name from the menu
	string file_name=show_menu();
	
	//2. Loading the maze into our array
	if (read(file_name) == false)
	{
		SetColor(12); //RED COLOR
		cout<<"ERROR: Could'nt read the file :("<<endl;
		SetColor(7);  //RESETS BACK
		return 0;
	}
	
	//3. Program finds where 'S' and 'E' are hidden
	scan_startAndend();
	
	//4. Program starts te recursive solver
	trace_file<<"=== Recursion Log Started ==="<<endl;
	
	//MAIN LOGIC LINE
	bool success = find_path(start_Row, start_Col);
	
	//5. Prints and saves the result
	saveO(success);
	
	trace_file.close();
	
	cout<<"\nPleaase! Press Enter to Exit...";
	cin.ignore();
	cin.get();
	return 0;
}

//--------------------------------------------------------------
// COLOR FUNCTION 
//-----------------------------\/-------------------------------

void SetColor(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),value);
}
//--------------------------------------------------------------
// 1st MODULE: MENU
//-----------------------------\/-------------------------------

string show_menu()
{
	int choice;
	string name;
	
	cout<<"========================================="<<endl;
	cout<<" === WELCOME TO MAZE SOLVER PRGORAM === "<<endl;
	cout<<"=========================================\n"<<endl;
	cout<<"         ++++++++ MENU ++++++++ "<<endl;
	cout<<endl;
	cout<<"1. Use Default file (input.txt)"<<endl;
	cout<<"2. Solve the custome file."<<endl;
	cout<<"Select (1/2): ";
	cin>>choice;
	
	if(choice == 2)
	{
		cout<<"Please! Enter the File Name: ";
		cin>>name;
		return name;
	}
	else
	{
		return "input.txt";
	}
}

//--------------------------------------------------------------
// 2nd MODULE: File Reading
//-----------------------------\/-------------------------------

bool read(string file_name)
{
	ifstream my_file(file_name);
	
	if(!my_file.is_open())
	{
		return false;
	}
	
	string line;
	Rows = 0;
	Cols = 0; 
	
	while(getline(my_file, line))
	{
		if(line.empty())
		{
			continue;
		}
		
		int c=0;
		
		//Loop through the string in order to ignore the spaces
		for(int i=0; i<line.length(); i++)
		{
			char letter = line[i];
			
			//To stroe only valid maze characters like : #, ., S, E
			if(letter != ' '&& letter!='\t'&& letter!= '\r')
			{
				maze_arr[Rows][c]=letter;
				c++;
			}
		}
		if(c>0)
		{
			Cols=c;
			Rows++;
		}
	}
	my_file.close();
	return true;
}

//--------------------------------------------------------------
// 3rd MODULE: Find Coordinates
//-----------------------------\/-------------------------------

void scan_startAndend()
{
	for(int i=0; i<Rows; i++)
	{
		for(int j=0; j<Cols; j++)
		{
			if(maze_arr[i][j] == 'S')
			{
				start_Row = i;
				start_Col = j;
			}
			else if(maze_arr[i][j] == 'E')
			{
				end_Row = i;
				end_Col = j;
			}
		}
	}
}

//--------------------------------------------------------------
// 4th MODULE: Recursion
//-----------------------------\/-------------------------------

bool find_path(int r, int c)
{
	total_steps++; //Steps Counter (For Bonus Marks)
	
	//1. The Base Case (IF OUTSIDE THE MAZE)
	if(r<0 || c<0 || r>=Rows || c>=Cols)
	{
		return false;
	}
	
	//2. The Base Case (IF HIT THE WALL '#' OR OUT OWN PATH '*')
	if(maze_arr[r][c]=='#' || maze_arr[r][c] == '*')
	{
		return false;
	}
	
	//3. The Base Case (IF FOUND THE EXIT)
	if(maze_arr[r][c]=='E')
	{
		trace_file<<"SUCCESS : Found Exit at: "<<r<<" , "<<c<<endl;
		return true;
	}
	
	trace_file<<"Visitng: "<<r<<" , "<<c<<endl;
	
	//Saves the current char to put back if needed
	char temp = maze_arr[r][c];
	
	//To Mark this spot as Visited or path
	if(maze_arr[r][c]!='S')
	{
		maze_arr[r][c] = '*';
	}
	
	//RECURSION: Moving in All 4 Directions
	if(find_path(r, c+1) == true)  //Move Right -->
	return true;
	if(find_path(r+1, c) == true)      //Move Down \/
	return true;
	if(find_path(r, c-1) == true)         //Move Left <--
	return true;
	if(find_path(r-1, c) == true)            //Move Up /\
	return true;
	
	//BACKTRACKING : Inorder to undo the mark if it is a dead end
	trace_file<<"BACKTRACKING FROM: "<<r<<" , "<<c<<endl;
	
	if(maze_arr[r][c]!='S')
	{
		maze_arr[r][c] = temp;
	}
	return false;
}

//--------------------------------------------------------------
// 5th MODULE: OUTPUT
//-----------------------------\/-------------------------------

void saveO(bool found)
{
	ofstream outFile("output.txt");
	
	if(found)
	{
		cout<<endl;
		
		// +++ GREEN color used for success message +++
		SetColor(10);
		cout<<"+++ SUCCESS: PATH FOUND! :) +++"<<endl;
		SetColor(7);
		cout<<endl;
		
		//Makes sure that 'S' is visible (DOUBLE CHECKING: Might have been overwritten)
		//The double checking sees and makes sure that the 'S' is there or may be overwritten then overcomes it...
		maze_arr[start_Row][start_Col]='S';
		
		for(int i=0; i<Rows; i++)
		{
			for(int j=0; j<Cols; j++)
			{
				char ch=maze_arr[i][j];
				
				//Writes to file
				outFile<<ch<<" ";
				
				//Print to screen
				if(ch=='*')
				{
					// *** GREEN Color used for highlighting the path ***
					SetColor(10);
					cout<<"* ";
					SetColor(7);
				}
				else
				{
					cout<<ch<<" ";
				}
			}
			cout<<endl;
			outFile<<endl;
		}
		SetColor(10);
		cout<<"\nTotal Recursion Steps: "<<total_steps<<endl;
		cout<<"OUTPUT SAVED TO: 'output.txt'"<<endl;
		SetColor(7);
	}
	else
	{
		SetColor(12);
		cout<<"\n=== FAILURE: NO PATH FOUND :( ==="<<endl;
        SetColor(7);	
	}
	outFile.close();
}