用一个变量标记A出现的次数，大于2 直接false； 对于出现的L 判断前一位和后一位是不是L 如果是直接false;
class Solution {
    public boolean checkRecord(String s) {
         int count = 0;

        boolean result = true;

        for (int i = 0 ; i < s.length();i++){

            String str = String.valueOf(s.charAt(i));

            if ("A".equals(str)){
                if (count > 1){
                    result = false;
                    break;
                }else {
                    count++;
                }

            }else if ("L".equals(str) && i > 0 && "L".equals(String.valueOf(s.charAt(i-1))) && "L".equals(String.valueOf(s.charAt(i+1))) && i < s.length()-1){
                result = false;    
                break;
            }

        }
        return result;
    }
}