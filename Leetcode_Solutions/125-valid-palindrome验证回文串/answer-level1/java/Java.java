public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        char[] c = s.toCharArray();
        int start = 0;
        int end = s.length() - 1;
        while (start < end) {
            if (!Character.isLetterOrDigit(c[start])) {
                start++;
            } else if (!Character.isLetterOrDigit(c[end])) {
                end--;
            } else if (c[start++] != c[end--]) {
                return false;
            }
        }
        return true;
}