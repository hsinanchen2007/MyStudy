    
    class Solution {
        public boolean isAnagram(String s, String t) {
            if(s.length() != t.length()) {
                return false;
            }
            HashMap<Character, Integer> hm = new HashMap<>();
            for(int i = 0;i < s.length();i++) {
                char c1 = s.charAt(i);
                char c2 = t.charAt(i);
                hm.put(c1, hm.getOrDefault(c1, 0) + 1);
                hm.put(c2, hm.getOrDefault(c2, 0) - 1);
            }
            for(Character key : hm.keySet()) {
                if(hm.get(key) != 0) {
                    return false;
                }
            }
            return true;
        }
    }