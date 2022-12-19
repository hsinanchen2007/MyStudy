### 方法一：图的思想
将二叉树看作一个有向图，由父节点指向左右节点，因此只有根节点的入度为 $0$，其他节点的入度为 $1$。

![幻灯片1.JPG](https://pic.leetcode-cn.com/f1f3b3b42f5008e34f4066c4391b7ac5037cf7ee2b2aab31e0fd41e0a20c8791-%E5%B9%BB%E7%81%AF%E7%89%871.JPG)

如果有节点的入度大于 $1$，说明该节点有多个父节点，则不是二叉树：

![幻灯片2.JPG](https://pic.leetcode-cn.com/2a9882598ad53ddacfd2a0d8204f83fb7dff007816655c0faee68466e3efe972-%E5%B9%BB%E7%81%AF%E7%89%872.JPG)

#### 算法
1. 维护一个长度为 $n$ 的数组 `in_counts` 表示各节点的入度，初始化为 $0$；
2. 由于题目中节点从 $0$ 到 $n - 1$ 编号，因此可用 `in_counts[编号]` 该节点的入度。分别遍历 `leftChild` 和 `rightChild` 记录入度；
3. 遍历 `in_counts`，记录入度为 $0$ 的个数 `count_in0` 和 入度大于 $1$ 的个数 `count_in2`，返回结果。

#### 代码
```python []
class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        in_counts = [0 for _ in range(n)]
        for node in leftChild:
            if node != -1:
                in_counts[node] += 1
        for node in rightChild:
            if node != -1:
                in_counts[node] += 1
        count_in0 = 0
        count_in2 = 0
        for in_count in in_counts:
            if in_count == 0:
                count_in0 += 1
            if in_count > 1:
                count_in2 += 1
        return count_in0 == 1 and count_in2 == 0
```

```C++ []
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> in_counts (n, 0);
        for(int node:leftChild)
            if(node != -1) in_counts[node]++;
        for(int node:rightChild)
            if(node != -1) in_counts[node]++;
        
        int count_in0 = 0;
        int count_in2 = 0;
        for(auto in_count:in_counts){
            if(in_count == 0)count_in0 ++;
            if(in_count > 1)count_in2 ++;
        }
        return count_in0 == 1 && count_in2 == 0;  
    }
};

```

#### 复杂度分析
- 时间复杂度：$O(n)$。
- 空间复杂度：$O(n)$。

### 方法二：数学
>本方法为周赛巨佬的方法，能想到此方法可见其功底扎实，值得我们学习。

以满二叉树为例，我们知道一个深度为 $n$ 的二叉树有如下特点：
- 一共有 $2^n-1$ 个节点；
- 深度为 $n$ 处有 $2^{n-1}$ 个叶子节点；
- 叶子节点下面的节点为题目中的 $-1$ 节点，深度为 $n+1$，个数为 $2^{(n+1)-1}=2^n$  个节点。

所以 $-1$ 节点的个数比总节点个数多 $1$。

![5170.jpg](https://pic.leetcode-cn.com/4529e5d73ac73f1b2043f0955f6d69c850bb57ced6d0b33f49b136c27d74bd39-5170.jpg)

#### 代码
```python []
class Solution(object):
    def validateBinaryTreeNodes(self, n, leftChild, rightChild):
        return (leftChild + rightChild).count(-1) == n + 1
```
#### 复杂度分析
- 时间复杂度：$O(n)$。
- 空间复杂度：$O(1)$。