public class Solution {
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    public int minCost(int[][] costs) {
        int house_num = costs.length;
        if (house_num == 0) {
            return 0;
        }
        int[][] dpcosts = new int[house_num+1][costs[0].length];
        for (int i=0;i<costs[0].length;i++) {
            dpcosts[0][i] = 0;
        }
        // 使用动态规划计算最小代价
        for(int i=1;i<house_num+1;i++) {
            dpcosts[i][0] = Math.min(dpcosts[i-1][1]+costs[i-1][0], dpcosts[i-1][2]+costs[i-1][0]);
            dpcosts[i][1] = Math.min(dpcosts[i-1][0]+costs[i-1][1], dpcosts[i-1][2]+costs[i-1][1]);
            dpcosts[i][2] = Math.min(dpcosts[i-1][0]+costs[i-1][2], dpcosts[i-1][1]+costs[i-1][2]);
        }
        return Math.min(dpcosts[house_num][0], Math.min(dpcosts[house_num][1], dpcosts[house_num][2]));
    }
}