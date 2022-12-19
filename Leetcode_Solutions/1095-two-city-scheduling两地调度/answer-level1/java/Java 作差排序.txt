```java []
public class Solution {
    public int solve(int[][] costs) {
        int result = 0;
        int[] vals = new int[costs.length];
        for (int i = 0;i < costs.length;i++) {
            vals[i] = costs[i][0] - costs[i][1];     //算出飞两地的费用差值
            result = result + costs[i][1];           //将飞B地的费用加上差值作为暂时的结果
        }
        Arrays.sort(vals);                           //排序的目的是为了将最小的差值放在前面
        for (int i = 0;i < costs.length / 2;i++) {
            result += vals[i];                       //再用之前暂存的结果加上一半较小的差值便得到了到A地的费用
        }
        return result;
    }
}
