用数组模拟树
用数组表示二叉树
i位置的树的parent：(i - 1) / 2
i位置的树的左子树：2 * (i + 1) - 1
i位置的树的右子树：2 * (i + 1) 
![QQ截图20200303214246.jpg](https://pic.leetcode-cn.com/5b14b7d79551fd7fca258f33102a434831e0231377182565ffceddb69ebf2cda-QQ%E6%88%AA%E5%9B%BE20200303214246.jpg)

```
class Solution {
    public int pathSum(int[] nums) {
        int[] base = {0, 0, 1, 3, 7};
        int n = 15;
        int[] tree = new int[n];
        Arrays.fill(tree, -1);
        //把每个树放在对应的位置上
        //位置计算：每层的基准base + 层偏移量
        for (int i = 0; i < nums.length; i++) {
            int temp = nums[i];
            int level = temp / 100;
            int val = temp % 10;
            temp /= 10;
            int offset = temp % 10 - 1;
            tree[base[level] + offset] = val;
        }
        //如果当前节点不为空，就叠加计算pathsum
        //每个节点加上父节点的值
        //注意循环从1开始
        for (int i = 1; i < n; i++) {
            if (tree[i] != -1) {
                int p = (i - 1) / 2;
                tree[i] += tree[p];
            }
        }
        //加上每个叶节点的pathsum
        //叶节点，即左右子树都为空
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int left = 2 * (i + 1) - 1;
            int right = left + 1;
            if (tree[i] != -1 && (left >= n || tree[left] == -1) && (right >= n || tree[right] == -1)) {
                ans += tree[i];
            }
        }
        return ans;
    }
}
```
