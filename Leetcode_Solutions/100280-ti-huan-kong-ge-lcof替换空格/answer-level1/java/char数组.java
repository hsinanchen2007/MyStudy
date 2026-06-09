    //时间复杂度O(n),空间复杂度O(n)
    //先统计空格数量
    //建立新char数组
    //按照位置加入String每一个字符
    //遇见空格加入%20

    class Solution {
        public String replaceSpace(String s) {
            int length = s.length();
            int count = 0;
            for(int i = 0; i < length; i++ ){
                if(s.charAt(i) == ' '){
                    count++;
                }
            }
            char[] chars = new char[length + 2 * count];
            int j = 0;
            for(int i = 0; i < length; i++ ){
                if(s.charAt(i) == ' '){
                    chars[j++] = '%';
                    chars[j++] = '2';
                    chars[j++] = '0';
                } else{
                    chars[j++] = s.charAt(i);
                }
            }
            return new String(chars);
        }
    }

![f8bf7751239b0869da5331e574654d3876f9cd33.jpg@518w_1e_1c.jpg](https://pic.leetcode-cn.com/45b1d8283589dd27d4f9d402cfe4fa6f52e6e57ce1479ea9078a2fe88db76609-f8bf7751239b0869da5331e574654d3876f9cd33.jpg@518w_1e_1c.jpg)

    //也可以用StringBuffer追加的方式