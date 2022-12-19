解题思路：
遍历一遍数组，记录每个节点的父节点，通过记录判断有无成环
if
    发现子节点（leftChild、rightChild中的数据）已经有父节点了，说明是有多个节点指向该子节点，return false；
else
    当前子节点没有父节点，记录一下；
    然后从当前子节点开始向上找
        if 走到头都没有元素等于当前子节点
            说明没有形成环
        else 
            说明形成了环，return false

代码如下：
    public static boolean isCircul(Map<Integer, Integer> parent, int i) {
        boolean isCircul = false;
        int cur = i;
        while (parent.containsKey(cur)) {
            int curParent = parent.get(cur);
            if (curParent == i) {
                isCircul = true;
                break;
            }
            cur = curParent;
        }
        return isCircul;
    }

    public static boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        if (n <= 0 || leftChild == null || rightChild == null) {
            return false;
        }
        Map<Integer, Integer> parent = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (leftChild[leftChild[i]] == i || rightChild[leftChild[i]] == i) {
                    return false;
                }
                if (parent.containsKey(leftChild[i])) {
                    return false;
                }
                parent.put(leftChild[i], i);
                if (isCircul(parent, i)) {
                    return false;
                }
            }
            if (rightChild[i] != -1) {
                if (rightChild[rightChild[i]] == i || leftChild[rightChild[i]] == i) {
                    return false;
                }
                if (parent.containsKey(rightChild[i])) {
                    return false;
                }
                parent.put(rightChild[i], i);
                if (isCircul(parent, i)) {
                    return false;
                }
            }
        }
        return parent.keySet().size() == n - 1 ? true : false;
    }
![image.png](https://pic.leetcode-cn.com/96ced15df8cd6b8d9a8f846e39ae03edeff8a7a304b2cb45833240a98456e429-image.png)
执行结果：
通过
显示详情
执行用时 :40 ms, 在所有 Java 提交中击败了8.33%的用户
内存消耗 :42.6 MB, 在所有 Java 提交中击败了100.00%的用户
效率不高，请各位多指教