> 解题

1. 顺序!!!最重要. 
2. $A = [1,2,3]$
3. 从`1`(位置为0)开始放入栈中, DFS进入下一层时, 遍历的位置应该是`1`后面的元素(位置为1).
4. 每一层都是一个子集, 因此每深入一层都需要将子集存入到结果中. 

> 代码

```java
class Solution {
    
    int n;
    
    Stack<Integer> path = new Stack();
    List<List<Integer>> result = new LinkedList();
    
    public List<List<Integer>> subsets(int[] nums) {
        n = nums.length;
        if(n <= 0) return result;
        
        dfs(nums, 0);
        
        return result;
    }
    
    public void dfs(int[] nums, int start){
        // 每一层都是一个方案, 需要存入到result中
        result.add(new LinkedList(path));
        for(int i = start; i < n; i++){
            path.push(nums[i]);
            dfs(nums, i+1);
            path.pop();
        }
    }
}
```

> 通过二进制位运算求解集合

1. $A = [1,2,3,4]$
2. 有数学常识可知共有 $2^4=16$ 个子集
3. 这15个子集有一个特点, 每个数的二进制位为1时, 这一位对应的元素即为子集中的元素. 仔细思考下在这张图, 很快会得到这个结论. 

|index|3|2|1|0||
|:-:|:-:|:-:|:-:|:-:|:-:|
|数组| **4** | **3** |**2** | **1**| 对应集合|
|0|0|0|0|0| []
|1|0|0|0|***1***|[1]
|2|0|0|***1***|0|[2]
|3|0|0|1|***1***|[1,2]
|4|0|***1***|0|0|[3]
|5|0|***1***|0|***1***|[3,1]
|6|0|***1***|***1***|0|[3,2]
|7|0|***1***|***1***|***1***|[3,2,1]
|8|***1***|0|0|0|[4]
|9|***1***|0|0|***1***|[4,1]
|10|***1***|0|***1***|0|[4,2]
|11|***1***|0|***1***|***1***|[4,2,1]
|12|***1***|***1***|0|0|[4,3]
|13|***1***|***1***|0|***1***|[4,3,1]
|14|***1***|***1***|***1***|0|[4,3,2]
|15|***1***|***1***|***1***|***1***|[4,3,2,1]

> 代码

```java
class Solution {
    
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new LinkedList();
        if(nums.length <= 0) return result;
        
        int n = nums.length;
        
        // 1 << n 是根据数组中的元素个数计算出子集的个数为 1<<n - 1; 这里开始遍历每一个数
        for(int i = 0; i < (1 << n); i++){
            // 一个数对应一个集合, 因此需要一个栈来存储
            Stack<Integer> path = new Stack();
            for(int j = 0; j < n; j++){
                if(((i >> j) & 1) == 1)
                    path.push(nums[j]);
            }
            // 每个数的各位二进制遍历结束后, 把该数对应的集合添加到结果集中
            result.add(new LinkedList(path));
        }
        
        return result;
    }
    
}
```

> 截止到2019-10-02

![image.png](https://pic.leetcode-cn.com/8ea24b430cc0db24502be3ba09ee9a581a825acc2d63e23713fbf96d84b57a07-image.png)
