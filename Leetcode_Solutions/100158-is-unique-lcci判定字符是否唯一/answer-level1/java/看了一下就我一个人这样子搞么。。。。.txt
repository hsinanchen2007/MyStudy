### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        for(int i=0;i<astr.length();i++){
            for(int j=i+1;j<astr.length();j++){
                if (astr.charAt(i) == astr.charAt(j)){
                    return false;
                }
            }
        }
        return true;

    }
}
```