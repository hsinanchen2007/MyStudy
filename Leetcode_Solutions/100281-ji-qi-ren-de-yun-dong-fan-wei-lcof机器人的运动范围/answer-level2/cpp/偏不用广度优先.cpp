看题目意思是需要广度优先搜索，但是**正好不存在孤立点**，所以可以用暴力解法，逐个点检验。
这里先大概确定了范围，然后逐个点检验，时间和空间复杂度和广度优先搜索相当。
```
class Solution {
public:
    int movingCount(int m, int n, int k) {
        int k1=k;
        int maxl=min(k,8);
        k-=8;
        while(k>0){
            maxl+=10*(min(k,9));
            k-=9;
        }
        int cnt=0;
        for(int i=0;i<=maxl;++i){
            for(int j=0;j<=maxl-i;++j){
                if(i<m && j<n && sum(i,j)<=k1) ++cnt;
            }
        }
        return cnt;
    }
    int sum(int i,int j){
        int res=0;
        while(i){
            res+=i%10;
            i/=10;
        }
        while(j){
            res+=j%10;
            j/=10;
        }
        return res;
    }
};
```
