 public int lengthOfLastWord(String s) {
        String str = s.trim();
        int len = str.lastIndexOf(" ");
        return str.substring(len + 1).length();
    }