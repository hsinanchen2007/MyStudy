先求了最小公因子，从最小公因子翻倍得到最大公因子。
```
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        String ans = "";
        String subMinStr = getSubStr(str1);
        if(subMinStr.equals("")) return "";
        if(!checkIsSubStr(subMinStr,str2)) return "";
        
        int times = Math.min(getTimes(str1,subMinStr),getTimes(str2,subMinStr));
        for(int i = times ; i > 0 ; i-- ){
            ans = buildAns(i,subMinStr);
            if( checkIsSubStr(ans,str1) && checkIsSubStr(ans,str2))break;
        }
        return ans;
    }

    String buildAns(int times , String subMinStr){
        StringBuilder stringBuilder = new StringBuilder("");
        for(int i = 0 ; i < times ; i ++ ){
            stringBuilder.append(subMinStr);
        }
        return stringBuilder.toString();
    }

    int getTimes(String str, String subStr){
        int times = 0;
        for(int i=0 , j=0; i< str.length() ; i++ , j++ ){
            if( str.charAt(i) != subStr.charAt(j) ) break;
            if( j == subStr.length() -1 ) {
                j = -1;
                times ++;
            }
        }
        return times;
    }

    String getSubStr( String str1 ){
        String subStr;
        StringBuilder stringBuilder = new StringBuilder("");
        stringBuilder.append(str1.charAt(0));
        int anchor = 0;
        for(int i = 1 ; i < str1 . length( ) ; i ++ ){
             if(str1.charAt(i) != str1.charAt(0)) {
                 stringBuilder.append(str1.charAt(i));
             }
             if(str1.charAt(i) == str1.charAt(0)){
                 subStr = stringBuilder.toString();
                 if(checkIsSubStr(subStr,str1)){
                    break;
                } else {
                    stringBuilder.append(str1.charAt(i));
                }
             }
        }
        subStr = stringBuilder.toString();
        if(checkIsSubStr(subStr,str1)) return subStr;
        else return "";
    }
    boolean checkIsSubStr(String subStr, String str){
        if(subStr.length() > str.length()) return false;
        for(int i=0 , j=0; i< str.length() ; i++ , j++ ){
            if( str.charAt(i) != subStr.charAt(j) ) return false;
            if( j == subStr.length() -1 ) j = -1;
        }
        if(str.length()%subStr.length() != 0) return false;
        else return true;
    }
}
```
