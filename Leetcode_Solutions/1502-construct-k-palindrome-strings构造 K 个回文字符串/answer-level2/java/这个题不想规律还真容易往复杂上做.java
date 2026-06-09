    
    class Solution {
        public boolean canConstruct(String s, int k) {
            if(s.length() == k) {
                return true;
            }
            if(s.length() < k) {
                return false;
            }
            int[] hash = new int[26];
            for(int i = 0;i < s.length();i++) {
                hash[s.charAt(i) - 'a']++;
            }
            int odd = 0;
            for(int i = 0;i < 26;i++) {
                if(hash[i] % 2 != 0) {
                    odd++;
                }
            }
            return odd <= k;
        }
    }