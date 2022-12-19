### 解题思路
该题和数独差不多，甚至更简单，写起来就像在套模版一样，一遍过。

### 代码

```cpp
class Solution {
public:
    bool valid(vector<string> a,int x,int y){
        int i,n=a.size();
        for(i=0;i<n;i++){
            if(a[x][i]=='Q'||a[i][y]=='Q')return false;
            if(y-x+i>=0&&y-x+i<n&&a[i][y-x+i]=='Q')return false;
            if(y+x-i>=0&&y+x-i<n&&a[i][y+x-i]=='Q')return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        int i,j,k=0;
        vector<string>s(n);
        vector<int>v(n,-1);
        string a(n,'.');
        vector<vector<string>>ans;
        for(i=0;i<n;i++){
            s[i].resize(n);
            for(j=0;j<n;j++)s[i][j]='.';
        }
        while(k<n){
            for(i=0;i<n;i++){
                if(i>v[k]&&valid(s,k,i)){
                    v[k]=i;s[k][i]='Q';
                    k++;break;
                }
            }
            if(i==n){
                v[k]=-1;k--;
                if(k<0)break;
                s[k]=a;
            }
            if(k==n){
                ans.push_back(s);
                k--;s[k]=a;
            }
        }
        return ans;
    }
};
```