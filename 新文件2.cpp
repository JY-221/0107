#include <iostream>
#include <windows.h>

using namespace std;

int board[4][4] = {
    {0, 0, 1, 0},
    {0, 4, 0, 0},
    {0, 0, 2, 0},
    {0, 1, 0, 0},
};

bool editable[4][4];

int cur_r = 0, cur_c = 0;
char c;

int check_horizontal(int i,int j)
{

    /* TODO: Check if a horizontal line has conflict number, or is finished. */
    
    int k=0,t=0,r=0;/*k是判斷錯的，t是判斷有幾個不等於0的數字，r是判斷對的*/
    
    
	for(int m=0;m<4;m++){
    		if(board[i][m]!=0){
    			t++;/*判斷有幾個不為0的數字*/ 
			}
			}
	if(k>t){
		return 1;/*1代表錯的，下面呼叫如果這個函式回傳值是1代表is_invalid要return true*/

	}
	else if(r==12){
		return 2;/*2代表是對的，下面呼叫如果這個函式回傳值是2代表is_done要return true*/
	}
    return 0;/*因為不可能值有錯的或對的兩種狀況(可能也有未完成的情況)，所以不用bool(這似乎只能回傳對跟錯，用int的話就還是要回傳一個數字(隨便任何數字都可以)，如果沒有這行跑出來就變成只有特定情況會回傳數值就不符合函式規定*/


}

int check_vertical(int i,int j)
{
    /* TODO: Check if a vertical line has conflict number, or is finished. */
    
    int k=0,t=0,r=0;/*k是判斷錯的，t是判斷有幾個不等於0的數字，r是判斷對的*/
    
    for(int n=0;n<4;n++){
    	for(int m=0;m<4;m++){
    		if(board[n][j]==board[m][j]&&board[n][j]!=0){
    			k++;
			}
			else if(board[n][j]!=board[m][j]&&board[n][j]!=0){
				r++;/*如果board[n][j]跟其他數字不一樣就加一，總共判斷四個數字，每個數字都要跟其他三個不一樣，r是12代表每個數字跟另外三個不一樣*/

			}
		}
	}
	for(int m=0;m<4;m++){
    		if(board[m][j]!=0){
    			t++;/*判斷有幾個不為0的數字*/ 
			}
			}
	if(k>t){
		return 1;/*1代表錯的，下面呼叫如果這個函式回傳值是1代表is_invalid要return true*/

	}
	else if(r==12){
		return 2;/*2代表是對的，下面呼叫如果這個函式回傳值是2代表is_done要return true*/
	}
    return 0;/*因為不可能值有錯的或對的兩種狀況(可能也有未完成的情況)，所以不用bool(這似乎只能回傳對跟錯，用int的話就還是要回傳一個數字(隨便任何數字都可以)，如果沒有這行跑出來就變成只有特定情況會回傳數值就不符合函式規定*/


    
}

int check_block(int i,int j)
{
    /* TODO: Check if a block has conflict number, or is finished. */
    int k=0,t=0;
    if(i<2&&j<2){/*判斷左上角那四格*/ 
    	for(int n=0;n<2;n++){
    		for(int m=0;m<2;m++){
    			if(board[n][m]!=0){
    				t++;
				}
				/*每個數字分別和其他數字依序比較有沒有重複的*/ 
    			if(board[n][m]==board[0][0]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[0][1]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[1][0]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[1][1]&&board[n][m]!=0){
    				k++;
				}
			}
		}
	}
	else if(i<2&&j>1){/*判斷右上角那四格*/
    	for(int n=0;n<2;n++){
    		for(int m=2;m<4;m++){
    			if(board[n][m]!=0){
    				t++;
				}
				/*每個數字分別和其他數字依序比較有沒有重複的*/
    			if(board[n][m]==board[0][2]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[0][3]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[1][2]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[1][3]&&board[n][m]!=0){
    				k++;
				}
			}
		}
	}
	else if(i>1&&j<2){/*判斷左下角那四格*/
    	for(int n=2;n<4;n++){
    		for(int m=0;m<2;m++){
    			if(board[n][m]!=0){
    				t++;
				}
				/*每個數字分別和其他數字依序比較有沒有重複的*/
    			if(board[n][m]==board[2][0]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[2][1]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[3][0]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[3][1]&&board[n][m]!=0){
    				k++;
				}
			}
		}
	}
	else if(i>1&&j>1){/*判斷右下角那四格*/
    	for(int n=2;n<4;n++){
    		for(int m=2;m<4;m++){
    			if(board[n][m]!=0){
    				t++;
				}
				/*每個數字分別和其他數字依序比較有沒有重複的*/
    			if(board[n][m]==board[2][2]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[2][3]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[3][2]&&board[n][m]!=0){
    				k++;
				}
				if(board[n][m]==board[3][3]&&board[n][m]!=0){
    				k++;
				}
			}
		}
	}
	if(k>t){
		return 1;/*如果有重複的數字個數比不是0的數字個數還要大，代表是錯的，return 1 ,在下面呼叫如果這個函式回傳值是1代表is_invalid要return true*/
	}
	if (k==4){
		return 2; /*代表都是對的，return 2， 下面呼叫如果這個函式回傳值是2代表is_done要return true*/
	}
	return 0;
}




