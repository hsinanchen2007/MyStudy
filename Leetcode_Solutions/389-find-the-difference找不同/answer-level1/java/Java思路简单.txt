### 解题思路
这一题我的做法是先设置两个数组存放每个s和t中字母的频率。然后进行比较。其中如果比到最后发现这个字母还是没有找到（只能意味着这个多出来的字母是S中不存在的并且必定位于t的最后一位）。

### 代码

```java
class Solution {
    public char findTheDifference(String s, String t) {
        char[] sc=s.toCharArray();
        char[] cc=t.toCharArray();
        int[] num=new int[26];
        int[] num1=new int[26];
        for(int i=0;i<s.length();i++){
            num[sc[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            num1[cc[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
           if(num1[cc[i]-'a']!=num[cc[i]-'a']){
               return cc[i];
           }
        }
        return cc[t.length()-1];
    }
}
```