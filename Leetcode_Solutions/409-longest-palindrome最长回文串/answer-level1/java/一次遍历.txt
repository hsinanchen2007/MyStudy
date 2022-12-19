```
    public int longestPalindrome(String s) {
        int[] array = new int[123];
        char[] sChars = s.toCharArray();
        int maxLen = 0, len = sChars.length;
        for(int i = 0; i < len; i++){
            array[sChars[i]]++;
            //字符为偶数个时回文长度加2
            if((array[sChars[i]] & 1) == 0){
                maxLen+=2;
            }
        }
        //如果字符串的长度大于可行的最大长度，表明字符串中有奇数的字符，因此回文的长度应该加1
        return len > maxLen ? maxLen + 1 : maxLen;
    }
```
