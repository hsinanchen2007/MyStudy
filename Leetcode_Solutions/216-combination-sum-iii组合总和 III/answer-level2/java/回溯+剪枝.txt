### 注释很详细了
```java
    List<List<Integer>> res = new ArrayList<>();

    // 返回和为n的k个数
    public List<List<Integer>> combinationSum3(int k, int n) {
        // 调用递归函数
        getConbination(n, k, 1, new Stack<>());
        return res;
    }

    /***
     * 
     * @param target：当前的目标和
     * @param k：当前还需要k个数
     * @param start：去重用
     * @param s
     */
    private void getConbination(int target, int k, int start, Stack<Integer> s) {
        // 递归终止条件，找到了
        if (target == 0 && k == 0) {
            res.add(new ArrayList<>(s));
            return;
        }
        for (int i = start; i <= 9; i++) {
            // 剪枝，两种情况一定不可能：1、新加入的数比目标还大 2、插入数的个数超过限制
            if (i > target || k <= 0)
                break;
            s.push(i);
            getConbination(target - i, k - 1, i + 1, s);
            s.pop();    // 回溯的关键一步，即退回到上一个状态
        }
    }
```