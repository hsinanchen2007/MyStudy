class Solution {
    public int reverse(int x) {
        StringBuilder str = new StringBuilder("");
        if(x < 0){
            str.append("-");
        }
        try{
            return Integer.parseInt(str.toString()+new StringBuilder(String.valueOf(Math.abs( x))).reverse().toString());
        }catch(Exception e){
            return 0;
        }
        
    }
}