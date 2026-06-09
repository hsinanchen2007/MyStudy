    /**
     * 使用不断循环匹配结果
     * @param s
     * @return
     */
    public String compressString(String s) {
        if(s == null || s.length() == 0){
            return s;
        }
        StringBuilder sb = new StringBuilder();
        char[] chars = s.toCharArray();
        int i = 1;
        int cuIen = 1;
        char lastC = chars[0];
        while (i != chars.length) {
            if (chars[i] == lastC) {
                cuIen++;
            } else {
                sb.append(lastC).append(cuIen);
                cuIen = 1;
            }
            lastC = chars[i];
            i++;
        }
        sb.append(lastC).append(cuIen);
        return s.length() <= sb.length() ? s : sb.toString();
    }