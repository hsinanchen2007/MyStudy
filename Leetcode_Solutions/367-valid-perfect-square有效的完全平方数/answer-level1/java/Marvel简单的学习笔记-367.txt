### 解题思路
和69题求x的平方根一样，可用二分法或牛顿迭代法，具体原理不赘述了。最后求得的平方根必须验证后再输出结果，因为求出来的结果的平方可能会小于num。还是要注意溢出的问题。

### 代码

```java
class Solution {
    public boolean isPerfectSquare(int num) {
        if(num<2)   return true;
        int s=num/2;
        while(s>num/s)
        {
            s=(s+num/s)/2;
        }
        return (s*s==num);
    }
}
```
