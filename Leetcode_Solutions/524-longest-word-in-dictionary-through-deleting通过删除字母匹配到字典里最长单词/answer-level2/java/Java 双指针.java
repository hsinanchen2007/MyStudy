### 解题思路
此题需解决的问题有二：
1. 判断字典中的字符能否通过删除给定字符串的字符来得到；
2. 返回符合条件的最长且字典顺序最小的字符串。

*对于第一个问题：*
我们可以使用两个指针i,j，一个指向给定字符串s，另一个指向字典中的字符串str。如果两个指针指向的字符相同，则同时将指针后移，否则将给定字符串的指针后移。循环结束后，若j到达尾部即可判断可以通过删除某些字符得到字典中的字符串。

*对于第二个问题，若具备以下任一条件则可说明该字符串为新的答案：*
- j>maxLength；当前字典字符串大于先前字符串的长度，因为题目需要我们寻找长度最长的字符串
- j==maxLength&&res.compareTo(str)>0；当前字典字符串等于先前字符串的长度，但字典顺序更小
- maxLength==0；存储第一个答案

### 代码

```java
class Solution {
    public String findLongestWord(String s, List<String> d) {
        int maxLength=0;
        String res="";
        for(String str:d){
            int i=0,j=0;
            while(i<s.length()&&j<str.length()){
                if(s.charAt(i)==str.charAt(j)){
                    i++;j++;
                }else i++;
            }
            //能通过删除某些字符得到
            if(j==str.length()){
                if(j>maxLength||(j==maxLength&&res.compareTo(str)>0)||maxLength==0){
                        maxLength=j;
                        res=str;
                }
            }
        }
        return res;
    }
}
```