## 解题方案

### 思路

- 标签：回溯与剪枝
- n 表示范围为 1...n，balance 表示剩余空间，start 表示开始位置，list 为回溯列表
- 判断 balance == 0，如果为 0 则代表 list 中已经存入 k 个数，拷贝 list 存入结果 ans 中
- 如果不为 0，从 start 位置开始递归调用，现将当前位置数据加入 list 中，并进入下一层，等待返回后将本层加入的数据移除，**本质就是树的构造过程**
- 其中循环结束条件默认为最大值到 n，这里可以优化进行剪枝，比如 `n=4，k=3` 时，如果列表从 `start=3` 也就是 `[3]` 开始，那么该组合一定不存在，因为至少要 `k=3` 个数据，所以剪枝临界点为 `n-balance+1`

### 代码

```Java []
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    public List<List<Integer>> combine(int n, int k) {
        getCombine(n, k, 1, new ArrayList<>());
        return ans;
    }
    
    public void getCombine(int n, int k, int start, List<Integer> list) {
        if(k == 0) {
            ans.add(new ArrayList<>(list));
            return;
        }
        for(int i = start;i <= n - k + 1;i++) {
            list.add(i);
            getCombine(n, k - 1, i+1, list);
            list.remove(list.size() - 1);
        }
    }
}
```

### 画解


<![frame_00001.png](https://pic.leetcode-cn.com/56fc86462db842d44a7e3e7983a7b5b01c8c25d106a9f4296c500d6d84478d74-frame_00001.png),![frame_00002.png](https://pic.leetcode-cn.com/e4bec9a5d9a76fa4e369ce9bd1422c606155d92fdf81014426b41f5479c7faff-frame_00002.png),![frame_00003.png](https://pic.leetcode-cn.com/4fbddb60995860f7b4c74f915cf220ce164ee4043b1a60a635d22f969c9c0dbb-frame_00003.png),![frame_00004.png](https://pic.leetcode-cn.com/df42c567454065d283b99fb51ce74ba780c14e2193873b734a5c4266567465a8-frame_00004.png),![frame_00005.png](https://pic.leetcode-cn.com/bf789bff2b0121f69ff9dc9297a55551bfa79e600224d32921e37954ea0dec36-frame_00005.png)>

点击我的头像加关注，和我一起打卡天天算法