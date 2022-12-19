 public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        int begin = 0;
        int end = s.length() - 1;
        int num = 0;
        while (begin < end) {
            num = s.charAt(begin);
            if (!((48 <= num && num <= 57) || (97 <= num && num <= 122))) {
                begin++;
                continue;
            }
            num = s.charAt(end);
            if (!((122 >= num && num >= 97) || (57 >= num && num >= 48))) {
                end--;
                continue;
            }
            if (s.charAt(begin) != s.charAt(end)) {
                return false;
            }
            begin++;
            end--;

        }
        return true;
    }