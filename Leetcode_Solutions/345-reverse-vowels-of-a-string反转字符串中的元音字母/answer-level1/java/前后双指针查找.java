### 解题思路
使用双指针解题方法
指针i从字符串左边开始遍历，指针j从右边开始遍历，直到i<j条件不成立时结束遍历
遍历过程中，遇到原因字符，则前后对换位置

### 代码

```java
class Solution {
     public String reverseVowels(String s) {
        if(s == null || "".equals(s)){
            return "";
        }
        char[] chars = s.toCharArray();
        int i = 0,j = chars.length-1;
        while (i < j){
            boolean iflag = isVowel(chars[i]);
            boolean jflag = isVowel(chars[j]);

            if(iflag && jflag){
                change(chars,i,j);
                i++;
                j--;
            }
            if(!iflag){
                i++;
            }
            if(!jflag){
                j--;
            }
        }
        return String.valueOf(chars);
    }

    private void change(char[] chars,int i,int j){
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }

    /**
     * 判断是否为元音字符
     * @param s
     * @return
     */
    private boolean isVowel(char s){
        if('a'== s || 'e'== s || 'i' == s || 'o' == s || 'u' == s
            || 'A' == s || 'E' == s || 'I' == s || 'O' == s || 'U' == s){
            return true;
        }
        return false;
    }
}
```