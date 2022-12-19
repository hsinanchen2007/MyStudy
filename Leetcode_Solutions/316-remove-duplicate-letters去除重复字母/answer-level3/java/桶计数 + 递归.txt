    public String removeDuplicateLetters(String s) {
        if (s == null || s.length() <= 1) return s;

        int[] map = new int[26];
        char[] strArr = s.toCharArray();

        for (char c : strArr) {
            map[c - 'a']++;
        }

        int minPos = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < s.charAt(minPos)) minPos = i; //找到字典序更小的就更新
            //如果都用完了某个字母，则这个就是当前最小的开头
            if (--map[s.charAt(i) - 'a'] == 0) break;
        }

        //递归进行，需要把这个已经列入结果的字母去掉
        return s.charAt(minPos) + removeDuplicateLetters(
                s.substring(minPos+1).replace(
                        "" + s.charAt(minPos),
                        ""
                ));
    }