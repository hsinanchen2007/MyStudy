### 解题思路
时间复杂度为O(N)

### 代码

```java
class Solution {
    public int climbStairs(int n) {
    //理清思路，就是斐波那契数列
    int i1=1,i2=2,temp=0;
    for(int i=3;i<=n;i++)
    {
        temp=i1+i2;
        i1=i2;
        i2=temp;
    }
    if(n==1)
       return 1;
    if(n==2)
       return 2;
    return temp;
    }
}
```