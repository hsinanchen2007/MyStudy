class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int ans=0;
        int[] fre = new int[60];
        Arrays.fill(fre, 0);
        for (int i:time) fre[i%60]++;
        for (int i=1;i<30;i++) ans+=fre[i]*fre[60-i];
        ans+=getPairNum(fre[0])+getPairNum(fre[30]);
        return ans;
    }

    private int getPairNum(int num) {
        if (num<2) return 0;
        return num*(num-1)/2;
    }
}