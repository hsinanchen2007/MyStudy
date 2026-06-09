### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxProduct(String[] words) {
        int max=0,flag=0;
      for(int i=0;i<words.length-1;i++){
          for(int j=i+1;j<words.length;j++){
             if(isPow(words[i],words[j])){
             max=Math.max(max,words[i].length()*words[j].length());
          }
          }
      }
          return max;
      }
    public boolean isPow(String num,String len){
        for(int i=0;i<num.length();i++){
            if(len.indexOf(""+num.charAt(i))!=-1)
            return false;
        }
        return true;
    }
}
```