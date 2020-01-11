/*Project members: 
Name						Matric
Saif Al Faied	  			1828615
Borhan Md Uddin				1822665
Khan Md Ferdous Ahmed		1825869
Obeid Salem Ahmed Bashwar 	1813179
*/

#include<iostream>
using namespace std;

//*Function Prototype
void printwelcome();
void printending();
int displayresult(int );
int single_player();
void multi_player();
void max_point(int , int);


//* Global Variables
int frame[10][3];		// Frames for player 1
int frame2[10][3];		// Frames for player 2
int f_Outcome[10];		// Frame Outcome for player 1
int f_Outcome2[10];		// Frame Outcome for player 2
int frameTotal[10];		// Per Frame Total for player 1
int frameTotal2[10];	// Per Frame Total for player 2
int currentFrame = 0;
int totalScore = 0;		//Total Score for player 1
int totalScore2= 0;		//Total Score for player 2
int player_type;

int main(){
	int single;
	
	printwelcome(); //*Function call
	
	while(1){
		cout<<"Input the number of player: ";
		cin>>player_type;
		
		if(player_type==1){
			cout<<"\n\nCongrats!!!\n\nYou are in Single player mode\n\n";
			single=single_player(); //*Single player Function call
			break;
		}
		else if(player_type==2){
			cout<<"\n\nCongrats!!!\n\nYou are in Multiplayer player mode\n\n";
			multi_player(); //Multiplayer Function call
			break;
		}
		else
		cout<<"Wrong Input.\nPlease Try Again.\n"<<endl;	
	}	
	if(player_type==1){
		displayresult(single);//*Function call for player 1 result display
	}	
	
return 0;
}

int single_player(){
	
	//*Points Input for frame 1-8
	do{
	while(1){
	
    cout << "Input roll 1 for frame number " << currentFrame + 1 << endl;
    cin >> frame[currentFrame][0];
    cout << endl;
	if(frame[currentFrame][0]>=0 && frame[currentFrame][0]<11 ){
		break;
	}
	else
	cout<<"Wrong Input!! Please try again!!\n"<<endl;
}
    if (frame[currentFrame][0] == 10){
        cout << "!!!STRIKE!!!\n" << endl;
        f_Outcome[currentFrame] = 2;
        currentFrame++;
    }
    else
    {
    	while(1){
        cout << "Input roll 2 for frame number " << currentFrame + 1 << endl;
        cin >> frame[currentFrame][1];
        cout << endl;
		
		if(frame[currentFrame][1]>=0 && frame[currentFrame][1]<11 ){
			break;
		}
		else
		cout<<"Wrong Input!! Please try again!!\n"<<endl;
		}
		
        if (frame[currentFrame][0] + frame[currentFrame][1] == 10)
        {
            cout << "!!!SPARE!!!\n" << endl;
            f_Outcome[currentFrame] = 1;
            currentFrame++;
        }
        else
        {
            cout << "The total for frame " << currentFrame + 1 <<
            " is: " << frame[currentFrame][0] + frame[currentFrame][1] << endl;
            f_Outcome[currentFrame] = 0;
            currentFrame++;
        }
    }
}
	while (currentFrame < 9);


//*Points Input for frame 1-10
	do{
	while(1){
    cout << "Input roll 1 for frame number " << currentFrame + 1 << endl;
    cin >> frame[currentFrame][0];
    cout << endl;
	if(frame[currentFrame][0]>=0 && frame[currentFrame][0]< 11){
		break;
	}
	else
	cout<<"Wrong Input!! Please try again!!\n"<<endl;
}
    if (frame[currentFrame][0] == 10)
    {
        cout << "!!!STRIKE!!!\n" << endl;
        f_Outcome[currentFrame] = 2;
        cout << "Input roll 2 for frame number " << currentFrame + 1 << endl;
        cin >> frame[currentFrame][1];
        cout << endl;
        cout << "Input roll 3 for frame number " << currentFrame + 1 << endl;
        cin >> frame[currentFrame][2];
        cout << endl;
        currentFrame++;
    }
    else
    {	
    	while(1){
        cout << "Input roll 2 for frame number " << currentFrame + 1 << endl;
        cin >> frame[currentFrame][1];
        cout << endl;
		if(frame[currentFrame][1]>=0 && frame[currentFrame][1]<11){
			break;
		}
		else
			cout<<"Wrong Input!! Please try again!!\n"<<endl;
		}
        if (frame[currentFrame][0] + frame[currentFrame][1] == 10)
        {
            cout << "!!!SPARE!!!\n" << endl;
            f_Outcome[currentFrame] = 1;
            cout << "Input roll 3 for frame number " << currentFrame + 1 << endl;
            cin >> frame[currentFrame][2];
            cout << endl;
            currentFrame++;
        }
        else
        {
            cout << "The total for frame " << currentFrame + 1 <<
            " is: " << frame[currentFrame][0] + frame[currentFrame][1] << endl;
            f_Outcome[currentFrame] = 0;
            currentFrame++;
        }
    }
}
while (currentFrame < 10);

//*Points Count for frame 1-7
	
for (currentFrame = 0; currentFrame < 8 ; currentFrame++)
{
    switch(f_Outcome[currentFrame])
    {
        case 0:
        frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame][1];
        break;
        case 1:
        frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame][1] +
        frame[currentFrame + 1][0];
        break;
        case 2:
        if(f_Outcome[currentFrame + 1] == 2)
        {
            frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame + 1][0] +
            frame[currentFrame + 2][0];
        }
        else
        {
            frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame + 1][0] +
            frame[currentFrame + 1][1];
        }
        break;
    }
}

