# 深度优先搜索(dfs)
## 递归
### 思路
- **初始化变量**:
    - 通过下标记录每一层的节点数的list——levelNum
    - 通过下标记录每一层节点val的总数的list——levelSum
    - 结果ans——每一层都是：levelSum / levelNum
- **递归参数**：
    - 遍历搜索到的节点node
    - 记录层数的level
    - levelNum
    - levelSum
- **递归逻辑**：
    - 退出条件：node == null
    - 递归层的处理逻辑：
        - 如果level >= 两个list任意一个的长度，代表第一次递归搜索到这一层，初始化这一层的两个list的元素
        - 否则就是通过level从两个list中取出元素，更新一下再放回去
    - 递归搜索左右子树
- **循环两个list，计算ans每一层的平均值，返回ans**
### 代码
```java[]
public class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> ans = new ArrayList<>();
        List<Integer> levelNum = new ArrayList<>();
        List<Double> levelSum = new ArrayList<>();
    
        rescurse(root, 0, levelNum, levelSum);
    
        for (int i = 0; i < levelNum.size(); i++) {
            ans.add(levelSum.get(i) / levelNum.get(i));
        }
    
        return ans;
    }
    
    private void rescurse(TreeNode node, int level, List<Integer> levelNum, List<Double> levelSum) {
        if (node == null) {
            return;
        }
    
        if (levelNum.size() <= level) {
            levelNum.add(1);
            levelSum.add((double) node.val);
        } else {
            levelNum.set(level, levelNum.get(level) + 1);
            levelSum.set(level, levelSum.get(level) + node.val);
        }
    
        rescurse(node.left, level + 1, levelNum, levelSum);
        rescurse(node.right, level + 1, levelNum, levelSum);
    }
}
```
## 非递归(Stack)
### 思路
思路和递归基本一致，使用stack来驱动遍历搜索的过程
### 代码
```java[]
public class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }

        List<Integer> levelNum = new ArrayList<>();
        List<Double> levelSum = new ArrayList<>();
        Stack<int[]> entryStack = new Stack<>();
        int[] rootEntry = new int[]{root.val, 0};
        entryStack.push(rootEntry);

        Stack<TreeNode> nodeStack = new Stack<>();
        nodeStack.push(root);

        while (!entryStack.isEmpty()) {
            int[] entry = entryStack.pop();
            int val = entry[0];
            int level = entry[1];

            if (level >= levelNum.size()) {
                levelNum.add(1);
                levelSum.add((double) val);
            } else {
                levelNum.set(level, levelNum.get(level) + 1);
                levelSum.set(level, levelSum.get(level) + val);
            }

            TreeNode node = nodeStack.pop();
            if (node.left != null) {
                int[] leftEntry = new int[]{node.left.val, level + 1};
                entryStack.push(leftEntry);
                nodeStack.push(node.left);
            }

            if (node.right != null) {
                int[] rightEntry = new int[]{node.right.val, level + 1};
                entryStack.push(rightEntry);
                nodeStack.push(node.right);
            }
        }

        for (int i = 0; i < levelNum.size(); i++) {
            ans.add(levelSum.get(i) / levelNum.get(i));
        }

        return ans;
    }
}
```
# 广度优先搜索(bfs)
## 非递归(Queue)
### 思路
广度优先的话，就一层层的处理计算，然后放入list中就可以了。
- 在利用Queue驱动
- 每一次循环先拿到Queue的长度(这个长度就是每一层的节点数)
- while循环从队列中取出当前层的所有节点：
    - 统计个数
    - 累加值
    - 将左右子树放入队列
- 循环两个list后，计算ans每一个元素的值
- 最后返回ans
### 代码
```java[]
public class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }

        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int count = queue.size();
            int num = count;
            double total = 0;
            while (count-- > 0) {
                TreeNode node = queue.poll();

                if (node == null) {
                    continue;
                }

                total += node.val;

                if (node.left != null) {
                    queue.offer(node.left);
                }

                if (node.right != null) {
                    queue.offer(node.right);
                }
            }

            ans.add(total / num);
        }

        return ans;
    }
}
```