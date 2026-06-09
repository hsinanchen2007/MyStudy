### 解题思路
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
36.3 MB
, 在所有 Java 提交中击败了
100.00%
的用户

第一次这么效果这么好，但是不知道思路有没有问题，我就是想的把一个数拆分成尽可能多的2和3，其他没了，特殊情况，如2和3 单独判断了一下

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        int result = 1;
        while(n>0 && (n!=4 && n!=2)){
            result*=3;
            n=n-3;
        }
        if(n!=0)
            result*=n;
        return result;

    }
}
```