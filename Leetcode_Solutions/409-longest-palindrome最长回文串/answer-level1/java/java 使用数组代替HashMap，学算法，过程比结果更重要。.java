一道比较简单的题。

学算法，过程比结果更重要。

### 代码

```java
    class Solution {
    public int longestPalindrome(String s) {
        if(s.length() == 0){
            return 0;
        }
        int res = 0;
        // 统计每个字母出现的次数
        int[] count = new int[128];
        charCount(count,s);

        // 统计数组中包含的偶数
        // 例如："ccc" c有3个，循环结束后 res = 2
        for(int i : count){
            res += (i / 2) * 2;
        }

        // res == s.length()表示没有个数是奇数的字母，直接返回res；
        // 有个数是奇数的字母，返回res+1,奇数个的字母可以 作为回文串正中间的字母
        return res == s.length() ? res : res + 1;
    }

    public void charCount(int[] count,String s){
        for(int i = 0;i < s.length();i++){
            char c = s.charAt(i);
            count[c]++;
        }
    }
}
```