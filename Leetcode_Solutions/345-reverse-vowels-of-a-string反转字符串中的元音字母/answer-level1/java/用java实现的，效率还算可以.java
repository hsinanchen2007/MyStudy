 
    public String reverseVowels(String s) {
        if (s.length() == 0) return "";
        StringBuilder res = new StringBuilder(s);
        int i = 0, j = s.length() - 1;
        while (i < j) {
            //先找到能交换的元音字符
            while (!judgeVowel(s.charAt(i)) && i < j) {
                i++;
            }
            while (!judgeVowel(s.charAt(j)) && i < j) {
                j--;
            }
            //交换下标为i和j的两个字符
            res.setCharAt(i, s.charAt(j));
            res.setCharAt(j, s.charAt(i));
            i++;
            j--;
        }
        return res.toString();
    }

    public boolean judgeVowel(char c) {//判断是否是元音字母
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' ||
                c == 'I' || c == 'O' || c == 'U') {
            return true;
        }
        return false;
    }