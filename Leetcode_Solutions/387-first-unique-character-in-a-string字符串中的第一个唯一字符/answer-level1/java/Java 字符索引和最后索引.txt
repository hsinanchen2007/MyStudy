    
    遍历字符，如果当前的索引就是最后的索引，则返回.

    public int firstUniqChar(String s) {
        
        for (int i = 0; i < s.length(); i++) {
            if (s.indexOf(s.charAt(i)) == s.lastIndexOf(s.charAt(i))) {
                return i;
            }
        }
        return -1;
    }