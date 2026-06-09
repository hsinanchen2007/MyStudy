class Solution {
    public void reverseString(char[] s) {
        int point1 = 0;
        int point2 = s.length-1;
        while(point1 < point2){
            char tmp = s[point2];
            s[point2] = s[point1];
            s[point1] = tmp;
            point1++;
            point2--;
        }
    }
}