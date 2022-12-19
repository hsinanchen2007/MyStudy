```
// 这一版实现其实是更复杂了点，题目没看全，将题意中：“注意：每次拼写时，chars 中的每个字母都只能用一次。”的“每次拼写时”去掉，下面的题解就满足了
    public static int countCharacters(String[] words, String chars) {
        int[] recordCharCount = new int[26]; // 记录chars数组中出现的字符的次数
        int len = chars.length();
        int wordsLen = words.length;
        if (len < 1 || wordsLen < 1) return 0;
        for (int i = 0; i < len; i++){
            recordCharCount[chars.charAt(i) - 'a'] += 1;
        }

        int result = 0;
        int hasLen = len; // chars还剩余长度
        for (int i = 0; i < wordsLen; i++){
            if (result == len) break; // 如果结果的长度已经是chars的长度了，就没必要遍历后续的数组了,起到优化效果
            if (hasLen < words[i].length()) continue; // 如果当前单词的长度大于剩余chars长度直接跳过，起到优化效果

            // 看当前单词是否可以被拼写
            String curStr = words[i];
            int curStrLen = curStr.length();

            int k = 0;
            for (; k < curStrLen; k++){
                if (recordCharCount[curStr.charAt(k) - 'a'] > 0){ // 如果当前有足够字符，就进行抵消
                    recordCharCount[curStr.charAt(k) - 'a'] -= 1;
                }else{ // 当前有个字符不够，说明这个单词不能被拼写，就将前面减过的加回来
                    k--; // 因为当前所在下标k的字符不符合，并没有进行抵消，所以要从前一个开始
                    while (k >= 0){
                        recordCharCount[curStr.charAt(k--) - 'a'] += 1;
                    }
                    break;
                }
            }

            if (k == curStrLen){ // 经过上面循环自后k的值超过最后一个元素，说明能被拼写
                result += curStrLen; // 更新结果
                hasLen -= curStrLen; // 更新剩余长度
            }
        }

        return result;
    }
```
