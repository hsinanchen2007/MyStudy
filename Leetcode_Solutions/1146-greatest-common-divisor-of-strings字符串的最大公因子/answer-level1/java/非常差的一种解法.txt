// 时间和空间都很差的解法。。。但是好理解

public String gcdOfStrings(String str1, String str2) {
        String s = findShorterStr(str1, str2);
        int str1Len = str1.length();
        int str2Len = str2.length();
        for (int i = s.length(); i > 0; --i) {
            // 至少需要除尽才可能比较
            if (str1Len % i == 0 && str2Len % i == 0) {
                String factor = str2.substring(0, i);
                if (compareStr(factor, str1) && compareStr(factor, str2)) {
                    return factor;
                }
            }
        }
        return "";
    }

    private String findShorterStr(String str1, String str2) {
        return str2.length() > str1.length()?str1:str2;
    }

    private boolean compareStr(String factor, String str1) {
        String[] split1 = str1.split(factor);
        return split1.length == 0;
    }


