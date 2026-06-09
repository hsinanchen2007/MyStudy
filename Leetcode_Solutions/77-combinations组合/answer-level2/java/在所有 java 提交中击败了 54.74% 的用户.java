### 解题思路
利用回溯方法。
1.从1-n，递归往list加，当个数为k时返回，返回后把最后一个元素移除。

### 代码

```java
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> r = new ArrayList();
        helper(n, k, r, new ArrayList(), 1);
        return r;
    }
    
    private void helper(int n, int k, List<List<Integer>> r, List<Integer> l, int cur) {
        if(l.size()==k) {
            r.add(new ArrayList(l));
            return;
        }
        
        for(int i=cur;i<=n;i++) {
            l.add(i);
            helper(n, k, r, l, i+1);
            l.remove(l.size()-1);
        }
    }
}
```