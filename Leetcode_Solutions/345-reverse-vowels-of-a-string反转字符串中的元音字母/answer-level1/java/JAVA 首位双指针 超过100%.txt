    public String reverseVowels(String s) {
        int left = 0;
        int right = s.length() -1;
        char[] strToChar = s.toCharArray();
        while (left < right) {
            while (left < right && !isVowel(strToChar[left])) left++;
            while (left < right && !isVowel(strToChar[right])) right--;
            strToChar = swap(strToChar, left, right);
            left++;
            right--;
        }
        return String.valueOf(strToChar);
    }

    private boolean isVowel(char c) {
        char lowerC = Character.toLowerCase(c);
        return lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u';
    }

    private char[] swap(char[] strToChar, int left, int right) {
        char temp = strToChar[left];
        strToChar[left] = strToChar[right];
        strToChar[right] = temp;
        return strToChar;
    }

**注意char[]和String之间的转换很耗时，尽量减少**