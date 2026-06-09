在所有 Java 提交中击败了82.19%的用户,尽管不是100%，供大家参考
将 n! 种排列分为：n 组，每组有 (n - 1)!个排列，根据k值可以确定是第几组的第几个排列
class Solution {
    static List<Integer> list = new LinkedList<>();

    public String getPermutation(int n, int k) {
        list.clear();    
        for (int i = 1; i <= n; i++) {
            list.add(i);
        }
        return helper3(k);
    }

    public int helper(int i) {
        if (i < 2) {
            return 1;
        }
        return i * helper(i - 1);
    }

    public String helper3(int k) {
        StringBuilder sb = new StringBuilder();
        int len = list.size();
        if (len == 1) {
            return String.valueOf(list.get(0));
        }
        int num = helper(len - 1);
        int group = (k - 1) / num;
        sb.append(list.get(group));
        list.remove(group);
        k -= num * group;
        sb.append(helper3(k));
        return sb.toString();
    }
}