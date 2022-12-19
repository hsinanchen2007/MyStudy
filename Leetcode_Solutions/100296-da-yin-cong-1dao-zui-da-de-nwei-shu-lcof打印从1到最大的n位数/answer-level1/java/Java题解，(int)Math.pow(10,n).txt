class Solution {
    public int[] printNumbers(int n) {
        int len = (int)Math.pow(10,n);
        int[] res = new int[len-1];
        for(int i=1;i<len;i++){
            res[i-1]=i;
        }
        return res;
    }
}