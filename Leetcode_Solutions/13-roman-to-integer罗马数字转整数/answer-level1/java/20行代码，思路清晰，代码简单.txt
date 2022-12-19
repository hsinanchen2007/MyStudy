#### 核心思想：使用map + 双指针
- 一个指针记录当前字符代表的值
- 另一个指针记录上一个字符代表的值
- 在累加过程中如果发现当前字符的值比上一个小了，那就说明发生了CM, CD, XL, XC之类的情况。<br>于是减去上个字符的值即可 `注意要减去两次`
  - 减去两次的原因：本来在上一个字符就该执行减法操作，但是却执行了加法操作，所以就和实际情况相差了2倍
```
class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> map = new HashMap<>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);
        int result = 0;
        char[] chars = s.toCharArray();
        int pre = 1000;
        for (char c : chars) {
            Integer current = map.get(c);
            result += current;
            if (current > pre) {
                result = result - (2 * pre);
            }
            pre = current;
        }
        return result;
    }
}
```