void fill_number(char c)
{
    /* TODO: Fill a number in to the cell the cursor is now pointing to.
             After fill in the number, check the horizontal line, the
             vertical line and the block the cell is in.
     */
     if (c=='1'){
     		board[cur_r][cur_c]=1; /*把游標所在的地方賦值1*/ 
     		return;
		 }
		 
		else if (c=='2'){
     		board[cur_r][cur_c]=2;/*把游標所在的地方賦值2*/
     		return;
		 }
     	
     	else if (c=='3'){
     		board[cur_r][cur_c]=3;/*把游標所在的地方賦值3*/
     		return;
		 }
		
		else if (c=='4'){
			board[cur_r][cur_c]=4;/*把游標所在的地方賦值4*/
			return;
		}
		else if (c=='0'){
			board[cur_r][cur_c]=0;/*把游標所在的地方賦值0，清除數字*/
			return;
		}

}

void move_cursor(char c)
{
    /* TODO: Move the cursor up, down, to the left or to the right.
             Remember to check if the cursor is moving out of bound.
    */
      if(c=='w'||c=='W'){
		if(cur_r-1>=0/*判斷游標停留的位置的上面一格有沒有超出上端的邊界*/){
			if(editable[cur_r-1][cur_c]==0/*判斷游標停留的位置的上面一格是不是題目給的數字*/){
				cur_r-=2;/*跳過原本題目數字的那格*/ 
			}
			else{
				cur_r--;/*直接往上一格*/ 
			}
		}
	}
	else if(c=='s'||c=='S'){
    	if(cur_r+1<4/*判斷游標停留的位置再往下一格有沒有超出邊界*/){
			if(editable[cur_r+1][cur_c]==0)/*判斷游標停留的位置的下面一格是不是題目給的數字*/{
				cur_r+=2;/*跳過原本題目數字的那格*/ 
			}
			else{
				cur_r++;/*直接往下一格*/ 
			}
		}
	}
	else if(c=='d'||c=='D'){
    	if(cur_c+1<4)/*判斷游標停留的位置往右邊一格有沒有超出邊界*/{
			if(editable[cur_r][cur_c+1]==0)/*判斷游標停留的位置的右邊一格是不是題目給的數字*/{
				cur_c+=2;/*跳過原本題目數字的那格*/ 
			}
			else{
				cur_c++;/*直接往右一格*/ 
			}
		}
	}
	else if(c=='a'||c=='A'){
    	if(cur_c-1>=0)/*判斷游標停留的位置的左邊一格*/{
			if(editable[cur_r][cur_c-1]==0)/*判斷游標停留的位置的左邊一格是不是題目給的數字*/{
				cur_c-=2;/*跳過原本題目數字的那格*/ 
			}
			else{
				cur_c--;/*直接往左一格*/
			}
		}
	}


}

bool is_invalid(int i, int j)
{
   
    /* TODO: Check if board[i][j] is in a line that has conflict numbers. */
    /*分別執行判斷直排、橫排、方塊裡面的狀況*/ 
   
    if(check_horizontal(i,j)==1){
    	return true; /*如果 check_horizontal(i,j) return 1，代表是錯的答案*/ 
	}
	else if(check_block(i,j)==1){
    	return true;/*如果 check_block(i,j) return 1，代表是錯的答案*/
	}
	else if(check_vertical(i,j)==1){
    	return true; /*如果 check_vertical(i,j) return 1，代表是錯的答案*/
	}
    return false;/*其餘 return false 代表都是對的*/ 
}

