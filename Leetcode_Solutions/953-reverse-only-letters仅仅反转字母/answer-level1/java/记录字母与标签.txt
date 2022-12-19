class Solution {
    public String reverseOnlyLetters(String S) {
        StringBuilder sb = new  StringBuilder();
        ArrayList<Integer> ar = new ArrayList<Integer>();
        for(int i=0;i<S.length();i++)
        {
            if (Character.isLetter(S.charAt(i)))
                sb.append(S.charAt(i));
            else 
                ar.add(i);
        }
        sb.reverse();
        for(int i: ar) 
            sb.insert(i,S.charAt(i));
        return sb.toString();
        
    }
}