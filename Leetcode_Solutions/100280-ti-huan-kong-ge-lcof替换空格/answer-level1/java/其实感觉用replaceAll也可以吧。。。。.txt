  public static String replaceSpace(String s) {
        char[] chars = s.toCharArray();
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == ' ') {
                sb.append("%20");
            }
            else {
                sb.append(chars[i]);
            }
        }
        return sb.toString();
    }