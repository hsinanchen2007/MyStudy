### 解题思路

数组替代Set，没有用的额外的数据结构。这里仅考虑了ASCII码，若考虑其他字符，可设为Unicode码长度65536

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        int[] charArr = new int[128];
        int c = 0;
        for(int i=0; i<astr.length(); i++){
            c = astr.charAt(i);
            if(charArr[c]>0) return false;
            charArr[c]++;
        }
        return true;
    }
}
```