```
class Solution {
    public String reverseWords(String s) {
        if(null == s){
            return null;
        }
        String[] arr = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for(String word : arr){
            sb.append(new StringBuilder(word).reverse());
            sb.append(" ");
        }
        int len = sb.length();
        if(len >= 1){
            sb.deleteCharAt(len - 1);
        }
        return sb.toString();
    }
}
```
