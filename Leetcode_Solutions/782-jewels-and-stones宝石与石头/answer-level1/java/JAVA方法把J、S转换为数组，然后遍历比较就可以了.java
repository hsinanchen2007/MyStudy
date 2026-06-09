class Solution {
    public int numJewelsInStones(String J, String S) {
       int index=0;
        char[]charJrr=J.toCharArray();
        char[]charSrr=S.toCharArray();
        for (int i = 0; i <charJrr.length ; i++) {
            for (int j = 0; j < charSrr.length; j++) {
                if (charJrr[i]==charSrr[j]){
                    index++;
                }
            }

        }


         return index; 
    }
}