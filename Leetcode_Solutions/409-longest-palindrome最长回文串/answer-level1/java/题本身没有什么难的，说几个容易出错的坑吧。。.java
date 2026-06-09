### 解题思路

1. 做过前天那题的同学，很容易想到做一个int[26+26]数组来保存各字母的个数，但A～Z和a～z在ASCII表上是分开的喔，所以存数组的时候也要分开存哦
2. 如果某字母有偶数个，因为偶数有对称性，可以把它全部用来构造回文串；但如果是奇数个的话，并不是完全不可以用来构建，也不是只能选最长的那个，而是只要砍掉1个，剩下的变成偶数就可以全部计入了
3. 但奇数字母里，可以保留1个不砍，把它作为回文串的中心，所以最后还要再加回一个1
4. 但是！如果压根没有奇数的情况，这个1也不能随便加，所以还要分情况讨论


大概就是这些坑容易掉进去。。都躲过了AC应该没啥问题

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int[] c = new int[26+26];
        for(char ss : s.toCharArray()) {
            if(ss >= 'a') {
                c[ss-'a'] += 1;
            } else {
                c[ss-'A'+26] += 1;
            }
        }
        int res = 0;
        int odd = 0;
        for(int cc : c) {
            res += cc;
            if(cc % 2 == 1) {
                odd += 1;
            }
        }
        return odd == 0 ? res : res - odd + 1;
    }
}
```