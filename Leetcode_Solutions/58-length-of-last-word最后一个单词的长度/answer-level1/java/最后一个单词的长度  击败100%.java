### 解题思路
思路：
获得字符串的长度，从字符串的最后一位字符向前遍历，记录遍历长度，直到遇到空格或者字符串遍历完毕。
特殊情况：字符串的最后一位是空格，这时需要从倒数第二位开始计算单词长度。

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        int ans = 0;
        for(int i=s.length()-1;i>=0;i--){
            if(s.charAt(i)==' '){
                if(ans != 0){
                    return ans;
                }
            }else{
                ans = ans + 1;
            }
        }
        return ans;
    }
}
```