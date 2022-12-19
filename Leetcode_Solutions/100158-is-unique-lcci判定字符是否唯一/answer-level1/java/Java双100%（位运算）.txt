### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        int mark = 0;
        for(int i=0; i<astr.length(); i++){
            int cur = 'a' - astr.charAt(i);
            if((mark & (1<<cur)) != 0){
                return false;
            }
            mark |= (1<<cur);
        }
        return true;
    }
}
```