bool is_done(int i, int j)
{
    /* TODO: Check if board[i][j] is in a line that has finished. */
    /*分別執行判斷直排、橫排、方塊裡面的狀況*/
    check_horizontal(i,j);
    check_block(i,j);
    check_vertical(i,j);
    
    if(check_horizontal(i,j)==2){
    	return true;/*如果 check_horizontal(i,j) return 2，代表是對的答案*/
	}
	else if(check_block(i,j)==2){
    	return true;/*如果 check_block(i,j) return 2，代表是對的答案*/
	}
	else if(check_vertical(i,j)==2){
    	return true; /*如果 check_vertical(i,j) return 2，代表是對的答案*/ 
	}
    return false;
}


bool check_win()
{	
/* TODO: Check if the game is set. That is, every cell is finished. */
    int k=0;
    for(int t=0;t<4;t++){
    	if(check_horizontal(t,0)==2){k++;
		}
    	if(check_vertical(0,t)==2){k++;
		}
	}
	/*判斷直排根橫排是不是都是對的，每個都執行四次*/ 
	
	
	if(k==12)return true;/*如果每個條件都有符合的話k值就會是12， return true*/ 
    return false;

}


bool is_moving_action(char c)
{
    return (c == 'W' || c == 'w' || c == 'S' || c == 's' ||
            c == 'A' || c == 'a' || c == 'D' || c == 'd');
}

bool is_filling_action(char c)
{
    return (c >= '0' && c <= '4');
}

string get_styled_text(string text, string style)
{
    string color = "", font = "";
    for (char c : style)
    {
        if (c == 'R')
            color = "31";
        if (c == 'G')
            color = "32";
        if (c == 'E')
            color = "41";
        if (c == 'C')
            color = "106";
        if (c == 'B')
            font = ";1";
    }
    return "\x1b[" + color + font + "m" + text + "\x1b[0m";
}

void print_board()
{
    // Flush the screen
    cout << "\x1b[2J\x1b[1;1H";

    // Print usage hint.
    cout << get_styled_text("W/A/S/D: ", "B") << "move cursor" << endl;
    cout << get_styled_text("    1-4: ", "B") << "fill in number" << endl;
    cout << get_styled_text("      0: ", "B") << "clear the cell" << endl;
    cout << get_styled_text("      Q: ", "B") << "quit" << endl;
    cout << endl;

    // Iterate through and print each cell.
    for (int i = 0; i < 4; ++i)
    {
        // Print horizontal divider.
        if (i && i % 2 == 0)
            cout << "---------------" << endl;

        // Print the first vertical divider in each line.
        cout << "|";
        for (int j = 0; j < 4; ++j)
        {
            // Set text style based on the state of the cell.
            string style = "";

            // Set style for the cell the cursor pointing to.
            if (cur_r == i && cur_c == j)
                style = "C";
            // Set style for the cell in an invalid line.
            else if (is_invalid(i, j))
                style = "E";
            // Set style for the cell in a finished line.
            else if (is_done(i, j))
                style = "G";

            // Set style for a the cell that is immutable.
            if (!editable[i][j])
                style += "B";

            // Print the cell out in styled text.
            // If the content is 0, print a dot, else print the number.
            if (board[i][j] == 0)
                cout << get_styled_text(" · ", style);
            else
                cout << get_styled_text(" " + to_string(board[i][j]) + " ", style);

            // Print the vertical divider for each block.
            if ((j + 1) % 2 == 0)
                cout << "|";
        }
        cout << endl;
    }
}

void initialize()
{
    // Set up styled text for Windows.
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    // Mark editable cells
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            editable[i][j] = !board[i][j];

    // Print the initial board out.
    print_board();
}

int main()
{
    char c;
    bool action_ok;

    initialize();
    while (cin >> c)
    {
        action_ok = false;
        if (is_moving_action(c))
        {
            action_ok = true;
            move_cursor(c);
        }

        if (is_filling_action(c))
        {
            action_ok = true;
            fill_number(c);
        }

        if (c == 'Q' || c == 'q')
            break;

        print_board();
        
        if (check_win())
        {
            cout << "YOU WIN!" << endl;
            break;
        }
        
      
        if (!action_ok)
            cout << get_styled_text("!!! Invalid action !!!", "R");
    }

    return 0;
}


