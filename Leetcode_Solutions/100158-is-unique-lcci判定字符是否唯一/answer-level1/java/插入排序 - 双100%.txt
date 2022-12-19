### 解题思路

插入排序，比较条件中加入相等的比较

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        if (astr == null || "".equals(astr) || astr.length() == 1) {
            return true;
        }
        char[] cs = astr.toCharArray();
        for (int j = 1, len = cs.length; j < len; j++) {
            int i;
            char jc = cs[j]; 
            for (i = j-1; i >= 0; i--) {
                if (jc == cs[i]) {
                    return false;
                } else if (jc > cs[i]) {
                    break;
                } else {
                    cs[i+1] = cs[i];
                }
            }
            cs[i+1] = jc;
        }
        return true;
    }
}
```