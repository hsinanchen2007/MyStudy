> 解题

1. 按深度遍历, 深度由变量k控制
2. 深度>k, 结束不再继续深入; 否则继续深入
3. 按$0,1,2 \cdots n$的顺序遍历, 每个数深入k层.

> 图解如下

![image.png](https://pic.leetcode-cn.com/f951c88e551f68180e84c0f9d4dd11387bfc17862df45ff02de772363f90073e-image.png)


> 代码

```java
class Solution {
    List<List<Integer>> result = new LinkedList();
    Stack<Integer> path = new Stack();
    
    public List<List<Integer>> combine(int n, int k) {
        if(n <= 0 || k <= 0) return result;
        
        dfs(n, k, 0);
        
        return result;
    }
    
    public void dfs(int n , int k, int start){
        if(path.size() == k) {
            result.add(new LinkedList(path));
            return;
        }
        
        for(int i = start; i < n; i++){
            if(path.size() > k) continue;
            path.push(i+1);
            dfs(n, k, i + 1);
            path.pop();
        }
    }
}
```

> 截止2019-10-02

字节跳动是真爱考这类题啊.

![image.png](https://pic.leetcode-cn.com/a0e2dacd10f8cab479dfba64aff3dea1c12b4749876a9b2b832dff70cd7231fa-image.png)

