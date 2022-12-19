### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        int index =0;       //t的索引，每次比较后加1
        int count =0;       //计算s的每个字符是否与当前t的字符相等，是加1.否不变，最后与s的长度比较
        int indexS = 0;     //s的索引，每一个字符与t当前索引往后的比较，相等加1到下一个
       
            while(index<t.length()){
                if(indexS>=s.length()) break;   //如果s的索引走到最后，结束循环。
                char temp = s.charAt(indexS)；  //s当前的字符
                if(temp == t.charAt(index)){    //与当前t的字符相等
                    count++;                             
                    index++;                    //下一个t的字符
                    indexS++;                   //下一个s的字符
                    continue;                   //下一次循环
                }else{
                    index++;                    //当前t的字符与s当前字符不等，准备t的下一个
                }
            }
        

        if(count==s.length()){
            return true;    
        }else return false;
    }
}
```