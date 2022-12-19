首先有两种特殊情况，一种是板子数为0，一种是板子的最长和最短一致。然后其他情况就是运用一个数组（很显然数组大小总是为板子总数加一）保存板子的最大长度（即长板子数为板子总数时）在数组末尾，然后从最后开始往前走，每走一步就用后一个（数组中的下标加一）的板子总长度减去一个长的板子，加上一个短的板子，直到长板子数为0即可。
![QQ图片20200227183015.png](https://pic.leetcode-cn.com/792febf446ddacd94590f2e98c622681c3e4c2fdd0ea5f1ac0fcdc063ec58f05-QQ%E5%9B%BE%E7%89%8720200227183015.png)
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
           if(k==0)
           {
               vector<int>dp(k,0);
                return dp;
           }
            if(shorter==longer)
          {   
              vector<int>dp(1,k*shorter);
             return  dp;
          } 
          vector<int>dp(k+1,0);
          dp[0]=k*shorter;
          dp[k]=k*longer;
            for(int i=k-1;i>0;--i)
            {
                dp[i]=dp[i+1]-longer+shorter;
            }
            return dp;
    }
};