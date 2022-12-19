class Solution {
    public String reverseWords(String s) {
        if( s.length() == 0){
            return "";
        }
        String str = s.trim();
        StringBuilder sb = new StringBuilder();
        String[] word = str.split(" ");
        Collections.reverse(Arrays.asList(word));
        for (String s1 : word) {
            if(s1.equals("")){
                continue;
            }
            sb.append(s1 + " ");
        }
        return sb.toString().trim();
    }
}