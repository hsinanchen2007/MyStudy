    
    class Solution {
        public List<Integer> findSubstring(String s, String[] words) {
            List<Integer> list = new ArrayList<>();
            if(s == null || s.length() == 0 || words == null || words.length == 0) {
                return list;
            }
            HashMap<String, Integer> hs = new HashMap<>();
            for (String string : words) {
                hs.put(string, hs.getOrDefault(string, 0) + 1);
            }
            int len = words[0].length();
            int sublen = words.length * words[0].length();
            for(int i = 0;i < s.length() - sublen + 1;i++) {
                HashMap<String, Integer> temp = new HashMap<>();
                for(int j = i;j < i + sublen;j = j + len) {
                    String subWord = s.substring(j, j + len);  //首先看存在或不存在
                    if(!hs.containsKey(subWord)) {
                        break;
                    }else {
                        temp.put(subWord, temp.getOrDefault(subWord, 0) + 1);
                        if(temp.get(subWord) > hs.get(subWord)) {
                            break;
                        }
                    }
                    if(j == i + sublen - len) {
                        list.add(i);
                    }
                }
            }
            return list;
        }
    }