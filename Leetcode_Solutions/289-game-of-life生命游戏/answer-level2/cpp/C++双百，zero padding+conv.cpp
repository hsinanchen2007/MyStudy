### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp;
        int sum;
        int h = board.size();
        if(h){
            int w = board[0].size();
            if(w){
                vector<int> l_;
                for(int i=0;i<w+2;i++){
                    l_.push_back(0);
                }
                temp.push_back(l_);

                for(int i=0;i<h;i++){
                    vector<int> l;
                    l.push_back(0);
                    for(int j=0;j<w;j++){
                        l.push_back(board[i][j]);
                    }
                    l.push_back(0);
                    temp.push_back(l);
                }
                temp.push_back(l_);

                for(int i=1;i<h+1;i++){
                    for(int j=1;j<w+1;j++){
                        sum=0;
                        sum+=temp[i-1][j-1];
                        sum+=temp[i-1][j];
                        sum+=temp[i-1][j+1];
                        sum+=temp[i][j-1];
                        sum+=temp[i][j+1];
                        sum+=temp[i+1][j-1];
                        sum+=temp[i+1][j];
                        sum+=temp[i+1][j+1];
                        if(temp[i][j]==1){
                            if(sum<2||sum>3){
                                board[i-1][j-1]=0;
                            }
                            else{
                                board[i-1][j-1]=1;
                            }
                        }
                        else{
                            if(sum==3){
                                board[i-1][j-1]=1;
                            }
                        }
                    }
                }
            }
        }
    }
};
```