//*Points Count for frame 8
	
for (currentFrame = 8; currentFrame < 9 ; currentFrame++)
{
    switch(f_Outcome[currentFrame])
    {
        case 0:
        frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame][1];
        break;
        case 1:
        frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame][1] +
        frame[currentFrame + 1][0];
        break;
        case 2:
        frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame + 1][0] +
        frame[currentFrame + 1][1];
        break;
    }
}

//*Points Count for frame 10 
	
for (currentFrame = 9; currentFrame < 10 ; currentFrame++)
{
    switch(f_Outcome[currentFrame])
    {
        case 0:
        frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame][1];
        break;
        case 1:
        frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame][1] +
        frame[currentFrame][2];
        break;
        case 2:
        frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame][1] +
        frame[currentFrame][2];
        break;
    }
}

cout<<"\n\nRESULTS:"<<endl;
//* This loop stands for the Displaying all the frames
for (currentFrame = 0; currentFrame < 10 ; currentFrame++) 
{
    totalScore = totalScore + frameTotal[currentFrame];

    cout << "Frame " << currentFrame + 1 << " Total score: " <<
    frameTotal[currentFrame];
    cout << endl;
}
    return totalScore;
}


void multi_player(){

	do{	//*INPUT FOR Player 1
	while(1){
    cout << "Player 1\nInput roll 1 for frame number " << currentFrame + 1 << endl;
    cin >> frame[currentFrame][0];
    cout << endl;
    
	if(frame[currentFrame][0]>=0 && frame[currentFrame][0]<11){
		break;
	}
	else
	cout<<"Wrong Input!! Please try again!!\n"<<endl;
}
    if (frame[currentFrame][0] == 10)
    {
        cout << "!!!STRIKE!!!\n" << endl;
        f_Outcome[currentFrame] = 2;
        
    }
    else
    {
    	while(1){
        cout << "Input roll 2 for frame number " << currentFrame + 1 << endl;
        cin >> frame[currentFrame][1];
        cout << endl;
		if(frame[currentFrame][1]>=0 && frame[currentFrame][1]<11){
			break;
		}
		else
		cout<<"Wrong Input!! Please try again!!\n"<<endl;
	}
        if (frame[currentFrame][0] + frame[currentFrame][1] == 10)
        {
            cout << "!!!SPARE!!!\n" << endl;
            f_Outcome[currentFrame] = 1;
           
        }
        else
        {
            cout << "The total for frame " << currentFrame + 1 <<
            " is: " << frame[currentFrame][0] + frame[currentFrame][1] << endl;
            f_Outcome[currentFrame] = 0;
          
        }
    }
    
    //*INPUT For  Player 2
    while(1){
    cout << "Player 2\nInput roll 1 for frame number " << currentFrame + 1 << endl;
    cin >> frame2[currentFrame][0];
    cout << endl;
	if(frame2[currentFrame][0]>=0 && frame2[currentFrame][0]<11){
		break;
	}
	else
	cout<<"Wrong Input!! Please try again!!\n"<<endl;
}
    if (frame2[currentFrame][0] == 10)
    {
        cout << "!!!STRIKE!!!\n" << endl;
        f_Outcome2[currentFrame] = 2;
        currentFrame++;
    }
    else{
		while(1){
        cout << "Input roll 2 for frame number " << currentFrame + 1 << endl;
        cin >> frame2[currentFrame][1];
        cout << endl;
		
		if(frame2[currentFrame][1]>=0 && frame2[currentFrame][1]<11){
			break;
		}
		else
		cout<<"Wrong Input!! Please try again!!\n"<<endl;
	}
        if (frame2[currentFrame][0] + frame2[currentFrame][1] == 10)
        {
            cout << "!!!SPARE!!!\n" << endl;
            f_Outcome2[currentFrame] = 1;
            currentFrame++;
        }
        else
        {
            cout << "The total for frame " << currentFrame + 1 <<
            " is: " << frame2[currentFrame][0] + frame2[currentFrame][1] << endl;
            f_Outcome2[currentFrame] = 0;
            currentFrame++;
        }
    }
}
	while (currentFrame < 9);


	//*Points input for frame 1-10
	//*Input POINTS Player 1
	do{			
	while(1){
    cout << "Player 1\n\nInput roll 1 for frame number " << currentFrame + 1 << endl;
    cin >> frame[currentFrame][0];
    cout << endl;
	if( frame[currentFrame][0]>=0 &&  frame[currentFrame][0]<11){
		break;
	}
	else
	cout<<"Wrong Input!! Please try again!!\n"<<endl;
	}
    if (frame[currentFrame][0] == 10)
    {
        cout << "!!!STRIKE!!!\n" << endl;
        f_Outcome[currentFrame] = 2;
        while(1){
		cout << "Input roll 2 for frame number " << currentFrame + 1 << endl;
        cin >> frame[currentFrame][1];
        cout << endl;
        if(frame[currentFrame][1]>=0 && frame[currentFrame][1]<11){
        	break;
		}
		else
			cout<<"Wrong Input!! Please try again!!\n"<<endl;
		}
        cout << "Input roll 3 for frame number " << currentFrame + 1 << endl;
        cin >> frame[currentFrame][2];
        cout << endl;
     
    }
    else
    {
    	while(1){
        cout << "Input roll 2 for frame number " << currentFrame + 1 << endl;
        cin >> frame[currentFrame][1];
        cout << endl;
		if(frame[currentFrame][1]>=0 && frame[currentFrame][1]<11){
			break;
		}
		else
			cout<<"Wrong Input!! Please try again!!\n"<<endl;	
	}
        if (frame[currentFrame][0] + frame[currentFrame][1] == 10)
        {
            cout << "!!!SPARE!!!\n" << endl;
            f_Outcome[currentFrame] = 1;
            while(1){
            cout << "Input roll 3 for frame number " << currentFrame + 1 << endl;
            cin >> frame[currentFrame][2];
            cout << endl;
            if(frame[currentFrame][2]>=0 && frame[currentFrame][2]<11){
            	break;
			}
			else
			cout<<"Wrong Input!! Please try again!!\n"<<endl;	
        }
		}
        else
        {
            cout << "The total for frame " << currentFrame + 1 <<
            " is: " << frame[currentFrame][0] + frame[currentFrame][1] << endl;
            f_Outcome[currentFrame] = 0;
           
        }
    }
    
    //*Points input for frame 1-10
    //* For Player 2
    while(1){
    cout << "Player 2\n\nInput roll 1 for frame number " << currentFrame + 1 << endl;
    cin >> frame2[currentFrame][0];
    cout << endl;
	if( frame2[currentFrame][0]>=0 &&  frame2[currentFrame][0]<11){
		break;
	}
	else
		cout<<"Wrong Input!! Please try again!!\n"<<endl;	
	}
	
    if (frame2[currentFrame][0] == 10)
    {
        cout << "!!!STRIKE!!!\n" << endl;
        f_Outcome2[currentFrame] = 2;
        while(1){
        cout << "Input roll 2 for frame number " << currentFrame + 1 << endl;
        cin >> frame2[currentFrame][1];
        cout << endl;
        if(frame2[currentFrame][1]>=0 && frame2[currentFrame][1]<11){
        	break;
		}
		else
			cout<<"Wrong Input!! Please try again!!\n"<<endl;	
		}
        
        while(1){
			cout << "Input roll 3 for frame number " << currentFrame + 1 << endl;
       		cin >> frame2[currentFrame][2];
    		cout << endl;
        
			if(frame2[currentFrame][2]>=0 && frame2[currentFrame][2]<11){
        		break;
			}
			else
			cout<<"Wrong Input!! Please try again!!\n"<<endl;
		}
        currentFrame++;
    }
    else
    {
    	while(1){
        cout << "Input roll 2 for frame number " << currentFrame + 1 << endl;
        cin >> frame2[currentFrame][1];
        cout << endl;
		if(frame2[currentFrame][1]>=0 && frame2[currentFrame][1]<11){
			break;
		}
		else
		cout<<"Wrong Input!! Please try again!!\n"<<endl;
	}
        if (frame2[currentFrame][0] + frame2[currentFrame][1] == 10)
        {
            cout << "!!!SPARE!!!\n" << endl;
            f_Outcome2[currentFrame] = 1;
            while(1){
            cout << "Input roll 3 for frame number " << currentFrame + 1 << endl;
            cin >> frame2[currentFrame][2];
            cout << endl;
            if(frame2[currentFrame][2]>=0 && frame2[currentFrame][2]<11){
            	break;
			}
			else
				cout<<"Wrong Input!! Please try again!!\n"<<endl;
			}
           currentFrame++;
        }
        else
        {
            cout << "The total for frame " << currentFrame + 1 <<
            " is: " << frame2[currentFrame][0] + frame2[currentFrame][1] << endl;
            f_Outcome2[currentFrame] = 0;
            currentFrame++;
        }
    }
}
while (currentFrame < 10);

//*Points Count for frame 1-7
	
for (currentFrame = 0; currentFrame < 8 ; currentFrame++)
{
    switch(f_Outcome[currentFrame]) //*Player 1 Calculation
    {
        case 0:
        frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame][1];
        break;
        case 1:
        frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame][1] +
        frame[currentFrame + 1][0];
        break;
        case 2:
        if(f_Outcome[currentFrame + 1] == 2)
        {
            frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame + 1][0] +
            frame[currentFrame + 2][0];
        }
        else
        {
            frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame + 1][0] +
            frame[currentFrame + 1][1];
        }
    }
    
	switch(f_Outcome2[currentFrame])//*Player 2 Calculation
    {
        case 0:
        frameTotal2[currentFrame] = frame2[currentFrame][0] + frame2[currentFrame][1];
        break;
        case 1:
        frameTotal2[currentFrame] = frame2[currentFrame][0] + frame2[currentFrame][1] +
        frame2[currentFrame + 1][0];
        break;
        case 2:
        if(f_Outcome2[currentFrame + 1] == 2)
        {
            frameTotal2[currentFrame] = frame2[currentFrame][0] + frame2[currentFrame + 1][0] +
            frame2[currentFrame + 2][0];
        }
        else
        {
            frameTotal2[currentFrame] = frame2[currentFrame][0] + frame2[currentFrame + 1][0] +
            frame2[currentFrame + 1][1];
        }
    }
}

