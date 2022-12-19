    /**
     * 辗转相除法，迭代更新large和small，有GCD的字符串pair除完之后small应该为空字符串""
     * 如：large = "ABCABC", small = "ABC"
     *    large = "ABC", small = ""
     * 没有GCD的字符串pair除完之后small不为空
     * 如：large = "ABCDEF", small = "ABC"
     *    large = "ABC", small = "DEF"
     */
    public String gcdOfStrings(String str1, String str2) {
        String large = str1.length() >= str2.length() ? str1 : str2;
        String small = str1.length() < str2.length() ? str1 : str2;
        while (!getRemainingString(large, small).equals(large)) {
            String temp = large;
            large = small;
            small = getRemainingString(temp, small);
        }
        if (small.length() != 0) {
            return "";
        }

        return large;
    }


    private String getRemainingString(String large, String small) {
        return large.replaceAll(small, "");
    }