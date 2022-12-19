先确定公共前缀最长多少，再去循环比对
```
public String longestCommonPrefix(String[] strs) {
        
        if(strs == null) {
            return "";
        }
        
        int strLen = strs.length;
        if(strLen == 0) {
            return "";
        }
        if(strLen == 1) {
            return strs[0];
        }

        /* 1. find min foreach count */
        int forCount = strs[0].length();
        for (int index = 1; index < strLen; index++) {
            if (forCount > strs[index].length()) {
                forCount = strs[index].length();
            }
        }

        /* 2. foreach first string and compare */
        StringBuffer commonPrefix = new StringBuffer();
        boolean theEnd = false;
        for (int indexX = 0; indexX < forCount; indexX++) {
            char strZeroCurrentChar = strs[0].charAt(indexX);
            for (int indexY = 1; indexY < strLen; indexY++) {
                if (strs[indexY].charAt(indexX) != strZeroCurrentChar) {
                    theEnd = true;
                    break;
                }
            }
            if (theEnd) {
                break;
            }
            commonPrefix.append(strZeroCurrentChar);
        }
        return commonPrefix.toString();
    }
```
