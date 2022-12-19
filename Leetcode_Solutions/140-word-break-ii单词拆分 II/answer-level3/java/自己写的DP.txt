    
    class Solution {
        public List<String> wordBreak(String s, List<String> wordDict) {
            ArrayList<String>[] dp = new ArrayList[s.length()];
            int min = Integer.MAX_VALUE;
            int max = Integer.MIN_VALUE;
            for(String str : wordDict) {
                min = Math.min(min, str.length());
                max = Math.max(max, str.length());
            }
            // DP看看能不能拆成词组
            boolean[] split = new boolean[s.length()];
            for(int i = 0;i < s.length();i++) {
                for(int j = i - min + 1;j >= 0 && j >= i - max + 1;j--) {
                    String temp = s.substring(j, i + 1);
                    if(wordDict.contains(temp)) {
                        if(j == 0) {
                            split[i] = true;
                            break;
                        }
                        split[i] |= split[j - 1];
                    }
                }
            }
            // 不能拆就直接返回空list，如果不先判断一下会超出内存限制
            if(!split[s.length() - 1]) {
                return new ArrayList<>();
            }
            // 同样的思路DP求最后结果
            for(int i = 0;i < s.length();i++) {
                dp[i] = new ArrayList<String>();
                for(int j = i - min + 1;j >= 0 && j >= i - max + 1;j--) {
                    String temp = s.substring(j, i + 1);
                    if(wordDict.contains(temp)) {
                        if(j == 0) {
                            dp[i].add(temp);
                            break;
                        }
                        for(int k = 0;k < dp[j - 1].size();k++) {
                            dp[i].add(dp[j - 1].get(k) + " " + temp);
                        }
                    }
                }
            }
            return dp[s.length() - 1];
        }

    }