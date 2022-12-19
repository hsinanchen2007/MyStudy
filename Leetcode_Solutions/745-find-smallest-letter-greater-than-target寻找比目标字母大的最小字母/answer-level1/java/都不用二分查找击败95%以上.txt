
first主要为了判断是否存在比target大的序列
然后接下再判断序列比target大的情况下最小序列



class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        char index = letters[0];
        boolean first=true;
        for (int i = 0; i < letters.length; i++) {
                if (target<letters[i]){
                    if (first){
                        index=letters[i];
                        first=false;
                    }
                    if (letters[i]<index){
                        index=letters[i];
                    }
                }

        }
        return index;
    }
}