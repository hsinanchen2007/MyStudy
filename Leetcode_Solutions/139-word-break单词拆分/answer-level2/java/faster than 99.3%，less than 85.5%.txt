    public class U139 {
        public boolean wordBreak(String s, List<String> wordDict) {
            int[] v = new int[s.length()+1];
            return recursive(s, 0, wordDict, v);
        }

        public boolean recursive(String s, int start, List<String> wordDict, int[] v){
            v[start] = 1;
            for(int i = start; i < s.length(); i++){
                if(v[i + 1] == 1) continue;
                if(wordDict.contains(s.substring(start,i+1))){
                    if(i + 1 == s.length() || recursive(s,i+1, wordDict, v))
                        return true;
                }
            }
            return false;
        }
    }