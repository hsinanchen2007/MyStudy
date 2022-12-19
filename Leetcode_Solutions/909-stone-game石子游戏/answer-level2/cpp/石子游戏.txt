### 解题思路
首先考虑递归解法，如注释部分。
对于偶数堆石子，第一个人可以获得石子的最大数量 = 当前石子总数 - min(去掉第一堆石子后第二个人可以获得石子的最大数量，去掉最后一堆石子后第二个人可以获得石子的最大数量）。（1）
对于奇数堆石子，第二个人可以获得石子的最大数量 = 当前石子总数 - min(去掉第一堆石子后第一个人可以获得石子的最大数量，去掉最后一堆石子后第二个人可以获得石子的最大数量）。（2）

可以看到递归解法需要计算大量重复子表达式，因此考虑动态规划。
（2）式代入（1）式可以得到递推式。逐步增加石子堆数（偶数堆），依次计算所需变量值，则可以得到面对全部石子堆时第一个人可以得到的最大石子数。

### 代码

```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = accumulate(piles.begin(),piles.end(),0);
        
        vector<vector<int>> mat(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                mat[i][j]=accumulate(piles.begin()+i,piles.begin()+j+1,0);
            }
        }
        
        vector<vector<int>> stone1(n,vector<int>(n,0));
        for(int l=0;l<=(n-2);l++){
            
            stone1[l][l+1]=max(piles[l],piles[l+1]);
        }
        
        for(int k=3;k<=n;k = k+2 ){
            for(int i=0;i+k<n;i++){
                int l=i;
                int r=i+k;
                int left = mat[l+1][r] - min(stone1[l+2][r],stone1[l+1][r-1]);
                int right = mat[l][r-1] - min(stone1[l+1][r-1],stone1[l][r-2]);
                stone1[l][r] = mat[l][r] - min(left,right);
            }
        }
        return stone1[0][n-1]>((sum-1)/2);
        /*
        int a = stone1(piles,0,piles.size()-1,mat);
         return a>((sum-1)/2);*/
    }
    /*
    int stone1(vector<int> piles,int leftIndex, int rightIndex,vector<vector<int>> mat) {
        if((rightIndex -leftIndex) == 1)
            return max(piles[leftIndex],piles[rightIndex]);
        int left = stone2(piles,leftIndex+1,rightIndex,mat);
        int right = stone2(piles,leftIndex,rightIndex-1,mat);
        return mat[leftIndex][rightIndex]-min(left,right);
    }
    int stone2(vector<int> piles,int leftIndex, int rightIndex,vector<vector<int>> mat) {
        if((rightIndex - leftIndex) ==0)
         return piles[rightIndex];
        int left = stone1(piles,leftIndex+1,rightIndex,mat);
        int right =  stone1(piles,leftIndex,rightIndex-1,mat);
        return mat[leftIndex][rightIndex] - min(left,right);
    }*/
};
```