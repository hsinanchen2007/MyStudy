`    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return "";
        }
        // 当前的最大长度;
        int MaxLen = Integer.MIN_VALUE;
        // 对应的left;
        int LEFT = 0;
        // 对应的right;
        int RIGHT = 0;
        // 回文串共有2n-1个可能的回文中心,从每个回文中心开始进行扩展
        int N = s.length();
        for (int center = 0; center <= 2 * N - 2; center++) {
            int left = center / 2;
            int right = left + center % 2;
            while (left >= 0 && right < N && s.charAt(left) == s.charAt(right)) {
                left--;
                right++;
            }
            // 记录当前最left, 当前最right;
            if (right - left > MaxLen) {
                MaxLen = right - left;
                LEFT = left;
                RIGHT = right;
            }
        }
        return s.substring(LEFT + 1, RIGHT);
    }`