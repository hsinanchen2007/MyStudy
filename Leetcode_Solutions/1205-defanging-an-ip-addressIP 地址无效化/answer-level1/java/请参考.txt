- class Solution {
   
   public String defangIPaddr(String address) {
      String result="";
      int acount=0;
        for(int i=0; i<address.length();i++) {
            if (address.charAt(i)=='.') {      
                result += address.substring(acount,i);
                result += "[.]";
                acount = i+1;    
            }
        }        
        return result+address.substring(acount,address.length());  
    
}
}