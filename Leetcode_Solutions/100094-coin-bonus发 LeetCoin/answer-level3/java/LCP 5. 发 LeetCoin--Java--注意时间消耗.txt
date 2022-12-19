[Leetcode-Java(200+题解，持续更新、欢迎star)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/LCP/_5_bonus_2.java)

[原始题解，易理解，但提交超时](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/LCP/_5_bonus.java)
```java
    private int mod = 1000000007;

    /**
     * 解题思路：
     * 1、构建树及依赖关系
     * 2、按操作赋值
     * 3、保存取值结果
     * <p>
     * 比较{@link _5_bonus}优化：、
     * 发团队币，全部发给团队负责人，负责人统一保存
     * 1、为了让取币总和更快，在发币的时候就保存了团队币总和
     * 2、由于发币团队成员都是一致的，所以负责人中可以保存下属的同样的币（每个人还可以有自己特有的币）
     *
     * 执行用时 :47 ms , 在所有 Java 提交中击败了93.62% 的用户
     * 内存消耗 :89.6 MB, 在所有 Java 提交中击败了100.00%的用户
     *
     * @param n
     * @param leadership
     * @param operations
     * @return
     */
    public int[] bonus(int n, int[][] leadership, int[][] operations) {
        List<Integer> retList = new ArrayList<>();
        //创建树
        CoinTree[] trees = new CoinTree[n + 1];
        for (int i = 1; i <= n; i++) {
            trees[i] = new CoinTree(i);
        }
        //构造依赖关系
        for (int i = 0; i < leadership.length; i++) {
            int[] item = leadership[i];
            //计算团队成员
            CoinTree parent = trees[item[0]];
            trees[item[1]].parent = parent;
            while (parent != null) {
                parent.teamSize++;
                parent = parent.parent;
            }
        }
        //操作
        for (int i = 0; i < operations.length; i++) {
            int[] item = operations[i];
            //操作类型
            int operation = item[0];
            switch (operation) {
                case 1://给某个人发币
                    addPersonCoin(trees[item[1]], item[2]);
                    break;
                case 2://给某个人和他的团队发币
                    addTeamCoin(trees[item[1]], item[2]);
                    break;
                case 3://计算某个人和他的团队币总和，并记录返回
                    retList.add(getTeamCoin(trees[item[1]]));
                    break;
            }
        }

        //list to array
        int[] retArr = new int[retList.size()];
        for (int i = 0; i < retList.size(); i++) {
            retArr[i] = retList.get(i);
        }

        return retArr;
    }

    private int getTeamCoin(CoinTree tree) {
        long result = tree.teamCoinAll;
        int size = tree.teamSize;
        CoinTree parent = tree.parent;
        while (parent != null) {
            result += parent.teamCoin * size;
            parent = parent.parent;
        }
        return (int) (result % mod);
    }

    private void addPersonCoin(CoinTree tree, int coin) {
        tree.teamCoinAll += coin;
        CoinTree parent = tree.parent;
        while (parent != null) {
            parent.teamCoinAll += coin;
            parent = parent.parent;
        }
    }

    private void addTeamCoin(CoinTree tree, int coin) {
        tree.teamCoin += coin;
        int teamAddCoin = coin * tree.teamSize;
        tree.teamCoinAll += teamAddCoin;
        CoinTree parent = tree.parent;
        while (parent != null) {
            parent.teamCoinAll += teamAddCoin;
            parent = parent.parent;
        }
    }

    class CoinTree {
        int value;
        int teamSize;  //团队成员（包括自己）
        long teamCoin;  //团队每个人共有
        long teamCoinAll;//团队总共有的
        CoinTree parent;

        public CoinTree(int value) {
            this.value = value;
            teamSize = 1;//自己
        }
    }
```