
#### 方法一
**【历史重难点题目】**
* [历史重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)

**【思路】**
* 一个爷爷结点，有两个儿子结点，有四个孙子结点。爷爷节点获取到最大的偷取的钱数呢？爷爷偷了儿子就不能偷，儿子偷了爷爷和孙子就不能偷，所以有如下两种方法
1. 偷4个孙子的钱 + 偷爷爷的钱
2. 偷两个儿子的钱
* 遍历每个结点，将以上两个结果取最大，就行了


**【代码】**
```java
public int rob(TreeNode root) {
    if (root == null) 
        return 0;

    int money = root.val;
    if (root.left != null) 
        money += (rob(root.left.left) + rob(root.left.right));
    if (root.right != null) 
        money += (rob(root.right.left) + rob(root.right.right));
    
    return Math.max(money, rob(root.left) + rob(root.right));
}
```


**【备注】**
* 该方法计算了很多重复值，**可以用一个数据结构，将计算过的金额数存下来**

#### 方法二
[感谢最高亮同学的回答](https://leetcode-cn.com/problems/house-robber-iii/solution/san-chong-fang-fa-jie-jue-shu-xing-dong-tai-gui-hu/)

**【核心思想】**
* 一维数组用一维的dp存，这里用map存

**【代码】**
```java
public int rob(TreeNode root) {
    HashMap<TreeNode, Integer> map = new HashMap<>();
    return help(root, map);
}

int help(TreeNode root, HashMap<TreeNode, Integer> map) {
    if (root == null) return 0;
    if (map.containsKey(root)) return map.get(root);
    int money = root.val;

    if (root.left != null) {
        money += (help(root.left.left, map) + help(root.left.right, map));
    }
    if (root.right != null) {
        money += (help(root.right.left, map) + help(root.right.right, map));
    }
    int result = Math.max(money, help(root.left, map) + help(root.right, map));
    map.put(root, result);
    return result;
}
```


#### 方法三
**【核心思想】**
* 每个节点可选择偷或者不偷两种状态，相连节点不能一起偷
* 当前节点选择偷时，那么两个孩子节点就不能选择偷了
* 当前节点选择不偷时，两个孩子节点只需要拿最多的钱出来就行(两个孩子节点偷不偷没关系)
* 当前节点选择不偷: `当前节点能偷到的最大钱数 = 左孩子能偷到的钱 + 右孩子能偷到的钱`
* 当前节点选择偷: `当前节点能偷到的最大钱数 = 左孩子选择自己不偷时能得到的钱 + 右孩子选择不偷时能得到的钱 + 当前节点的钱数`

**【思路】**
* `result[0]`存储当前节点选择不偷时获得的最大的钱
* `result[1]`存储当前节点选择偷时获得的最大的钱
* `left[]`存储左儿子结点的情况
* `right[]`存储右儿子结点的情况
* `result[0] = Math.max(left[0], left[1]) + Math.max(right[0], right[1])`
* `result[1] = left[0] + right[0] + root.val`
* 
**【代码】**
```java
public int rob(TreeNode root) {
    int[] result = help(root);
    return Math.max(result[0], result[1]);
}

public int[] help(TreeNode root) {
    if (root == null) return new int[2];
    int[] result = new int[2];

    int[] left = help(root.left);
    int[] right = help(root.right);

    result[0] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
    result[1] = left[0] + right[0] + root.val;

    return result;
}

```

**【关注微信公众号，带你拿大厂offer】**
![logo_gif.gif](https://pic.leetcode-cn.com/3ce7ebde811bdc9a12d80be1f7b2190e587135fd2c957d28b079ad08cb0acb79-logo_gif.gif)
