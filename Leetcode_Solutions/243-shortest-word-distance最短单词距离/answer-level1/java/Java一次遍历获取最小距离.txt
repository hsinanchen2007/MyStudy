    public static int shortestDistance(String[] words, String word1, String word2) {

        int i = 0, count1 = -1, count2 = -1, res = words.length;
        while (i < words.length){
            if (word1.equals(words[i])){
                count1 = i;
                // 如果word2已经出现过，则取当前的距离跟res的最小值
                if (count2 > -1){
                    res = Math.min(res, i - count2);
                }

            } else if (word2.equals(words[i])){
                count2 = i;
                // 如果word1已经出现过，则取当前的距离跟res的最小值
                if (count1 > -1){
                    res = Math.min(res, i - count1);
                }
            }
            i++;
        }

        return res;
    }
