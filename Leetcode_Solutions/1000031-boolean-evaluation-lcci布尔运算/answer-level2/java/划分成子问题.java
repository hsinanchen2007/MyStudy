```java
class Solution {
    private HashMap<List, Integer> map = new HashMap<>();

    public int countEval(String s, int result) {
        int len = s.length();
        if (len == 1) return result == Integer.parseInt(s) ? 1 : 0;
        int res = 0;
        for (int i = 0; i < len; ++i) {
            //遇到'0'或'1'，跳过
            if (s.charAt(i) == '0' || s.charAt(i) == '1') continue;
            //分割成左半部分 和 右半部分
            String left = s.substring(0, i), right = s.substring(i + 1);
            if (!map.containsKey(Arrays.asList(left, 0))) map.put(Arrays.asList(left, 0), countEval(left, 0));
            if (!map.containsKey(Arrays.asList(left, 1))) map.put(Arrays.asList(left, 1), countEval(left, 1));
            if (!map.containsKey(Arrays.asList(right, 0))) map.put(Arrays.asList(right, 0), countEval(right, 0));
            if (!map.containsKey(Arrays.asList(right, 1))) map.put(Arrays.asList(right, 1), countEval(right, 1));

            int left0 = map.get(Arrays.asList(left, 0)), left1 = map.get(Arrays.asList(left, 1));
            int right0 = map.get(Arrays.asList(right, 0)), right1 = map.get(Arrays.asList(right, 1));
            switch (s.charAt(i)) {
                case '&':
                    res += result == 0 ? left0 * right0 + left0 * right1 + left1 * right0 : left1 * right1;
                    break;
                case '|':
                    res += result == 0 ? left0 * right0 : left1 * right0 + left0 * right1 + left1 * right1;
                    break;
                default:
                    res += result == 0 ? left0 * right0 + left1 * right1 : left0 * right1 + left1 * right0;
            }
        }
        return res;
    }
}
```
