class Solution {
    public int[] numMovesStonesII(int[] stones) {
        int len = stones.length;
        Arrays.sort(stones);
        int mx = stones[len-1] - stones[0]+1-len;
        mx -= Math.min(stones[len-1]-stones[len-2]-1,stones[1]-stones[0]-1 );
        int mi = mx;
        int i = 0,j = 0,cost;
        for (; i < len; ++i) {
            while (j+1<len&&stones[j+1]-stones[i]+1<=len){
                ++j;
            }
            cost = len-(j-i+1);
            if(j - i + 1 == len- 1 && stones[j] - stones[i] + 1 == len - 1){
                cost = 2;
            }
            mi = Math.min(mi,cost);
        }
        int[] result = {mi,mx};
        return result;
    }
}