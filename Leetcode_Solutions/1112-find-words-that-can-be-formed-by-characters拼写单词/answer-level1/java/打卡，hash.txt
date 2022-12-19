    
    class Solution {
        public int countCharacters(String[] words, String chars) {
            int res = 0;
            int[] hash = new int[26];
            for(int i = 0;i < chars.length();i++) {
                hash[chars.charAt(i) - 'a']++;
            }
            outer: for(int i = 0;i < words.length;i++) {
                int[] temp = Arrays.copyOf(hash, 26);
                for(int j = 0;j < words[i].length();j++) {
                    if(temp[words[i].charAt(j) - 'a'] == 0) {
                        continue outer;
                    }
                    temp[words[i].charAt(j) - 'a']--;
                }
                res += words[i].length();
            }
            return res;
        }
    }