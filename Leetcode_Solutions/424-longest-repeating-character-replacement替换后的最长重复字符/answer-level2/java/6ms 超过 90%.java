```
   public int characterReplacement4(String s, int k) {
        int result = 0;
        int maxCount = 0;
        int []count = new int[26];
        for (int right = 0, left = 0; right < s.length(); right++) {
            // 当前窗口内的最多字符的个数
            maxCount = Math.max(maxCount, ++count[s.charAt(right)-'A']);
            // 需要替换的字符个数就是当前窗口的大小减去窗口中数量最多的字符的数量
            while(k + maxCount < right-left+1){
                count[s.charAt(left)-'A']--;
                //缩小窗口
                left++;
            }
            // 当窗口内可替换的字符数小于等于k时，我们需要根据该窗口长度来确定是否更新result
            result = Math.max(result, right-left+1);
        }
        return result;
    }
```

更多参考 https://github.com/wenxueliu/leecode_practice/blob/master/src/main/java/com/wenxueliu/leetcode/LeetCode424.java