### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int ans=0,used[101][101];
    int dicx[4]={-1,0,0,1},dicy[4]={0,1,-1,0};
    int sum(int n){
        int k=0;
        while(n){
            k+=n%10;
            n/=10;
        }
        return k;
    }
    void func(int i,int j,int m,int n,int k){
        if(i<0||j<0||i>=m||j>=n||used[i][j]||sum(i)+sum(j)>k)return;
        used[i][j]=1;
        ans++;
        for(int t=0;t<4;t++)func(i+dicx[t],j+dicy[t],m,n,k);
    }
    int movingCount(int m, int n, int k) {
       func(0,0,m,n,k);
       return ans;
    }
};
```