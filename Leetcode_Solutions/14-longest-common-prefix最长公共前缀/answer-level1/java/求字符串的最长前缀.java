### 解题思路
数组大小为0时，前缀不存在
数组只有一个字符串，前缀为它本身
把第一个设为初始前缀，逐一比较剩余的字符串，找到第一个与第二个的相同前缀
然后讲将这个前缀和剩下的字符串比较

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
          if(strs.length==0){return "";}
          if(strs.length==1){return strs[0];}
          
          String a=strs[0];
          for(int i=0;i<strs.length;i++){
              
              for(j=0;j<a.length()&&j<strs[i].length();j++){
                  if(a.charAt(j)!=strs[i].charAt(j)){
                            a=a.substring(0,j); 
                                break;}
              }
              
          }
         
          return a;

    }
}
```