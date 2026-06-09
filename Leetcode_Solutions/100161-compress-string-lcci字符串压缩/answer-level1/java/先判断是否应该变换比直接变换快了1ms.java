    public String compressString(String S) {
        int len = S.length();
        //先判断是否变换后比变换前更长
        int count = 1;
        for (int i = 0; i < len - 1; i++) {
            if (S.charAt(i + 1) != S.charAt(i)) {
                count++;
            }
        }
        if (2 * count >= len) return S;

        //字符不同的位置
        int index = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len - 1; i++) {
            if (S.charAt(i + 1) != S.charAt(i)) {
                sb.append(S.charAt(i)).append(i + 1 - index);
                index = i + 1;
            }
        }
        //考虑最后一个字符
        sb.append(S.charAt(len - 1)).append(len - index);
        return sb.toString();
    }