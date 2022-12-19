class Solution {
    public boolean isPerfectSquare(int num) {
                long r = num / 2 + 1;
         while (r*r >=num) {
             r = (r + num/r)/2;
             if (r*r == num) return true;
         }
         return false;

    }
}