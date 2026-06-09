    public class U140 {
        public List<String> wordBreak(String s, List<String> wordDict) {
            List<String>[] v = new List[s.length() + 1];
            HashSet<String> set = new HashSet<>(wordDict);
            return recursive(v, 0, s, set);
        }

        public List<String> recursive(List<String>[] v, int start, String s, HashSet<String> wordDict){
            if(v[start] == null) v[start] = new ArrayList<>();
            for (int i = start; i < s.length(); i++) {
                if(v[i+1] != null && v[i+1].isEmpty()) continue;
                String curStr = s.substring(start, i + 1);
                if (wordDict.contains(curStr)) {
                    if(i + 1 != s.length()) {
                        if (v[i + 1] == null)
                            v[i + 1] = recursive(v, i + 1, s, wordDict);
                        for (String temp : v[i + 1]) {
                            v[start].add(curStr + " " + temp);
                        }
                    }
                    else v[start].add(curStr);
                }
            }
            return v[start];
        }
    }