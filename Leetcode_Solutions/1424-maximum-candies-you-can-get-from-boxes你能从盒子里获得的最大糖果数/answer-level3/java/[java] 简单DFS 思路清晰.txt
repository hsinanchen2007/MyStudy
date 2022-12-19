```
    boolean[] isPass; // 可到达的箱子
    boolean[] isAdd;
    int[] status;
    int[] candies;
    int[][] keys;
    int[][] containedBoxes;
    int sum = 0;

    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        isPass = new boolean[status.length];
        isAdd = new boolean[status.length];
        this.status = status;
        this.candies = candies;
        this.keys = keys;
        this.containedBoxes = containedBoxes;
        for (int i : initialBoxes) {
            isPass[i] = true;
            DFS(i);
        }
        return sum;
    }

    private void DFS(int cur) {
        /**
         * 只有有钥匙并且能到达的箱子才能添加,
         * 添加过了的箱子不再遍历
         */
        if (status[cur] == 1 && !isAdd[cur] && isPass[cur]) {
            sum += candies[cur];
            isAdd[cur] = true;
        } else {
            return;
        }
        /**
         * 所有有钥匙和能到达的箱子
         */
        Set<Integer> box = new HashSet<>();
        /**
         * 开启对应有钥匙的箱子
         */
        for (int k : keys[cur]) {
            status[k] = 1;
            box.add(k);
        }
        /**
         * 记录能到达的箱子
         */
        for (int c : containedBoxes[cur]) {
            isPass[c] = true;
            box.add(c);
        }

        for (int cu : box){
            DFS(cu);
        }
    }
```
