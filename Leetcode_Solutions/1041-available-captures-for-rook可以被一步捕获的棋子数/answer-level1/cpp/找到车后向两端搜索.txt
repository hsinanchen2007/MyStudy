执行用时 :0 ms,在所有 C++ 提交中击败了100.00%的用户 内存消耗 :8.3 MB,在所有 C++ 提交中击败了90.91%的用户

    class Solution {
    public:
        int numRookCaptures(vector<vector<char>>& board) {
            int res=0;
            int a,b;    //车的坐标
            int i,j;
            bool flag = false;  //是否找到车
            for (i=0;i<8;i++)   //搜索行
            {
                vector<char> row = board[i];
                for(j=0;j<8;j++)
                {
                    char piece = row[j];
                    if(piece=='R')  //找到车
                    {
                        a=i,b=j;
                        flag=true;
                        break;
                    }
                }
                
                if(flag)    //同一行向两边搜索
                {
                    for(j=b;j>=0;j--)    
                    {
                        char piece = row[j];
                        if(piece == 'B') break;
                        if(piece == 'p') {res++;break;}
                    }
                    for(j=b;j<8;j++)    
                    {
                        char piece = row[j];
                        if(piece == 'B') break;
                        if(piece == 'p') {res++;break;}
                    }
                    break;  //跳出搜索行
                }
            }
            //同一列向两边搜索
            for(i=a;i>=0;i--)
            {
                if(board[i][b] == 'B') break;
                if(board[i][b] == 'p') {res++;break;}
            }
            for(i=a;i<8;i++)
            {
                if(board[i][b] == 'B') break;
                if(board[i][b] == 'p') {res++;break;}
            }
            
            return res;
        }
    };