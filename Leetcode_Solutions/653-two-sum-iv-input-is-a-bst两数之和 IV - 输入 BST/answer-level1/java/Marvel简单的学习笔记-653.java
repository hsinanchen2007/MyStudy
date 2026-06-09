### 解法一：HashSet
dfs遍历树的每个结点，查询哈希表内是否含有与当前结点值加和为目标值的元素，有则返回ture，否则把当前结点值存入哈希表。然后分别到左右子树中递归查询。

时间复杂度：$O(n)$。
空间复杂度：$O(n)$，最坏情况下，HashSet空间复杂度$O(n)$，递归需要的栈空间$O(n)$。

代码：
```java
class Solution {
    private Set<Integer> set = new HashSet<>();
    public boolean findTarget(TreeNode root, int k) {
        if(root == null)    
            return false;
        if(set.contains(k - root.val))  
            return true;
        set.add(root.val);
        return findTarget(root.left, k) || findTarget(root.right, k);
    }
}
```

### 解法二：中序遍历+双指针
BST的中序遍历是升序的，因此可将中序遍历的结果存到一个list中，问题就转变为在有序的数列中寻找两数之和。
而双指针可以很好地利用有序性。

时间复杂度：$O(n)$。
空间复杂度：$O(n)$，List需要$O(n)$的空间，递归调用需要$O(n)$的栈空间。

代码：
```java
class Solution {
    public boolean findTarget(TreeNode root, int k) {
        List<Integer> list = new ArrayList<>();
        inOrder(root, list);
        int lo = 0, hi = list.size() - 1;
        while(lo < hi)
        {
            int sum = list.get(lo) + list.get(hi);
            if(sum < k)         lo++;
            else if(sum > k)    hi--;
            else                return true;
        }
        return false;
    }
    private void inOrder(TreeNode root, List<Integer> list) {
        if(root == null)    return;
        inOrder(root.left, list);
        list.add(root.val);
        inOrder(root.right, list);
    }
}
```