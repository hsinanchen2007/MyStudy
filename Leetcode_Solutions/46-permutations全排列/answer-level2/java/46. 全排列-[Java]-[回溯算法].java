
```java
    /**
     * 解题思路（回溯算法）:
     * 根据题意，数组中的每一个数字，都可能出现在排列中的任何位置，所以一个个的去试着放
     * 1、将数组转换成一个list，再定义一个itemList保存遍历结果，retList保存返回结果
     * 2、循环list下标index，取index的数加入itemList，将其移除list
     * 3、再将剩余的list重复第2步
     * 4、当itemList的大小==数组大小，添加到retList
     * 5、回退第2步，将之前移除的数组添加到list中，并从itemList中移除
     *
     * @param nums
     * @return
     */
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> retList = new ArrayList<>();
        List<Integer> numList = toList(nums);
        dfs(numList, retList, new ArrayList<>(), nums.length);
        return retList;
    }

    private void dfs(List<Integer> numList,
                     List<List<Integer>> retList,
                     List<Integer> itemList,
                     int n) {
        if (itemList.size() == n) {
            retList.add(new ArrayList<>(itemList));
            return;
        }
        for (int i = 0; i < numList.size(); i++) {
            Integer item = numList.remove(i);
            itemList.add(item);
            dfs(numList, retList, itemList, n);
            itemList.remove(item);
            numList.add(i, item);
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