动态规划：
首先按Capital排序
当k大于等于Profits的长度时，dp[i][j], i是第i个项目，j是是否做这个项目，取0和1
当k小于Profits的长度时，dp[i][j][k]，i是第一个项目，j是当前做的第j个项目，k是是否做这个项目，取0和1

class Solution {
    public int findMaximizedCapital(int k, int W, int[] Profits, int[] Capital) {
        if (k >= Profits.length) {
            return maxk(k, W, Profits, Capital);
        }
        int[][][] dp = new int[Profits.length + 1][k + 1][2];
        Element[] elements = new Element[Capital.length];
        for (int i = 0; i <= Profits.length; i++) {
            dp[i][0][0] = W;
            dp[i][0][1] = Integer.MIN_VALUE;
            if (i != Profits.length) {
                elements[i] = new Element(i, Capital[i]);
            }
        }
        for (int i = 0; i <= k; i++) {
            dp[0][i][0] = W;
            dp[0][i][1] = Integer.MIN_VALUE;
        }
        Arrays.sort(elements);
        for (int i = 1; i <= elements.length; i++) {
            for (int j = 1; j <= k; j++) {
                // 第i个项目不做
                dp[i][j][0] = Math.max(dp[i - 1][j][0], dp[i - 1][j][1]);
//                System.out.println(String.format("dp[%d][%d]%d]", i, j ,0) + " : " + dp[i][j][0]);
                // 第i个项目做
                if (Math.max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) >= elements[i - 1].c) {
                    int a = dp[i - 1][j][0];
                    int b = dp[i - 1][j - 1][1];
                    int c = Profits[elements[i - 1].i];
                     dp[i][j][1] = Math.max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + Profits[elements[i - 1].i];
                } else {
                    dp[i][j][1] = Integer.MIN_VALUE;
                }
//                System.out.println(String.format("dp[%d][%d]%d]", i, j ,1) + " : " + dp[i][j][1]);
            }
        }
        return Math.max(dp[elements.length][k][0], dp[elements.length][k][1]);
    }

    private int maxk(int k, int W, int[] Profits, int[] Capital) {
        int[][] dp = new int[Profits.length + 1][2];
        Element[] elements = new Element[Capital.length];
        for (int i = 0; i <= Profits.length; i++) {
            dp[i][0] = W;
            dp[i][1] = Integer.MIN_VALUE;
            if (i != Profits.length) {
                elements[i] = new Element(i, Capital[i]);
            }
        }
        for (int i = 0; i <= k; i++) {
            dp[0][0] = W;
            dp[0][1] = Integer.MIN_VALUE;
        }
        Arrays.sort(elements);
        for (int i = 1; i <= elements.length; i++) {
                // 第i个项目不做
                dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
//                System.out.println(String.format("dp[%d][%d]%d]", i, j ,0) + " : " + dp[i][j][0]);
                // 第i个项目做
                if (Math.max(dp[i - 1][0], dp[i - 1][1]) >= elements[i - 1].c) {
                    int a = dp[i - 1][0];
                    int b = dp[i - 1][1];
                    int c = Profits[elements[i - 1].i];
                    dp[i][1] = Math.max(dp[i - 1][0], dp[i - 1][1]) + Profits[elements[i - 1].i];
                } else {
                    dp[i][1] = Integer.MIN_VALUE;
                }
//                System.out.println(String.format("dp[%d][%d]%d]", i, j ,1) + " : " + dp[i][j][1]);
        }
        return Math.max(dp[elements.length][0], dp[elements.length][1]);
    }
}

class Element implements Comparable<Element>{
    int c;
    int i;
    public Element (int i, int c) {
        this.i = i;
        this.c = c;
    }

    @Override
    public int compareTo(Element o) {
        return this.c - o.c;
    }
}