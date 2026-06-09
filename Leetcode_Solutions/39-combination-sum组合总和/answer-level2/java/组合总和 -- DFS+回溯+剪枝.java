> 解题

1. 画递归树是王道 
2. 先将candidates排序(升序)
3. 按candidates数组的顺序遍历每一个数(每一个数都是一条edge),以及对应的target. 每深入一层, target = target - nums[i]; 且将当前层节点的edge值所在索引返回.
4. 比较当前节点的edge与下一层的edge大小, 由于数组是排过序的, 所以`当前节点所在edge值必然大于或等于上一层的edge值`, 具体情况可以看一下手绘图. 
5. 当某个节点的值 $<0$ 时, 直接返回; 当某个节点的值 $==0$ 时, 将对应的通路添加到结果集中.

> 手绘图解

![image.png](https://pic.leetcode-cn.com/5b5ef0526401a9db75c95c90fdebdc429958c6281080041ed72d4f4fbcaa42ec-image.png)


> 代码

```java
class Solution {
    
    int n;
    List<List<Integer>> result = new LinkedList();
    Stack<Integer> path = new Stack();
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if(candidates.length <= 0) return result;
        
        n = candidates.length;
        
        Arrays.sort(candidates);
        
        dfs(candidates, target, 0);
        
        return result;
    }
    
    public void dfs(int[] nums, int target, int upper_index){
        if(target < 0 ) return;
        if(target == 0) {
            result.add(new LinkedList(path));
            return;
        }
        
        // 遍历数组, 数组中的每一个值对应一条edge
        for(int i = 0; i < n; i++){
            if(nums[upper_index] > nums[i]) continue;
            
            path.push(nums[i]);
            dfs(nums, target-nums[i], i);
            path.pop();
            
        }
    }
}
```

> 截止2019-10-02

![image.png](https://pic.leetcode-cn.com/a60513b11d10042b61dd3b2bdd00f49fff29436affe9e62311ef92fb5d543294-image.png)
