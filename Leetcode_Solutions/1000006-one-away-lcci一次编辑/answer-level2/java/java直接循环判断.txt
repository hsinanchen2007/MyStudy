![image.png](https://pic.leetcode-cn.com/233e26c70561d9766233186320fc55b67dbd8c561bd97b682d020e9fa2f08acd-image.png)


public boolean oneEditAway(String first, String second) {
        // "",""
        if (first.length() == 0 && second.length() == 0) {
            return true;
        }

        // "a","a"
        if (first.length() == 1 && second.length() == 1) {
            return true;
        }

        // 长度大于1
        if (Math.abs(first.length() - second.length()) > 1) {
            return false;
        }

        // replace
        if (Math.abs(first.length() - second.length()) == 0) {
            int diffCount = 0;
            for (int i = 0; i < first.length(); i++) {
                if (first.charAt(i) != second.charAt(i)) {
                    diffCount++;
                }
            }

            if (diffCount > 1) {
                return false;
            } else {
                return true;
            }

        }

        // insert delete
        if (Math.abs(first.length() - second.length()) == 1) {
            String small;
            String big;
            if (first.length() - second.length() < 0) {
                small = first;
                big = second;
            } else {
                small = second;
                big = first;
            }

            for (int j = 0; j < small.length(); j++) {
                if ((small.charAt(j) != big.charAt(j)) && (small.charAt(j) != big.charAt(j + 1))) {
                    return false;
                }
            }

        }

        return true;
    }