```java
     class Solution {
        private int res = 0;
        private HashMap<Character, Character> map = new HashMap<>(){{
            put('0','0');
            put('1','1');
            put('6','9');
            put('8','8');
            put('9','6');
        }};
        public int strobogrammaticInRange(String low, String high) {
            if (low == null || high == null || low.length() > high.length()) return 0;
            int low_len = low.length(), high_len = high.length();
            for (int i = low_len; i <= high_len; i++) {
                dfs(low, high, 0, i-1, new char[i]);
            }
            return res;
        }
        public void dfs(String low, String high, int left, int right, char[] cs) {
            if (left > right) {
                String now = String.valueOf(cs);
                if (cs.length == low.length()) {
                    if (now.compareTo(low) >= 0) {
                        if (cs.length == high.length()) {
                            if (now.compareTo(high) <= 0) res++;
                        }else {
                            res++;
                        }
                    }
                }else if (cs.length == high.length()) {
                    if (now.compareTo(high) <= 0 && cs[0]!='0') {
                        res++;
                    }
                }else {
                     if (cs[0]!='0') res++;
                }
            }else {
                if (right == left) {
                    cs[left] = '0';
                    dfs(low, high, left+1, right-1, cs);
                    cs[left] = '1';
                    dfs(low, high, left+1, right-1, cs);
                    cs[left] = '8';
                    dfs(low, high, left+1, right-1, cs);
                }else {
                    for (Map.Entry<Character,Character> entry : map.entrySet()) {
                        cs[left] = entry.getKey();
                        cs[right] = entry.getValue();
                        dfs(low, high, left+1, right-1, cs);
                    }
                }
            }
        }
    }
```

主要多了比大小的操作。
