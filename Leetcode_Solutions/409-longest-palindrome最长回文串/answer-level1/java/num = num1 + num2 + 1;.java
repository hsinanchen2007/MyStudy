### 解题思路
最初理解错了，回文串为对称字符串（num）：
1.出现次数为偶数此的字符均可参与构成（num1）；
2.出现次数为奇数次的字符如果长度大于2，则其(i-1)的长度可以参与构成（num2）；
3.如果有奇数次字符存在，则至多可以选取一个字符作为回文串的中心点；
num = num1 + num2 + 1;

大小写字母的ASCII值最大为122，所以可以讲字符串构建在一个总长度为123的int数组中来遍历。
这比用map结构效率提升很多;

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int[] charArray = new int[123];
        for(char c : s.toCharArray()) {
            charArray[c]++;
        }
        int num = 0;
        for(int value : charArray) {
            num += value / 2 * 2;
            if(value % 2 == 1 && num % 2 == 0) {
                num++;
            }
        }
        return num;
    }
}
```