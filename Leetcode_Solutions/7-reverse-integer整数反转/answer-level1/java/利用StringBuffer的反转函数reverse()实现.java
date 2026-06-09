class Solution {
    public int reverse(int x) {
        StringBuffer stringBuffer = new StringBuffer(String.valueOf(x));
        //如果为负数。先去掉符号再反转，然后再把符号加上
        if (stringBuffer.charAt(0) == '-'){
            stringBuffer.deleteCharAt(0);
            stringBuffer.reverse();
            try{
                int rev = Integer.parseInt("-" + stringBuffer.toString());
                return rev;
            }catch(NumberFormatException e1){
                return 0;
            }
        }
        //如果为正数
        stringBuffer.reverse();
        try{
            int rev = Integer.parseInt(stringBuffer.toString());
            return rev;
        }catch(NumberFormatException e2){
            return 0;
        }
    }
}