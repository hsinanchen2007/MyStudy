
class Solution {
    public boolean detectCapitalUse(String word) {
       int a=0;
       int b=0;
       for(int i=0;i<word.length();i++){
           if(word.charAt(i)>='A'&&word.charAt(i)<='Z'){
               a++;
           }else{
               b++;
           }
       }
      if(a==word.length()){
          return true;
      }
      if(b==word.length()){
          return true;
      }
      if(a==1&&(word.charAt(0)>='A'&&word.charAt(0)<='Z')){
           return true;
      }  
        return false;
    }
}