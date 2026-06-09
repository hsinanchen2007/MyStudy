### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        for(int i=0;i<astr.length();i++){
            if(astr.indexOf(astr.charAt(i))!=i){
                return false;
            }
        }
        return true;
    }
}
```