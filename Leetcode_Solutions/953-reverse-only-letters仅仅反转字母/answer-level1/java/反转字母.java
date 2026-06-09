### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseOnlyLetters(String S) {
        String sum="",num="";
      for(int i=S.length()-1;i>=0;i--)
       if(S.charAt(i)>='a'&&S.charAt(i)<='z'||S.charAt(i)>='A'&&S.charAt(i)<='Z')
      num+=S.charAt(i);
      int i=0,j=0;
      while(i<num.length()||j<S.length()){
        if(S.charAt(j)>='a'&&S.charAt(j)<='z'||S.charAt(j)>='A'&&S.charAt(j)<='Z'){
            sum+=num.charAt(i);
            i++;
            j++;
        }
        else{
            sum+=S.charAt(j);
            j++;
        }
      }
    return sum;
    }
}
```