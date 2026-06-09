### 解题思路
此处撰写解题思路
整数翻转的算法比较常见，重要的是处理好溢出的情况。刚开始看题的时候没注意最下面的防溢出要求，导致没跑过。
实际上这个提主要的知识点是int有符号数的范围0x80000000 -- 0x7fffffff
### 代码

```java
class Solution {
    public int reverse(int x) {
        int max = 0x7fffffff, min = 0x80000000;
        int t = x;
        long res = 0L;
        while (t!=0){
            res = res*10 + t%10;
            t/=10;
        }
        return (int)(res>0x7fffffff||res<0x80000000 ? 0:res);
    }
}
```