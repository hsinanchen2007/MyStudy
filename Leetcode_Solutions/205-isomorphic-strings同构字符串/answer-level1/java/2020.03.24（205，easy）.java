### 解题思路
本题使用**两个数组**解决对应关系问题

- 首先遍历`s`字符串，将第一次访问的元素在两个数组里 +1，达到对应关系

- 如果访问元素个数不相等，则返回`fasle`

### 代码

```java []
class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length() ) {
            return false;
        }
        // 定义两个数组来存放字符
        int[] arrS = new int[128];
        int[] arrT = new int[128];
        for (int i = 0; i < s.length(); i++) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);
            // 如果两个字符串在数组中对应的值不相等
            if (arrS[c1] != arrT[c2]) {
                return false;
            } else {
                // 如果还没有遍历到，则各自 + 1
                if (arrS[c1] == 0) {
                    arrS[c1] = i + 1;
                    arrT[c2] = i + 1;
                }
            }
        }
        return true;
    }
}
```