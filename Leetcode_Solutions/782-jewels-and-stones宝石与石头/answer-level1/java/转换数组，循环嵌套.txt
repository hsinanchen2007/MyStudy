class Solution {
    public int numJewelsInStones(String J, String S) {

        char[] Jr = J.toCharArray();
        char[] Sr = S.toCharArray();

        int num = 0;

        for (int i = 0; i< Jr.length; i++){
            for (int j = 0; j< Sr.length; j++){
                if (Sr[j] == Jr[i]){
                    num++;
                    continue;
                }
            }
        }

        return num;
    }
}