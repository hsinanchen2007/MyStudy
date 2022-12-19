### 解题思路
hashMap 有hash运算
switch 本质是对case排序，二分查找 ologn，少的时候 on
数组下标 o1

### 代码

```java
class Solution {
    private final static int[] mapping = new int['Y'];
    static {
        mapping['I'] = 1;
        mapping['V'] = 5;
        mapping['X'] = 10;
        mapping['L'] = 50;
        mapping['C'] = 100;
        mapping['D'] = 500;
        mapping['M'] = 1000;
    }

    public int romanToInt(String s) {

        char[] cs = s.toCharArray();
        int sum = 0;
        int before = Integer.MAX_VALUE;
        for (char c : cs) {
            int cur = mapping[c];
            sum += cur;
            if (cur > before) {
                sum -= before << 1;
            }
            before = cur;
        }
        return sum;
    }
}
```