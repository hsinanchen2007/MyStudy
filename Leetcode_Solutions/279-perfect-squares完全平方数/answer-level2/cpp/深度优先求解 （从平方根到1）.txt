**明显从平方根到1**
大的数用的越多，最后总的个数可能更少
从q--->1有明显的选择问题
选择深度优先遍历为佳
及时减枝，当前的个数大于 先前存储的立刻剪枝
i>remain/i立刻跳过 而非break因为是从大到小的顺序
```
class Solution {
public:
    int numSquares(int n) {
        if(n<=0) return 0;
        int q=sqrt(n);
        int cnt=INT_MAX;
        dfs(n,cnt,0,q);
        return cnt;
    }
 private:
    void dfs(int remain, int& cnt, int result, int start)
    {
        if(remain==0)
        {
           cnt=min(cnt,result);
           return ; 
        }
        for(int i=start;i>=1;i--)
        {
            if(i>(remain/i))
                continue ;
            result++;
            if(result>cnt)
                return ;
            dfs(remain-i*i,cnt,result,i); //
            result--;
        }
    }
};
```
