class Solution {
    public int lengthOfLastWord(String s) {
        
        int i = s.length() - 1;

        int j = 0;

        for (; i >= 0; i--) {

            if (s.charAt(i) == ' ') {

                if (j > 0) {
                    return j;
                }

            } else {
                j++;
            }

        }

        return j;


    }
}