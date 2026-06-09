```text
该题的核心思想还是DFS，下图是部分递归树。
```

![未命名文件 (1).png](https://pic.leetcode-cn.com/1e53e658aabf0899f6675eb8125352d1cb5c224b8eaf85aec1662bf2c471cb32-%E6%9C%AA%E5%91%BD%E5%90%8D%E6%96%87%E4%BB%B6%20\(1\).png)


```java
class Solution {
    
    //dfs
    public List<Integer> lexicalOrder(int n) {
        
        List<Integer> list = new ArrayList<>(n);
        for (int i = 1; i < 10; i++) {
            lexicalOrder(list, n, i);
        }
        
        return list;
    }
    
    private void lexicalOrder(List<Integer> list, int n, int i) {
        
        // return condition
        if (i > n) {
            return;
        }
        
        list.add(i);
        i = i * 10;
        
        // optimize
        if (i > n) {
            return;
        }
        
        for (int j = 0; j < 10; j++) {
            
            // optimize
            if (i + j > n) {
                break;
            }
            
            lexicalOrder(list, n, i + j);
        }
    }
}
```


