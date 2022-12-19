```
 class Solution {
        public List<Integer> findAnagrams(String s, String p) {
            List<Integer> res = new ArrayList<>();

            if (s.length() < p.length() || p.length() < 1) return res;

            int[] slide = new int[26];
            int[] target = new int[26];
            for (Character c : p.toCharArray()) {
                target[c - 'a'] += 1;
            }
            //slide window
            int l = 0, r = -1;
            while (r + 1 < s.length()) {
                slide[s.charAt(++r) - 'a'] += 1;
                if (r - l + 1 > p.length()) {
                    slide[s.charAt(l++) - 'a'] -= 1;
                }
                if (r - l + 1 == p.length() && equals(slide, target)) {
                    res.add(l);
                }
            }
            return res;
        }

        private boolean equals(int[] slide, int[] target) {
            for (int i = 0; i < 26; i++) {
                if (slide[i] != target[i]) {
                    return false;
                }
            }
            return true;
        }
    }
```
