### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
   
public:
    int numWays(int n) {
       

        int array[3]={1,1,2};
        if(n<=2) 
            return array[n];
        int small=1;
        int big=2;
        int numN=0;
        for(int i=3;i<=n;i++)
        {
            numN=(small+big)%1000000007;
            small=big;
            big=numN;

        }
        return numN;
    }
};
```