//*Points Count for frame 8 
//*Player 1 Calculation
for (currentFrame = 8; currentFrame < 9 ; currentFrame++)  
{
    switch(f_Outcome[currentFrame]) 
    {
        case 0:
        frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame][1];
        break;
        case 1:
        frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame][1] +
        frame[currentFrame + 1][0];
        break;
        case 2:
        frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame + 1][0] +
        frame[currentFrame + 1][1];
        break;
    }
}
//*Points Count for frame 8
//* Player 2 Calculation
for (currentFrame = 8; currentFrame < 9 ; currentFrame++){  
    switch(f_Outcome2[currentFrame]) 
    {
        case 0:
        frameTotal2[currentFrame] = frame2[currentFrame][0] + frame2[currentFrame][1];
        break;
        case 1:
        frameTotal2[currentFrame] = frame2[currentFrame][0] + frame2[currentFrame][1] +
        frame2[currentFrame + 1][0];
        break;
        case 2:
        frameTotal2[currentFrame] = frame2[currentFrame][0] + frame2[currentFrame + 1][0] +
        frame2[currentFrame + 1][1];
        break;
    }
}

//*Points Count for frame 10 Player 1	
for (currentFrame = 9; currentFrame < 10 ; currentFrame++)
{
    switch(f_Outcome[currentFrame]) //*player 1
    {
        case 0:
        frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame][1];
        break;
        case 1:
        frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame][1] +
        frame[currentFrame][2];
        break;
        case 2:
        frameTotal[currentFrame] = frame[currentFrame][0] + frame[currentFrame][1] +
        frame[currentFrame][2];
        break;
    }
}
//*Points Count for frame 10 Player 2
for (currentFrame = 9; currentFrame < 10 ; currentFrame++){
    switch(f_Outcome2[currentFrame]) { 
        case 0:
        frameTotal2[currentFrame] = frame2[currentFrame][0] + frame2[currentFrame][1];
        break;
        case 1:
        frameTotal2[currentFrame] = frame2[currentFrame][0] + frame2[currentFrame][1] +
        frame2[currentFrame][2];
        break;
        case 2:
        frameTotal2[currentFrame] = frame2[currentFrame][0] + frame2[currentFrame][1] +
        frame2[currentFrame][2];
        break;
    	}
	}

