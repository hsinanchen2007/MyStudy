import java.util.regex.Pattern;
class Solution {
 public static int expressiveWords(String S, String[] words) {
        int counter = 0;

        // 特殊处理，刚好有长度一样的字符串
        if (S.length() < 3) {
            //检查是否有相同的
            for (String temp : words) {
                if (temp.equals(S)) {
                    counter++;
                }
            }
            return counter;
        }

        String pattern = getPattern(S);

        //System.out.println(pattern);

        for (String s : words) {
            boolean isMatch = Pattern.matches(pattern, s);
            if (isMatch) {
                // S=aaa,s=aaaa，都是一样的字符，并且字符数多于S
                if (s.length() <= S.length()) {
                    counter++;
                }
            }
        }

        return counter;
    }

    public static String getPattern(String S) {
        StringBuffer pattern = new StringBuffer("^");

        //
        for (int i = 0; i < S.length() - 2; ) {
            if ((S.charAt(i) == S.charAt(i + 1)) && (S.charAt(i) == S.charAt(i + 2))) {
                pattern.append(S.charAt(i));
                pattern.append("{1,}");

                i = i + 2;
                if (i < S.length() - 2) {
                    for (int j = i + 1; S.charAt(j) == S.charAt(i); j++) {
                        i++;
                        if (j == S.length() - 1) {
                            break;
                        }
                    }

                    if (i < S.length() - 1) {
                        i++;
                    }

                }

            } else {
                pattern.append(S.charAt(i));
                i++;
            }
        }

        // 最后2个字符的处理
        if (!(S.charAt(S.length() - 3) == S.charAt(S.length() - 2))) {
            pattern.append(S.charAt(S.length() - 2));
        }

        // 最后1个字符的处理
        if (!(S.charAt(S.length() - 3) == S.charAt(S.length() - 1))) {
            pattern.append(S.charAt(S.length() - 1));
        }
        pattern.append("$");

        return pattern.toString();
    }

}