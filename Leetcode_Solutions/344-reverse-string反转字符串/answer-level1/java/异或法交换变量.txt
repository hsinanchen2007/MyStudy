只借助数组角标变量，不借助任何其他变量完成交换

```
class Solution {
    public void reverseString(char[] s) {
        if (s == null || s.length <= 1) {
            return;
        }
        for (int i = 0; i < s.length / 2; i++) {
            s[i] = (char) (s[i] ^ s[s.length - 1 - i]);
            s[s.length-1-i] = (char) (s[i] ^ s[s.length - 1 - i]);
            s[i] = (char) (s[i] ^ s[s.length - 1 - i]);
        }
    }
}
```

			执行耗时:1 ms,击败了100.00% 的Java用户
			内存消耗:43.9 MB,击败了100.00% 的Java用户
			
