假设p是\*aa\*bb\*cc，其实这里只需要关心aa，bb，cc在s中出现的顺序即可。
```
public boolean isMatch(String s, String p) {
        if (p.equals("*")) {
            return true;
        }
        p = "#" + p + "#";
        s = "#" + s + "#";
        String[] pArr = p.split("\\*");
        int i = 0;
        int j = 0;
        while (i < s.length() && j < pArr.length) {
            if ((i + pArr[j].length()) > s.length()) {
                return false;
            }
            if (healper(s.substring(i, i + pArr[j].length()), pArr[j])) {
                i += pArr[j].length();
                j++;
            } else {
                i++;
            }
        }
        return i == s.length() && j == pArr.length;
    }

    public boolean healper(String s, String p) {
        for (int i = 0; i < s.length(); i++) {
            if (p.charAt(i) == '?') {
                continue;
            }
            if (s.charAt(i) != p.charAt(i)) {
                return false;
            }
        }
        return true;
    }
```
