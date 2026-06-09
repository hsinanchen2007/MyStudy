### 解题思路
数学方法: 对于第j个灯泡，它会被操作多少次呢？这个要看j的因数的个数了，而判断灯泡是否亮着就是判断j的因数个数是否是奇数，可得，只有完全平方数的因数才会是奇数个，因此只需要去判断1~n有几个完全平方数，so easy！

### 代码

```java
class Solution {
    public int bulbSwitch(int n) {
        int num = 1;
        while (num*num <= n){
            num++;
        }
        return num - 1;
    }
}
```