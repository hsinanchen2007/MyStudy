```
    public static boolean validWordAbbreviation(String word, String abbr) {
        int i = 0;
        StringBuilder sb = new StringBuilder();
        int temp = 0;
        while (i < abbr.length()) {
            if (Character.isDigit(abbr.charAt(i))) {
                sb.append(abbr.charAt(i));
                i++;
                continue;
            } else {
                if (sb.length() != 0) {
                    if (sb.toString().startsWith("0")) {
                        return false;
                    }
                    temp = temp + Integer.parseInt(sb.toString());
                    sb.delete(0, sb.length());
                }
                if ((temp + 1) > word.length() || abbr.charAt(i) != word.charAt(temp++)) {
                    return false;
                }
                i++;
            }
        }
        if (sb.length() != 0 && ((Integer.parseInt(sb.toString()) + temp) != word.length() || sb.toString().startsWith("0"))) {
            return false;
        }
        return true;
    }
```
