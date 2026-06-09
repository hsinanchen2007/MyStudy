### 解题思路
此处撰写解题思路
这题的关键就是怎么在字符串字典中找到那个对应的字符串。其实很简单。
只要利用两个指针i,j，一个指向s字符串，一个指向sstr字符串，每一次查找过程中,i依次后移，若i,j对应的两个字符相等，则j后移，如果j可以移到sstr.length()，那么说明sstr中对应的字符s中都有，即s中删除一些字符后，可以得到sstr字符串，最后一步就是比较当前的结果字符与找到的sstr字符，按照题目的需求来决定是否改变结果字符，是不是还挺简单的呀。
### 代码

```java
class Solution {
    public String findLongestWord(String s, List<String> d) {
        String str="";
        for(String sstr:d){
            for(int i=0,j=0;i<s.length()&&j<sstr.length();i++){
                if(s.charAt(i)==sstr.charAt(j)) j++;
                if(j==sstr.length()){
                    if(sstr.length()>str.length()||(sstr.length()==str.length()&&str.compareTo(sstr)>0))  str=sstr;
                }
            }
        }
        return str;
        
    }
}
```