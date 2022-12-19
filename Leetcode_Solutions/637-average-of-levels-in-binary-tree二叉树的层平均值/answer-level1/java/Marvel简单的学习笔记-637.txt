### 解法一：BFS
最直观的思路，广度优先搜索，即层序遍历。
以层为单元，逐层循环，一次处理整层的顶点。
根结点入队后，只要队列不空，就记录队列中顶点的数量，此后仅对该数量的顶点出列，并将它们的子结点入列。
这样，每轮循环，队列中顶点的数量表示的就是当前层顶点的数量，计算层平均值即可。

代码：
```java
class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> res = new LinkedList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty())
        {
            int sz = q.size();
            double sum = 0;
            for(int i = 0; i < sz; i++)
            {
                TreeNode cur = q.poll();
                sum += cur.val;
                if(cur.left != null)    q.offer(cur.left);
                if(cur.right != null)   q.offer(cur.right);
            }
            res.add(sum / sz);
        }
        return res;
    }
}
```

### 解法二：DFS
递归的时候多使用一个参数记录当前层号。
同时，使用两个实例变量List，一个记录每层结点数，一个记录每层结点值之和。
每访问一个结点，就更新该层结点数与结点值之和。
递归结束后，通过结点值之和与结点数计算层平均值。

代码：
```java
class Solution {
    private List<Double> ans;
    private List<Integer> sz;
    public List<Double> averageOfLevels(TreeNode root) {
        ans = new LinkedList<>();
        sz = new LinkedList<>();
        dfs(root, 1);//层号从1开始
        for(int i = 0; i < ans.size(); i++)
            ans.set(i, ans.get(i) / sz.get(i));
        return ans;
    }
    private void dfs(TreeNode root, int layer) {
        if(root == null)    return;
        if(sz. size() < layer)//意味着第一次到达该层
        {
            sz.add(1);
            ans.add((double)root.val);
        }
        else
        {
           sz.set(layer-1, sz.get(layer-1) + 1);
           ans.set(layer-1, 1.0 * ans.get(layer-1) + root.val);
        }
        dfs(root.left, layer + 1);
        dfs(root.right, layer + 1);
    }
}
```