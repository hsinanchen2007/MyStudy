**1.找出数组里面的最短字符串;
2.双层循环检查每一个字符串的每一位的一致性即可;
3.完结。**


        public String longestCommonPrefix(String[] strs) {
            if (strs.length == 0)
                return "";

            int min_length = Integer.MAX_VALUE;
            for (int i = 0; i < strs.length; i++) {
                if (min_length > strs[i].length())
                    min_length = strs[i].length();
            }
            StringBuffer res = new StringBuffer();
            for (int i = 0; i < min_length; i++) {
                for (int j = 1; j < strs.length; j++) {
                    if (strs[j].charAt(i) != strs[j - 1].charAt(i))
                        return res.toString();
                }
                res.append(strs[0].charAt(i));
            }
            return res.toString();
        }