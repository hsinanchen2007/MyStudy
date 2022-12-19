class Solution {
   public static String intToRoman(int num) {
        if(num>=1000) {
            return mv((num/1000),"","","M") + intToRoman(num % 1000);
        }else if(num>=100){
            return mv((num/100),"M","D","C")+intToRoman(num % 100);
        }else if(num>=10){
            return mv((num/10),"C","L","X")+intToRoman(num % 10);
        }else {
            return mv((num), "X", "V", "I");
        }
    }
    public static String mv(int num,String V10,String V5,String V1) {
        if (num == 9) return V1 + V10;
        if (num == 4) return V1 + V5;
        StringBuilder stringBuilder = new StringBuilder();

        if (num >= 5) {
            stringBuilder.append(V5);
        }
        for (int i = 1; i <= num % 5; i++) {
            stringBuilder.append(V1);
        }
        return stringBuilder.toString();
    }
}