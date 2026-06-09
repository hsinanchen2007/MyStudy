
```java

    /**
     * 解题思路：
     * 整体思路类似，参考46-全排列题解 {@link https://leetcode-cn.com/problems/permutations/solution/46-quan-pai-lie-java-hui-su-suan-fa-by-pphdsny/}，其中需要注意的一点是，重复数字再取的时候得跳过
     * 1.先对数组进行排序
     * 2.采用回溯算法进行取数，当即将取到的数和之前回退回来的数一致的时候，再向上一层回溯
     *
     * @param nums
     * @return
     */
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> retList = new ArrayList<>();
        Arrays.sort(nums);
        List<Integer> numList = toList(nums);
        dfs(numList, retList, new ArrayList<>(), nums.length);
        return retList;
    }

    //递归回溯
    private void dfs(List<Integer> numList,
                     List<List<Integer>> retList,
                     List<Integer> itemList,
                     int n) {
        if (itemList.size() == n) {
            retList.add(new ArrayList<>(itemList));
            return;
        }
        Integer preNum = null;
        for (int i = 0; i < numList.size(); i++) {
            if (preNum != null && preNum.equals(numList.get(i))) {
                //重复数字，不重复取
                continue;
            }
            Integer item = numList.remove(i);
            itemList.add(item);
            dfs(numList, retList, itemList, n);
            itemList.remove(itemList.size() - 1);
            numList.add(i, item);
            preNum = item;
        }
    }

    private List<Integer> toList(int[] nums) {
        List<Integer> retList = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            retList.add(nums[i]);
        }
        return retList;
    }
```