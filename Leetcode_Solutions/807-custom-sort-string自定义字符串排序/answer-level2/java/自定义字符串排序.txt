### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String customSortString(String S, String T) {
        String sum="";
        int []num=new int[26];
        for(int j=0;j<T.length();j++){
             num[T.charAt(j)-'a']++;
        }
        for(int i=0;i<S.length();i++){
            while(num[S.charAt(i)-'a']>0){
            sum+=S.charAt(i);
            num[S.charAt(i)-'a']--;
            }
        }
        for(int i=0;i<T.length();i++){
            while(num[T.charAt(i)-'a']>0){
            sum+=T.charAt(i);
            num[T.charAt(i)-'a']--;
        }
        }
        return sum;
    }
}
```