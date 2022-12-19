### 解题思路
判断字符串中字母出现的次数

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        if(null == astr)
            return false;
        if(astr.length() == 1)
            return true;
        int[] count = new int[128];
        for(int i=0;i<astr.length();i++){
            if(count[astr.charAt(i)] != 0)
                return false;
            count[astr.charAt(i)]++;
        }
        return true;
    }
}
```