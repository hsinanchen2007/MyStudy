### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        // return new StringBuilder(s.substring(n,s.length())).append(s.substring(0,n)).toString();
        char[] sCharArray = s.toCharArray();
        String left = "";
        String right = "";
        for(int i = 0;i < sCharArray.length;i++){
            if(i<n){
                left +=String.valueOf(sCharArray[i]);
            }else{
                right +=String.valueOf(sCharArray[i]);
            }
        }
        return right + left;
    }
}
```