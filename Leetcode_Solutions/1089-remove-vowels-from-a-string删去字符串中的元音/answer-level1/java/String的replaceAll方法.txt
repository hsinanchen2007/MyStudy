class Solution {
    public String removeVowels(String S) {
        S=S.replaceAll("a","");
        S=S.replaceAll("e","");
        S=S.replaceAll("i","");
        S=S.replaceAll("o","");
        S=S.replaceAll("u","");
        return S;
    }
}