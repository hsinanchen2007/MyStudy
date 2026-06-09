完全不需要那么复杂的数据结构和算法

执行用时 :101 ms, 在所有 Java 提交中击败了97.51%的用户
内存消耗 :56.7 MB, 在所有 Java 提交中击败了94.62%的用户

    /** Initialize your data structure here. */
    Map<Integer, List<String>> lengthWordsMap;
    Set<String> wordSet;
    public WordDictionary() {
        lengthWordsMap = new HashMap<>();
        wordSet = new HashSet<>();
    }

    /** Adds a word into the data structure. */
    public void addWord(String word) {
        wordSet.add(word);
        int length = word.length();

        List<String> list = lengthWordsMap.get(length);
        if (list == null){
            list = new ArrayList<>();
        }

        list.add(word);

        lengthWordsMap.put(length,list);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        if (word.indexOf(".")==-1) return wordSet.contains(word);
        else{
            List<String> list = lengthWordsMap.get(word.length());

            if (list == null) return false;

            for (String w: list){
                if (match(w,word)) return true;
            }

            return false;
        }
    }

    private boolean match(String w1, String w2) {
        char[] arr1 = w1.toCharArray();
        char[] arr2 = w2.toCharArray();
        int i = 0, j = 0;
        for (; i < w1.length() && j < w2.length(); i++,j++) {
            if (arr1[i] != arr2[j]){
                if (arr1[i] == '.' || arr2[j] == '.'){
                    continue;
                } else{
                    return false;
                }
            }
        }

        return true;
    }