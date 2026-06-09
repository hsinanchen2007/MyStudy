### 解题思路
f(1)=A1;
f(2)=max(A1,A2)
f(3)=max(f(2),f(1)+A3)
...
f(k)=max(f(k-1),f(k-2)+Ak)  关键就在于找公式

### 代码

```cpp
class Solution {
public:
    int max(int n1,int n2)
    {
        if(n1>n2)
        return n1;
        return n2;

    }
    int rob(vector<int>& nums) {
      int pre1Max=0,pre2Max=0;
      int curMax=0;
      for(int i=0;i<nums.size();i++)
      {
//缩小空间复杂度，只用到三个变量，变量的赋值与对应关系可由 f(k)=max( f(k-1),f(k-2)+Ak )与f(k+1)=max( f(k),f(k-1)+A(k+1) )得到
           curMax=max(pre1Max+nums[i],pre2Max);
          pre1Max=pre2Max;
          pre2Max=curMax;
      }
      return curMax;
    }
};
```