1.规律题;
2.遇到I就start++,D就end--;
3.数组的最后一位数字要看字符串的最后一位字母,如果是I,那么就要增加,将start赋值给数组最后一个元素,D亦然;
4.完结。


        public int[] diStringMatch(String S) {
            int[] ans = new int[S.length() + 1];
            char[] c = S.toCharArray();

            int start = 0, end = c.length;
            for (int i = 0; i < c.length; i++) {
                if (c[i] == 'I')
                    ans[i] = start++;
                else
                    ans[i] = end--;
            }
            ans[ans.length - 1] = c[c.length - 1] == 'I' ? start : end;

            return ans;
        }