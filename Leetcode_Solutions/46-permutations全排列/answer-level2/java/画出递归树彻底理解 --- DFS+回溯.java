# 求解排列的两种思路

有数组 $A = [1, 2, 3]$, 枚举出由数组A元素组成的所有排列.

## 思路1 

- 第0个位置,`3个`元素都可以放置
- 第0个位置放置结束后, 第1个位置, 剩余的`2个`元素可以放置
- 第0个和第1个位置放置结束后, 第2个位位置, 最后一个有`1个`元素放置

总结一下, 就是按每个位置可能放置的元素来进行枚举.

> 简单画一个遍历过程的图如下. 

![image.png](https://pic.leetcode-cn.com/870729487929c26b9d36c998c25c6d52671f78748b44f07f89f10325e6c507b4-image.png)

## 思路2

- 第1个数0可以有`3种`放置方式, 分别为放在第0个位置, 第1个位置, 第2个位置
- 当第1个数放置完成后, 第2个数可以有`2种`放置方式
- 当第1个数和第2个数都放置完成后, 第3个数只有`1种`放置方式.

> 画图如下

![image.png](https://pic.leetcode-cn.com/447999dd1b45b749329cd4ddb4de8a4ecd4cdbc13d117b44e3077f12f18ebe82-image.png)

# 递归树与状态数组

> 思路1 递归树与状态数组

![1.jpeg](https://pic.leetcode-cn.com/4d70a389a7e2e9b8c532b1a581e137dcdbe85aa899e259072ccad62dfa0dc7f6-1.jpeg)

> 思路2 递归树与状态数组

![2.jpeg](https://pic.leetcode-cn.com/28f14ed4379b383a510799dd948c334d518694fbd49e7e047f7a45d6e12426b7-2.jpeg)

# 代码

> 思路1 代码

```java
class Solution {
    
    int n;
    Stack<Integer> path;
    List<List<Integer>> res;
    boolean[] state;
    
    public List<List<Integer>> permute(int[] nums) {
        n = nums.length;
        if(n <= 0) return res;
        
        state = new boolean[n];
        path = new Stack();
        res = new LinkedList();
        
        dfs(nums, 0);
        
        return res;
    }
    
    public void dfs(int[] nums, int pos){
        if(pos == n){
            res.add(new LinkedList(path));
            return ;
        }
        
        for(int i = 0; i < n; i++){
            if(!state[i]){
                // 保存现场
                state[i] = true;
                path.push(nums[i]);
                
                dfs(nums, pos + 1);
                
                // 恢复现场
                path.pop();
                state[i] = false;
            }
        }
    }
}
```

> 思路2 代码

```java
class Solution {
    
    int n;
    Integer[] path;
    boolean[] state;
    List<List<Integer>> res;
    
    public List<List<Integer>> permute(int[] nums) {
        n = nums.length;
        if(n <= 0) return res;
        
        state = new boolean[n];
        res = new LinkedList();
        path = new Integer[n];
        
        dfs(nums, 0);
        
        return res;
    }
    
    public void dfs(int[] nums, int num_pos){
        if(num_pos == n){
            res.add(new ArrayList(Arrays.asList(path)));
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(!state[i]){
                // 保存现声
                state[i] = true;

                path[i] = nums[num_pos];
                dfs(nums, num_pos + 1);

                // 恢复现场
                state[i] = false;
            }
        }
        
    }
}
```
