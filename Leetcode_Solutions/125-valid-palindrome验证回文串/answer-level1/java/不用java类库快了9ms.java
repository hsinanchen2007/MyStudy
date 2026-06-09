不用类库快了9ms 实际项目到底要不要用类库呢

class Solution {
    public boolean isPalindrome(String s) {
        
        s = s.toLowerCase();
        
        for(int i=0, j = s.length() - 1;i<j;i++,j--){
            while(i < j && !(s.charAt(i) >= 'a' && s.charAt(i) <= 'z' || s.charAt(i) >= '0' && s.charAt(i) <= '9')) i++;
            while(i < j && !(s.charAt(j) >= 'a' && s.charAt(j) <= 'z' || s.charAt(j) >= '0' && s.charAt(j) <= '9')) j--;

            if(s.charAt(i) != s.charAt(j)){
                return false;
            }
        }
        
        return true;
    }
    
}