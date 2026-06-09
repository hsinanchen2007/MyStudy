执行用时：9 ms
战胜 97.67 % 的 java 提交记录
深度优先遍历，递归解法，不断添加末尾数字，直到长度达到N。
其中末尾数字是 前一位数字 + K 或者 前一位数字 -K
class Solution {
    public int[] numsSameConsecDiff(int N, int K) {
        if (N == 1) {
            return new int[]{0,1,2,3,4,5,6,7,8,9};
        }
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i <= 9; i++) {
            helper(list, i, 0, K, N ,0);
        }
        int[] ans = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            ans[i] = list.get(i);
        }
        return ans;
    }
    public void helper(List<Integer> list, int temp, int count, int K, int N, int ans) {
        ans += temp;
        count++;
        if (count == N) {
            list.add(ans);//长度达到N之后结束递归，将结果添加到答案中，返回上一层；
            return;
        }
        if (temp - K >= 0) {
            helper(list, temp - K, count, K, N, ans * 10);
        }
        if (temp + K < 10 && K != 0) {
            helper(list, temp + K, count, K, N, ans * 10);//第一遍提交未判断 K != 0，导致结果出现重复
        }
    }
}