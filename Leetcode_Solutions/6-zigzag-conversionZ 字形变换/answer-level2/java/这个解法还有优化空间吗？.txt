public static String convert(String s, int numRows) {
        if(s == null || s == "" || numRows == 1){
            return s;
        }
        StringBuilder result = new StringBuilder();
        String[] split = s.split("");
        int j = 2 + (numRows - 2) * 2;
        int height = 0;
        int i = 0;
        Boolean b = true;
        while (height < numRows) {
            int k = 0;
            if (height == 0 || height == numRows - 1){
                k = j;
            }else {
                if (b) {
                    k = j - 2 * height;
                    b = false;
                }else {
                    k = j - (j - 2 * height);
                    b = true;
                }
            }

            if (i >= split.length) {
                i = ++height;
                b = true;
                continue;
            }
            result.append(split[i]);
            i += k;
        }
        return result.toString();
    }