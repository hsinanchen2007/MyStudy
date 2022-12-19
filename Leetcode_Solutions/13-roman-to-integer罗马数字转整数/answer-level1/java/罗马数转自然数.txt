### 解题思路
从最右边的数字开始，如果左侧的数比右侧中最大的罗马数字大，则累加，否者则减去左侧数。

### 代码

```java
class Solution {
    final static Map<Character, Integer> valueMap = new HashMap<>();
    static {
        valueMap.put('I', 1);
        valueMap.put('V', 5);
        valueMap.put('X', 10);
        valueMap.put('L', 50);
        valueMap.put('C', 100);
        valueMap.put('D', 500);
        valueMap.put('M', 1000);
    }

    public static int romanToInt(String s) {
        int value = 0;
        int temp = 0;
        int maxValue = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            temp = valueMap.get(s.charAt(i));
            if (maxValue <= temp) {
                maxValue = temp;
                value += temp;
            } else {
                value -= temp;
            }
        }
        return value;
    }
}
```