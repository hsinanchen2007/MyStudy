使用快慢指针，检查字符串是否包含重复字符
     若包含重复字符，则慢指针 + 1
     若不包含，则快指针 + 1,计算上一次最大值和目前字符串的大小
```  
  public int lengthOfLongestSubstring(String s) {
        int slow = 0;
        int fast = 1;
        int maxLength = 0;

        while (slow < fast && fast <= s.length()) {
            String tmp = s.substring(slow, fast);
            if (!this.doubleString(tmp)) {
                if (maxLength < tmp.length()) {
                    maxLength = tmp.length();
                }
                fast++;
            } else {
                slow++;
            }
        }
        return maxLength;
    }

    public boolean doubleString(String str) {
        Set<Character> characterSet = new HashSet<>();
        int length = str.length();
        if (length == 1) {
            return false;
        }
        for (int i = 0; i < length; i++) {
            if (characterSet.contains(str.charAt(i))) {
                return true;
            } else {
                characterSet.add(str.charAt(i));
            }
        }
        return false;
    }
```