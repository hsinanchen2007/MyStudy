```
class Solution {
    public String reverseOnlyLetters(String S) {
        int start = 0, end = S.length() - 1;
        char[] chars = S.toCharArray();
        while(start < end){
            while(start < end && !isCharacter(S.charAt(start))){
                start++;
            }
            while(start < end && !isCharacter(S.charAt(end))){
                end--;
            }
            swap(chars, start, end);
            start++;
            end--;
        }
        return new String(chars);
    }
    
    private boolean isCharacter(char c){
        if (c >= 'a' && c <= 'z'){
            return true;
        }
        if (c >= 'A' && c <= 'Z'){
            return true;
        }
        return false;
    }
    
    private void swap(char[] chars, int start, int end){
        char temp = chars[start];
        chars[start] = chars[end];
        chars[end] = temp;
    }
}
```
