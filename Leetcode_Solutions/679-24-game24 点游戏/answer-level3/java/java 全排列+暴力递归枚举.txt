**思路**
1. 首先，求出四个数字的全排列。参考[全排列](https://leetcode-cn.com/problems/permutations-ii/)
2. 接着，遍历所有排列，通过在排列的数字之间增加运算和括号，计算每个排列是否能够算出24。具体括号的运算也就是说先将某一对相邻的数字结合。如[1,2,3,4]，我们可以先运算1和2，得到下一个排列[1 oper 2, 3, 4]。其中**1 oper 2**可以是1+2，1-2，1*2或1/2。同时我们也可以先结合2和3，或者3和4。详见代码。
3. 除此之外，我们需要注意的是除0以及double运算会有误差，因此，我们在判断运算的结果是否等于24的时候需要考虑这个误差。如下：
```java
    Math.abs(numList.get(0) - 24) <= 1e-6;
```

```java
    private int[] nums;
    private int len;
    private List<List<Double>> permutationList;

    private void getPermutationList(List<Double> tmpList, boolean[] visited) {
        if (tmpList.size() == len) {
            permutationList.add(new ArrayList<>(tmpList));
            return;
        }

        for (int i = 0; i < len; i++) {
            if (visited[i] || i > 0 && !visited[i-1] && nums[i] == nums[i-1]) {
                continue;
            }

            visited[i] = true;
            tmpList.add((double) nums[i]);
            getPermutationList(tmpList, visited);
            tmpList.remove(tmpList.size() - 1);
            visited[i] = false;
        }
    }

    private boolean rec(List<Double> numList) {
        int size = numList.size();
        if (size== 1) {
            return Math.abs(numList.get(0) - 24) <= 1e-6;
        }

        // 选择相邻的两两先结合（执行四则运算）
        for (int i = 0; i < size - 1; i++) {
            // +，-，*，/
            List<Double> newNumList = new ArrayList<>();
            newNumList.add(numList.get(i) + numList.get(i+1));
            newNumList.add(numList.get(i) - numList.get(i+1));
            newNumList.add(numList.get(i) * numList.get(i+1));
            if (numList.get(i+1) != 0) {
                newNumList.add(numList.get(i) / numList.get(i+1));
            }

            for (Double newNum: newNumList) {
                List<Double> nextList = new ArrayList<>(numList);
                nextList.set(i, newNum);
                nextList.remove(i + 1);
                if (rec(nextList)) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean judgePoint24(int[] nums) {
        this.nums = nums;
        this.len = nums.length;
        permutationList = new ArrayList<>();
        Arrays.sort(nums);
        getPermutationList(new ArrayList<>(), new boolean[len]);

        for (List<Double> numList : permutationList) {
            if (rec(numList)) {
                return true;
            }
        }

        return false;
    }
```