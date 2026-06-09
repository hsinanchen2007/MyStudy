### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/a38e2467e58014409541b07eca281ee46331b0e9c9012b96a16dd33c70853c51-image.png)

**为啥会这么慢呀 QAQ**

### 代码

```java
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new LinkedList();
        combine(result, new LinkedList(), n, k, 1);
        return result;
    }
    private void combine(List<List<Integer>> result, List<Integer> temp, int n, int k, int i){
        if(temp.size() == k){
            result.add(new LinkedList(temp));
            return;
        }
        for(int j = i; j <= n; j ++){
            temp.add(j);
            combine(result, temp, n, k, j + 1);
            temp.remove(temp.size() - 1);
        }
    }
}
```