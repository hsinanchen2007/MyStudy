- 1 交换
```
/**
     * 交换法
     * 1
     * 12，21
     * 123，321，132；213，312，231
     *
     * @param nums 数组
     * @return 排列数组
     */
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        res.add(list);

        lable1:
        for (int num : nums) {
            int resSize = res.size();
            for (int j = 0; j < resSize; j++) {
                List<Integer> lt = res.get(j);
                int len = lt.size();

                // 终止
                if (len == nums.length) {
                    break lable1;
                }

                // 加入元素
                lt.add(num);

                // 交换位置并添加
                for (int i = 0; i < lt.size() - 1; i++) {
                    List<Integer> temp = new ArrayList<>(lt);
                    temp.set(temp.size() - 1, temp.get(i));
                    temp.set(i, num);
                    res.add(temp);
                }
            }
        }
        return res;
    }
```

- 2 插入法
```
/**
     * 插入法
     * 1
     * 12， 21
     * 123，132，312； 213，231，321
     *
     * @param nums 数组
     * @return 排列数组
     */
    public List<List<Integer>> permute2(int[] nums) {
        LinkedList<List<Integer>> res = new LinkedList<>();
        List<Integer> list = new LinkedList<>();
        res.add(list);

        lable1:
        for (int num : nums) {
            int resSize = res.size();
            for (int i = 0; i < resSize; i++) {
                // 取出第一个
                List<Integer> lt = res.removeFirst();
                int len = lt.size();

                // 终止条件
                if (len == nums.length) {
                    break lable1;
                }

                // 插入元素，并添加
                while (len >= 0) {
                    List<Integer> temp = new LinkedList<>(lt);
                    temp.add(len, num);
                    res.add(temp);
                    len--;
                }
            }
        }
        return res;
    }
```

- 3 回溯
```
 /**
     * 回溯法
     * 注：终止条件，回退方式
     *
     * @param nums 数组
     * @return 排列数组
     */
    public List<List<Integer>> permute1(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();

        Stack<Integer> stack = new Stack<>();
        this.sort(res, nums, stack);
        return res;
    }

    private void sort(List<List<Integer>> res, int[] nums, Stack<Integer> stack) {
        // 终止点
        if (nums.length == stack.size()) {
            res.add(new ArrayList<>(stack));
            return;
        }
        // 回溯
        for (int num : nums) {
            if (stack.contains(num)) {
                continue;
            }
            stack.push(num);
            sort(res, nums, stack);
            stack.pop();
        }

    }
```
