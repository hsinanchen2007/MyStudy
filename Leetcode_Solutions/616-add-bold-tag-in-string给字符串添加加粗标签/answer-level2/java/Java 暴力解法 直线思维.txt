
代码即题解，直来直去。

    public String addBoldTag(String s, String[] dict) {
        int[] flags = new int[s.length()];

        for (int idx = 0; idx < s.length(); idx++) {
            String subString = s.substring(idx);
            for (String word : dict) {
                if (subString.startsWith(word)) {
                    for (int i = 0; i < word.length(); i++) {
                        if (flags[idx + i] != 1) {
                            flags[idx + i] = 1;
                        }
                    }
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < flags.length; i++) {
            if (flags[i] == 1) {
                if (i - 1 >= 0 && flags[i - 1] != 1 || i == 0) {
                    sb.append("<b>");
                }
                sb.append(s.charAt(i));
                if (i == flags.length - 1) {
                    sb.append("</b>");
                }
            } else {
                if (i - 1 >= 0 && flags[i - 1] == 1) {
                    sb.append("</b>");
                }
                sb.append(s.charAt(i));
            }
        }

        return sb.toString();
    }




