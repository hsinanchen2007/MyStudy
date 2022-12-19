### 解题思路
先处理一些特殊情况，如字符串数组为空或只有一个元素，或者存在空字符串。其它的情况我们只需要对第一个字符串，找到其特定索引上的字符，并判断其它字符串同位置是否与其相同即可。如果全部相同，那么我们把这个字符拼接到目标字符串上，并将索引后移，直到索引与某个字符串长度相同，或者某个位置上出现了与第一个字符串不同的字符。
### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
          int len = strs.length;
          if(len==0){
              return "";
          } 
          if (len==1 || strs[0].equals("")){
              return strs[0];
          }
         //为每个字符串建立逐位的索引
          int j=0;
         //用来拼接字符串
          StringBuilder str = new StringBuilder();
          char s = 'a';
          while(j<strs[0].length()){
            s = strs[0].charAt(j);
            for (int i = 1;i<len;i++){
            //索引已经超过了某个字符串的长度，直接返回
              if (strs[i].length()==j){
                  return str.toString();
              }
            //某个索引
              if(strs[i].charAt(j)!=s){
                  return str.toString();
              }
            }
            str.append(s);
            j++;          
          }         
          return str.toString(); 
    }
}
```