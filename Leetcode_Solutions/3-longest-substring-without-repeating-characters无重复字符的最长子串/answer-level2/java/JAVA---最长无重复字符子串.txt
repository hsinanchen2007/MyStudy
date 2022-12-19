滑动窗口 + hashMap
1. hashMap中存储字符所在的位置
2. 当无重复元素时，滑动窗口右指针为当前位置；当出现重复元素时，滑动窗口左指针挪到重复元素的下一个位置；
3. 遍历过程中记录滑动窗口的最大宽度

```
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int res = 0;
        int left = 0, right = 0;
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (map.get(c) == null) {
                map.put(c, i);
                right = i;            
            } else {
                int index = map.get(c);
                // 将index之前的元素移除map
                removeBeforeIndex(map, s, left, index);
                map.put(c, i);
                left = index + 1;
            }
            res = Math.max(right - left + 1, res);
        }
        return res;
    }

    private void removeBeforeIndex(Map<Character, Integer> map, String s, int left, int index) {
        for (int i = left; i <= index; i++) {
            map.remove(s.charAt(i));
        }
    }
```