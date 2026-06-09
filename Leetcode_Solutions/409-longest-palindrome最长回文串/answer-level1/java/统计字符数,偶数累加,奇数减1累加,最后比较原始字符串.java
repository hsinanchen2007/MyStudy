### 解题思路

回文:  

abba  ---  每个字符数全为偶数
abbba, abbcceccbba, aba --- 单独把中间一个字符拿掉, 其余都是偶数个 

1. for循环统计每个字符出现的数量, 放到int[] a数组中
2. for循环遍历字符统计数组a, 值为偶数直接累加, 值为奇数减1再累加
3. 最终累加的结果和s的长度做比较, 小于s的长度, 则说明s中有字符数为奇数的字符, 选一个作为回文中间分隔字符, 所以结果再加1; 否则, s中字符数都为偶数, 直接返回累加结果. 

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int[] a = new int[128];
        for (char c : s.toCharArray()) {
            a[c]++;
        }
        int num = 0;
        for(int v : a) {
            num += (v % 2 == 0) ? v : v-1;
        }
        return num < s.length() ? num + 1 : num;
    }
}
```