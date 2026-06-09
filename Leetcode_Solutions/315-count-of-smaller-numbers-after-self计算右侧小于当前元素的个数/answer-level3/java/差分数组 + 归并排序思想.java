### 解题思路
主要就是利用归并排序的思想,可以参考算法导论上的逆序计数问题

特别的,在归并排序的过程中,利用helper差分数组进行加速,成功从TLE优化到了几十毫秒级

### 代码

```java
class Solution {
    private static class Node {
        private int num;
        private int index;
        private int count;

        public Node(int num, int index) {
            this.num = num;
            this.index = index;
            this.count = 0;
        }
    }

    private List<Node> calculateResult(List<Node> nodeList) {
        if (nodeList.size() == 1 || nodeList.size() == 0) {
            return nodeList;
        }

        List<Node> leftList = calculateResult(nodeList.subList(0, nodeList.size() / 2));
        List<Node> rightList = calculateResult(nodeList.subList(nodeList.size() / 2, nodeList.size()));

        List<Node> resultList = new ArrayList<>();
        int i = 0;
        int j = 0;

        int[] helper = new int[leftList.size()];
        while (i < leftList.size() && j < rightList.size()) {
            if (leftList.get(i).num > rightList.get(j).num) {
                helper[i]++;
                resultList.add(rightList.get(j++));
            } else {
                resultList.add(leftList.get(i++));
            }
        }

        int sum = 0;
        for (int t = 0; t < helper.length; t++) {
            sum += helper[t];
            leftList.get(t).count += sum;
        }

        if (i == leftList.size()) {
            resultList.addAll(rightList.subList(j, rightList.size()));
        } else {
            resultList.addAll(leftList.subList(i, leftList.size()));
        }

        return resultList;
    }

    public List<Integer> countSmaller(int[] nums) {
        List<Node> nodeList = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            nodeList.add(new Node(nums[i], i));
        }

        calculateResult(nodeList);

        int[] result = new int[nodeList.size()];
        for (Node node: nodeList) {
            result[node.index] = node.count;
        }

        List<Integer> resultList = new ArrayList<>();
        for (int num: result) {
            resultList.add(num);
        }

        return resultList;
    }
}
```