class Solution {
    public String removeVowels(String S) {
        Set<Character> set=new HashSet<>();
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<S.length();i++){
            if(set.contains(S.charAt(i))){
                continue;
            }
            sb.append(S.charAt(i));
        }
        return sb.toString();
    }
}