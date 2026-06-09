```
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        String ok = "";
        String temp = "";
        int l1 = str1.length();
        int l2 = str2.length();
        int tempLength = 0;
        int minLength = Math.min(l1, l2);
        for (int i = minLength; i > 0; i--) {
            temp = str1.substring(0, i);
            if (isOk(str1, temp) && isOk(str2, temp)) {
                ok = temp;
                break;
            } else {
                continue;
            }
        }
        return ok;
    }

    private boolean isOk(String all, String sub) {
        if (sub.equals("")) {
            return false;
        }
        int allL = all.length();
        int subL = sub.length();
        if (allL % subL != 0) {
            return false;
        }
        int len = allL / subL;
        String newStr = "";
        for (int i = 0; i < len; i++) {
            newStr = newStr + sub;
        }
        return all.equals(newStr);
    }
}
```
