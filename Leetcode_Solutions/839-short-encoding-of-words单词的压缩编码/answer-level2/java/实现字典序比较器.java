    //复习什么是字典序 
    //字典序比较分两种：1.两个字符串长度相等。2.两个字符串长度不等。
    //当两个字符串长度相等时，比如abc和bac，将每一位的字母想象成
    //相应的26进制的数（字符在a-z范围内的话），从开头依次比较，ASCII码值中 a < b，则第一个字符串小。
    //当两个字符串不等时，将短的那个右边补上最小的ASCII码值，变成长度相等的字符串，然后再一位位的比较ASCII码的int值，
    //所以，如果短的那个字符串是长的前缀的话，就相当于比较两个长度（反正比较器都会返回负数）
    class Solution {
        public int minimumLengthEncoding(String[] words) {
            Arrays.sort(words, new Comparator<String>() {
                @Override
                public int compare(String o1, String o2) {    // 字典序比较器
                    int len1 = o1.length();
                    int len2 = o2.length();
                    for(int i = 0;i < len1 && i < len2;i++) {
                        char c1 = o1.charAt(len1 - i - 1);
                        char c2 = o2.charAt(len2 - i - 1);
                        if(c1 != c2) {
                            return c1 - c2;
                        }
                    }
                    return len1 - len2;
                }
            });
            int res = 0;
            for(int i = 0;i < words.length;i++) {
                if(i == words.length - 1 || !words[i + 1].endsWith(words[i])) {
                    res += words[i].length() + 1;
                }
            }
            return res;
        }
    }