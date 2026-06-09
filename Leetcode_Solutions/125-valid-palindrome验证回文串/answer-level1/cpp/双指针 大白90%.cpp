 bool isEqual(char cl, char cr) {
        if (cl == cr) return true;
        if ((cl >= 'a' && cl <= 'z')  &&
            (cr >= 'A' && cr <= 'Z') && cr - 'A' == cl - 'a')
            return true;
        if ((cl >= 'A' && cl <= 'Z')  &&
            (cr >= 'a' && cr <= 'z') && cr - 'a' == cl - 'A')
            return true;
        return false;
    }
    bool isNormal(char c) {
        return ((c >= 'a' && c <= 'z') ||
             (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'));
    }
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int left = 0, right = s.length() - 1;
        while (left < right) {
            while (left < right && !isNormal(s[left])) left++;
            while (left < right && !isNormal(s[right])) right--;
            if (left < right && isEqual(s[left], s[right])) {
                left++;
                right--;
            } else {
                break;
            }
        }
        
        return left >= right;
    }