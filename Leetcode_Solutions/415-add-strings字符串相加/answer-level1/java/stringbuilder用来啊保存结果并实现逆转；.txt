class Solution {
    public String addStrings(String num1, String num2) {
        int len=num2.length(),les=0;
        StringBuilder sb=new StringBuilder();
        if(num1.length()<num2.length()){
            len=num1.length();
          
        }
        for(int i=0;i<len;i++){
            int sum=(num1.charAt(num1.length()-1-i)-'0')+(num2.charAt(num2.length()-1-i)-'0')+les;
            int a=sum%10;
            les=sum/10;
            sb.append(a);
        }
        for(int j=len;j<num1.length();j++){
             int sum=(num1.charAt(num1.length()-1-j)-'0')+les;
            int a=sum%10;
            les=sum/10;
            sb.append(a);
        }
        for(int j=len;j<num2.length();j++){
             int sum=(num2.charAt(num2.length()-1-j)-'0')+les;
            int a=sum%10;
            les=sum/10;
            sb.append(a);
        }
        if(les!=0){
        sb.append(les);
        }
        sb.reverse();
        return sb.toString();
    }
}