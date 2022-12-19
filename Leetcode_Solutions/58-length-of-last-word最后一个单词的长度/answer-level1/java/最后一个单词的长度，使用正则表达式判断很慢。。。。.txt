### 解题思路

### 代码

```java
/*方法1
从最后一个不为空格得字母开始计数
*/
class Solution {
    public int lengthOfLastWord(String s) {
        int len = s.length();
        //如果为空串"",返回0；
        if(len == 0){return 0;}
        int i = len - 1;
        //空格" "长度为1；必须先判断i>=0？
        while(i >= 0 && s.charAt(i) == ' '){
            i --;
        }
        int cnt = 0;
        while(i != -1 && s.charAt(i) != ' '){
            cnt ++;
            i --;
        }
        return cnt;
    }
}

/*方法2
利用正则表达式：\s表示空格
把s按照空格（+表示至少一个）分开，存入字符串数组words,位于开头的空格会存入数组（实验证明）
如果s中全部是空格，则words为一个空格，空格长度为0；
如果s为空串“”，words中为一个空串，words长度为1，其字符串长度为0
返回words数组最后一个单词的长度。
*/
class Solution {
    public int lengthOfLastWord(String s) {
        String[] words = s.split("[\\s]+");
        for(String str : words){
            System.out.println(str.length());
        }
        int len = words.length;
        System.out.println(len);
        if(len == 0){return 0;}
        return words[len-1].length();
    }
}
```