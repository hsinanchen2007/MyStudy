### 解题思路
获取开始的下标值与最后获取的下标值是否一致

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        for (int i = 0; i <astr.length() ; i++) {
            int index = astr.indexOf(astr.charAt(i));
            int index2 = astr.lastIndexOf(astr.charAt(i));
            if (index != index2) {
                return false;
            }
        }
        return true;
    }
}
```