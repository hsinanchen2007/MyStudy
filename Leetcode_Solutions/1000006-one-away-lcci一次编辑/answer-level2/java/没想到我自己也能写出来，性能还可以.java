    public boolean oneEditAway(String first, String second) {
        //相等直接返回
        if (first.equals(second)) return true;
        //jj小的是first
        if (first.length() > second.length()) {
            String tmp = first;
            first = second;
            second = tmp;
        }
        int len1 = first.length();
        int len2 = second.length();
        if (len2 - len1 > 1) {
            return false;
        }
        int i = 0, j = 0;
        int count = 0;
        if (len1 == len2) {
            while (i < len1 && j < len2) {
                if (first.charAt(i) != second.charAt(j)) {
                    count++;
                    //优化：不同超过一次直接返回
                    if (count > 1) {
                        return false;
                    }
                }
                i++;
                j++;
            }
        }else {
            while (i < len1 && j < len2) {
                if (first.charAt(i) != second.charAt(j)) {
                    count++;
                    if (count > 1) {
                        return false;
                    }
                    //短的不动  长的+1
                    j++;
                }else {
                    i++;
                    j++;
                }
            }
        }
        return true;
    }