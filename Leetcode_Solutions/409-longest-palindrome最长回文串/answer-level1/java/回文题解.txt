### 解题思路
最笨的方法：
  先将字符串遍历加如HashMap，key存在则value+1，key不存在则value=0,然后取出value值，看是否是奇偶数，若是偶数则为全部，若是奇数则长度减一，最后再把长度相加

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
         // 是否有单个元素，可以作为中间一个元素
        boolean center = false;
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        int size = 0;
        if (s != null && s != "") {
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                String cs = String.valueOf(c);
                if (map.containsKey(cs)) {
                    Integer value = map.get(cs);
                    map.put(cs, value + 1);
                } else {
                    map.put(cs, 1);
                }
            }

            for (Map.Entry m : map.entrySet()) {
                int value = (Integer) m.getValue();
                if (value % 2 == 0) {
                    size = size + value;
                } else {
                    size = size + value - 1;
                    center = true;
                }
            }
            if (center) {
                return size + 1;
            } else {
                return size;
            }
        }
        return 0;
    }
}
```