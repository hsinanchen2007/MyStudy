
```java
    /**
     * 解题思路：
     * 1.先对数组进行排序
     * 2.循环数组，从第0位开始取数，不断叠加直到（c[i]/target的除数）
     * 3.如 == target,则保存下来
     * 4.如 > target，则--当前数的个数，循环步骤2
     * 5.如 < target，则取下一位
     *
     * @param candidates
     * @param target
     * @return
     */
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> retList = new ArrayList<>();
        //排序
        Arrays.sort(candidates);
        //递归循环
        combinationSum(candidates, target, 0, retList, new ArrayList<>(), 0);

        return retList;
    }

    private void combinationSum(int[] candidates,
                                int target,
                                int index,
                                List<List<Integer>> retList,
                                List<Integer> addList,
                                int addSum) {
        if (index >= candidates.length) return;
        int n = (target - addSum) / candidates[index];
        if (n == 0) return;
        //全部添加到队列中
        for (int i = 0; i <= n; i++) {
            addList.add(candidates[index]);
        }
        int nSum = (n+1) * candidates[index];
        for (int i = n; i >= 0; i--) {
            //每次减-后，更新sum和list
            nSum -= candidates[index];
            addList.remove(addList.size() - 1);
            if (nSum + addSum == target) {
                //等于，添加到队列中
                retList.add(new ArrayList<>(addList));
            } else if (nSum + addSum > target) {
                //大于，--i
            } else {
                //小于，向后取数
                combinationSum(candidates, target, index + 1, retList, addList, addSum + nSum);
            }
        }
    }
```