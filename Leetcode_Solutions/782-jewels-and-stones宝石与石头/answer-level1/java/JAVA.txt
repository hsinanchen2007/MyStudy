class Solution {
    public int numJewelsInStones(String J, String S) {
        char[] charsJ = J.toCharArray();
        char[] charsS = S.toCharArray();
        int a = 0;
        for(int i=0;i < S.length();i++){
            for(int j=0;j<J.length(); j++){
                if(charsS[i] == charsJ[j]){
                    a ++;
                }
            }
        }
        return a;
    }
}