//* This loop stands for the Displaying all the frames & points
cout<<"\n\nRESULTS:"<<endl;
for (currentFrame = 0; currentFrame < 10 ; currentFrame++){
    totalScore += frameTotal[currentFrame];
	totalScore2 += frameTotal2[currentFrame];
    
	cout << "Player 1 Frame " << currentFrame + 1 << " Total score: " <<
    frameTotal[currentFrame]<<endl;
	cout << "Player 2 Frame " << currentFrame + 1 << " Total score: " <<
    frameTotal2[currentFrame]<<endl;
    cout << endl;
}
 	
    max_point(totalScore,totalScore2); //*function call for multiplayer result
}

int displayresult(int Total){ //*function for single player result
	cout << "Total score = " << totalScore << endl; 
	printending();
	system("PAUSE");	

}

 void max_point(int t1, int t2){	//*function for multiplayer result 
	int total ;
	cout<<"\n\nPlayer 1 Total Score: "<<t1<<endl;
	cout<<"\n\nPlayer 2 Total Score: "<<t2<<endl;
	if(t1>t2){
		cout<<"\n\n!!!!Congratulation!!!!\n\nPlayer 1 is the winner!!!\n\n"<<endl;
		printending();
		system("PAUSE");
	}
	if(t1<t2){
		cout<<"\n\n!!!!Congratulation!!!!\n\nPlayer 2 is the winner!!!\n\n"<<endl;
		printending();
		system("PAUSE");
	}
	
	if(t1==t2){
		cout<<"\n\nIts a Draw!!!\n\n"<<endl;
		printending();
		system("PAUSE");
		
	}
	
}

void printwelcome(){
	cout<<"\n*******************************************************************"<<endl;	
	cout<<"***********************Welcome To Bowling Allay********************"<<endl;
	cout<<"*******************************************************************"<<endl<<endl;
	cout<<"Here you can play Single or Multiplayer Bowling Game\naccourding to your choice!"<<endl<<endl;;
}

void printending(){
	cout<<"\n\nThank you Very much for playing.\n"<<endl;
}

