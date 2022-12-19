### 解题思路
既然26位存不下，那索性直接存256位好了。
思路就是，遇到偶数的就直接加上，遇到奇数的就把奇数-奇数对2取余，即如果是3，那就取2.如果是1，那就取0.
最后判断一下，ans与s的长度关系，如果小于的话，那就加1，为什么因为回文中间的那个字符可以是单个的啊。否则那就直接输出ans咯。

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        if(s.length()==0) {
            return 0;
        }
        int[] table = new int[256];
        int ans = 0;
        for(char c:s.toCharArray()) {
            table[c] += 1;
        } 
        for(int i=0; i<256; i++) {
            if(table[i]%2==0) {
                ans += table[i];
            }else {
                ans += table[i]-table[i]%2;
            }
        }
        return ans<s.length()?ans+1:ans;
    }
}
```