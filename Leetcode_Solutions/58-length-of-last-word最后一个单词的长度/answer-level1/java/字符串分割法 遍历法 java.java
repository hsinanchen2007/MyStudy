### 解题思路
方法一：字符串分割法，利用split对" "进行分割
判断分割后数组的长度，若为0说明字符串内都为空格，返回0
若不为0则返回分割后最后字符串（单词）的长度

方法二：遍历，暴力破解，若字符为' '将计数count变为0，不为空count++
由于可能存在多个空格，临时变量t=count
最后返回的t即为长度（字符数）

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        String[] a=s.split(" ");
        if(a.length==0)
            return 0;
        return a[a.length-1].length();
    }
}
```
```java
class Solution {
    public int lengthOfLastWord(String s) {
        int count=0,t=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!=' '){
                count++;
                t=count;
            }else{
                count=0;
            }
        }
        return t;

    }
}
```