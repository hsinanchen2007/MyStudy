### 解题思路


### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        int i = haystack.length();
        int j = needle.length();
        if(j==0){
            return 0;
        }
        if(i==0||i<j){
            return -1;
        }
        for(int k=0;k<i-j+1;k++){
            if(haystack.substring(k,k+j).equals(needle)){
                return k;
            }
        }
        return -1;
    }
}
```