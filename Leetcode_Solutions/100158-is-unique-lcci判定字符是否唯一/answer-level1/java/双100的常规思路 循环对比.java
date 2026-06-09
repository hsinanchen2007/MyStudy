### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        
        char[] astrs=astr.toCharArray();

        for(int i=0;i<astrs.length;i++){
             for(int j=i+1;j<astrs.length;j++){
                   if(astrs[i] == astrs[j]){
                           return false;
                   }
             }
        }
        return true;
    }
}
```

