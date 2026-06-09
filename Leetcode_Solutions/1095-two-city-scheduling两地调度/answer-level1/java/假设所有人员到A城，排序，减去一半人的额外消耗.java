执行用时 :2 ms, 在所有 Java 提交中击败了95.91%的用户
内存消耗 :35.6 MB, 在所有 Java 提交中击败了100.00%的用户

    class Solution {
        public int twoCitySchedCost(int[][] costs) {
            int t = costs.length;
            int cha[] = new int[t];
            int sum = 0;
            for(int i=0;i<t;i++){
                cha[i] = costs[i][1]-costs[i][0];//计算人员到A城与到B城的消耗差
                sum +=costs[i][0];//加上所有人到A城的费用
            }
            Arrays.sort(cha);
            for(int i=0;i<t/2;i++)
                sum+=cha[i];//减去应到B城的人员的额外消耗
            return sum;
        }
    }