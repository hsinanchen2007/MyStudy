> 解题

在78.子集这题的基础上进行剪枝即可. 记得要先将数组排序.

> 剪枝图解


![image.png](https://pic.leetcode-cn.com/4495584e0c52dd3f472cf5b764065a2a909ed53ac517198a8be7dd447e86a55d-image.png)


> 代码
```java
class Solution {
    
    
    int n;
    List<List<Integer>> result = new LinkedList();
    Stack<Integer> path = new Stack();
    // 加上剪枝操作, 相同层, 如果当前元素与上一个元素相同, 则跳过不遍历以实现剪枝.
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        if(nums.length <= 0) return result;
        n = nums.length;
        
        // 先排序, 这是很重要的.
        Arrays.sort(nums);
        
        dfs(nums, 0);
        
        return result;
    }
    
    public void dfs(int[] nums, int start){
        result.add(new LinkedList(path));
        
        for(int i = start; i < n; i++){
            if((i-1)>=start && nums[i-1] == nums[i]) continue;
            path.push(nums[i]);
            dfs(nums, i+1);
            path.pop();
        }
        
    }
}
```

> 截止到2019-10-02

![image.png](https://pic.leetcode-cn.com/7918282fd4fd79b195886820410d96976e9940486cb6f1201eaa81ebe6738ce8-image.png)
