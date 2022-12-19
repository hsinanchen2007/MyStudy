```
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int target=n*n;
        int num=1;
        int up=0,right=n-1,left=0,down=n-1;
        int now_x=0,now_y=0;
        while(num<=target){
            if(num<=target){
                now_y=left;
                for(int i=left;i<=right;++i){
                    ans[now_x][now_y]=num;
                    ++now_y;
                    ++num;
                }
                --now_y;
                ++up;
            }
            if(num<=target){
                now_x=up;
                for(int i=up;i<=down;++i){
                    ans[now_x][now_y]=num;
                    ++now_x;
                    ++num;
                }
                --now_x;
                --right;
            }
            if(num<=target){
                now_y=right;
                for(int i=right;i>=left;--i){
                    ans[now_x][now_y]=num;
                    --now_y;
                    ++num;
                }
                ++now_y;
                --down;
            }
            if(num<=target){
                now_x=down;
                for(int i=down;i>=up;--i){
                    ans[now_x][now_y]=num;
                    --now_x;
                    ++num;
                }
                ++now_x;
                ++left;
            }
        }
        return ans;
    }
};
```
