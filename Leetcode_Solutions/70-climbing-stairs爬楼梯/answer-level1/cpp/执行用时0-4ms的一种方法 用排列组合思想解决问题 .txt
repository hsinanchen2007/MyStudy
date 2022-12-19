解题思路：
  假如有n阶台阶需要你进行攀爬，每次有且仅能爬1或2个台阶，求有多少种方法。
  这个题目可以认为是在p次执行步骤里，有k次选择爬2个台阶，然后求有多少种组合方式，是一个排列组合问题。
  因此我们需要先确定执行步骤的上下限，即p的最大值和最小值，以及两种最值情况下，1和2的数量。
  然后我们发现，每当选择爬2个台阶的步骤被替换为爬1个台阶后，p值会发生变化，即
          k--,p++;
  然后依托排列组合公式，得出每一个p值情况下，k次选择爬2个台阶的组合方式的数目，接着对所有的组合数目求和即可。

class Solution {
public:
    
    int Count(int p,int t)//排列组合函数
    {
       long long r=1;
      int z,i=1,b;
      if(t==0) return 1;
      else
      {
        if(t<=p/2)
        {
          z=t;
        }
        else{
          z=p-t;
        }
        b=z;
         while(z>0)
      {
        
        if(i<=b)
        {
          r=r*p/i;
         p--;   
         z--;
          i++;
        }
           else
           {
             r=r*p;
         p--;   
         z--;
           }
      }      
      }    
      return r;
    }


    int climbStairs(int n) {
      int i,j,k;
      i=n;//求p上限
      j=n%2;
      k=(n-j)/2;
      int p,r;
      r=0;
      p=k+j;//p下限
      while(p<=i)
      {
        r=r+Count(p,k);
        k--;
        p++;
      }
      
      return r;
        
    }
};