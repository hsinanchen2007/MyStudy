class Solution {
    public int firstUniqChar(String s) {
        // map
        // 转换成ASCII编码   97 - 122

        // 27个字母
         int [] c = new int[27];

         char[] chars = s.toCharArray();
         for (int i = 0, j = chars.length; i < j; i++) {
           c[(int)chars[i] % 97]++;
         }
       
         int result = -1;
         for (int i = 0, j = chars.length; i < j; i++) {
           if (c[(int)chars[i] % 97] == 1) {
               result = i;
               break;
           }
        }

       return result;
    }
}