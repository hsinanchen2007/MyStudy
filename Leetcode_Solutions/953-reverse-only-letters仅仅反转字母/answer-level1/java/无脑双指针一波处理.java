 之前用官方的Stack的方法处理也行，但是貌似效率不是很高，果然还是双指针效率高
 public String reverseOnlyLetters(String S) {
        char[] chars = S.toCharArray();
        int i = 0;
        int j = S.length() - 1;
        while (i < j) {
            while (i < j && !isLetter(S.charAt(i))) {
                i++;
            }
            while (i < j && !isLetter(S.charAt(j))) {
                j--;
            }
            char tmp = chars[j];
            chars[j] = chars[i];
            chars[i] = tmp;
            i++;
            j--;
        }
        return String.valueOf(chars);
    }
     public boolean isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }