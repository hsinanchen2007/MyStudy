递归：

```
class Solution {
    public int fib(int N) {
        if (N == 0 || N == 1) return N;
        return fib(N - 1) + fib (N - 2);
    }
}
```

不用递归一个个算：

```
class Solution {
    public int fib(int N) {
        if (N == 0 || N == 1) return N;
        int pre = 1;
        int prepre = 0;
        for (int i = 2;i <= N; i++) {
            int newpre = pre + prepre;
            prepre = pre;
            pre = newpre;
        }
        return pre;
    }
}
```

一个个算的时间复杂度是O(N)，递归虽然看着代码少，但是时间复杂度是O(2^N)，还不容易理解，反倒是不用递归既容易理解，又比较高效。
有数学方法可以直接计算时间复杂度为O(1)，不过我数学比较差并不知道，可以看其他人的题解。
至于打表，太过于牛逼了，也不提了。