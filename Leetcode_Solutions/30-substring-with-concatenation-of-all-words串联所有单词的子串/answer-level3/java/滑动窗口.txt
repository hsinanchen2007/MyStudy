### 解题思路
滑动窗口模板

### 代码

```java
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        if (s == null || s.length() ==0 || words.length ==0 || words == null) {
            return res;
        }

        Map<String, Integer> needs = new HashMap<>();
        int oneword = words[0].length();
        int wordnum = words.length;
        for (String word : words) {
            needs.put(word, needs.getOrDefault(word, 0) + 1);
        }

        for (int i=0; i<oneword; i++) {
            int left = i;
            int right = i;
            int match = 0;
            Map<String, Integer> window = new HashMap<>();

            while (right + oneword <= s.length()) {
                String r = s.substring(right, right + oneword);
                if (needs.containsKey(r)) {
                    window.put(r, window.getOrDefault(r, 0) + 1);
                    if (needs.get(r) >= window.get(r)) {
                        match++;
                    }
                }
                right +=oneword;

                while (match == words.length) {  
                    String l = s.substring(left, left + oneword);
                    if (needs.containsKey(l)) {
                        window.put(l, window.getOrDefault(l, 0) - 1);
                        if (needs.get(l) > window.get(l)) {
                            match--;
                        }
                    }
                    //在匹配的基础上，子串字符长度等于right-left时--找到解  
                    if ((right - left) == oneword * wordnum) {
                        res.add(left);
                    }
                    left += oneword;
                }
                
            }
        }
        return res;
    }
}
```