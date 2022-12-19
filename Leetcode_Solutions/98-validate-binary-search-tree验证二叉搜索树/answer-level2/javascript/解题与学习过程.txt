#### 错误思路：在第一个正确解答的版本出来之前，我也陷入了官方解答所说的直觉中`直觉 乍一看，这是一个平凡的问题。只需要遍历整棵树，检查 node.right.val > node.val 和 node.left.val < node.val 对每个结点是否成立。` 以这样的思维方式连续解答错误了两次，然后才意识到这个问题并转向其他解答方式
```javascript []
var isValidBST = function(root) {
  if (!root) return true;
  if (root.left && root.val <= root.left.val) return false
  if (root.right && root.val >= root.right.val) return false;
  return isValidBST(root.left) && isValidBST(root.right);
};
```

### 第零版，思路是递归将每个节点树转成数组并同时比较节点值是否符合条件（即数组每一项的值应该比它前面任一项的值大）。我认为这里其实可以算是正确解答了，但是可能因为leetcode后台没有正确地将`[0]`转为boolean值true，所以导致最后一个测试用例没有通过
![火星图片_20190810_155606.png](https://pic.leetcode-cn.com/3c03be0d17591105f197506bbeba8095460e8998f6f4556f02d10ac5566885ae-%E7%81%AB%E6%98%9F%E5%9B%BE%E7%89%87_20190810_155606.png)

```javascript []
var isValidBST = function(root) {
  if (!root) return true;
  if (!root.left && !root.right) return [root.val];

  const left = root.left ? isValidBST(root.left) : [];
  if (!left) return false;
  const right = root.right ? isValidBST(root.right) : [];
  if (!right) return false;

  if (left.length && root.val <= left[left.length - 1]) return false;
  if (right.length && root.val >= right[0]) return false;
  return left.concat(root.val, right);
};
```


## 第一版，鉴于第零版的失败，只好暂时放弃一边生成数组一边比较，而是先将二叉树完全转为数组后再比较值是否符合条件，但是空间占用稍大
> 108ms,41.8M。
```javascript []
var isValidBST = function(root) {
  const arr = tree2Arr(root);
  for (let i = 0; i < arr.length - 1; i++) {
    if (arr[i + 1] <= arr[i]) return false;
  }
  return true;
};

function tree2Arr(root) {
  return root ? tree2Arr(root.left).concat(root.val, tree2Arr(root.right)) : [];
}
```

## 第一版改进型，还是在构造数组的同时进行校验效率更高，在tree2Arr方法的返回中添加一个标记来标识是否通过检查，没通过检查就不再继续构造了。
> 104ms,38.9M。
```javascript []
var isValidBST = function(root) {
  const res = tree2Arr(root);
  return res.valid;
};

function tree2Arr(root) {
  if (!root) return { valid: true, arr:[] };
  if (!root.left && !root.right) return { valid: true, arr: [root.val] };
  const left = root.left ? tree2Arr(root.left) : { valid: true, arr: [] };
  if (!left.valid) return { valid: false };
  if (left.arr.length && root.val <= left.arr[left.arr.length - 1]) return { valid: false };

  const right = root.right ? tree2Arr(root.right) : { valid: true, arr: [] };
  if (!right.valid) return { valid: false };
  if (right.arr.length && root.val >= right.arr[0]) return { valid: false };
  return { valid: true, arr: left.arr.concat(root.val, right.arr) };
}
```
---
#### 接下来自己一下子没想到啥好的思路了，所以转向学习大佬的思路和方法
## 第二版，先在题解栏中搜索看到本题唯一一个JavaScript题解，思路很不错，具体代码不贴了，详见 [题解](https://leetcode-cn.com/problems/validate-binary-search-tree/solution/javascriptdi-gui-jie-fa-by-zmen)
> 104ms,37.5M。

## 第三版，在《学习JavaScript数据结构与算法（第三版）》 10.4 树的遍历 章节中学习到了中序遍历方法，如果是按照中序遍历顺序遍历该二叉树的话那么后一个访问的节点值一定比前一个访问的节点值大，很直观，非常适合用来解这道题。使用数组或者对象来辅助校验
![未命名文件 (1).jpg](https://pic.leetcode-cn.com/eb514daadf9ba713243364f2658ccaed2f711415641d9df24c21d35d3b84237d-%E6%9C%AA%E5%91%BD%E5%90%8D%E6%96%87%E4%BB%B6%20\(1\).jpg)


> arr → 88ms,37.3M。 obj → 104ms.37.9M。
```javascript []
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isValidBST = function(root, arr = []) {
  if (!root) return true;
  return isValidBST(root.left, arr) && compareAndPush(root.val, arr) && isValidBST(root.right, arr);
};

function compareAndPush (val, arr) {
  if (arr.length) if (arr[arr.length - 1] >= val) return false
  arr.push(val);
  return true;
}
```
```javascript Obj []
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isValidBST = function(root, obj = {}) {
  if (!root) return true;
  return isValidBST(root.left, obj) && compareAndPush(root.val, obj) && isValidBST(root.right, obj);
};

function compareAndPush (val, obj) {
  if (obj.max + '') if (obj.max >= val) return false
  obj.max = val;
  return true;
}
```
```javascript []
// 该代码理论上可行，但可能是因为使用了全局变量，在测试用例输入为 [0] 时会产生错误输出。
// 刚好在测试过程中发现了这个情况，而且本人一般遵循函数式编程风格，不修改函数外变量状态是函数式编程很重要的一个特点
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isValidBST = function(root) {
  if (!root) return true;
  return isValidBST(root.left) && checkNode(root.val) && isValidBST(root.right);
};

function checkNode (val) {
  if (temp34567 >= val) return false
  temp34567 = val;
  return true;
}

let temp34567 = -Number.MAX_VALUE;
```

## 第四版，学习官方题解，官方题解方法一的思路也是很巧妙的。因为在每个二叉搜索树中，根节点的值一定比左子树所有节点的值大且一定比右子树所有节点的值小。巧妙的将这些上下限值通过函数递归传给子节点来进行比较。顺便发现了该方法的遍历顺序就是先序遍历
![未命名文件.jpg](https://pic.leetcode-cn.com/8c36ce894ab3cc0f5fddcf44b322f08c233a82734b4cc8bcba06848028adbd50-%E6%9C%AA%E5%91%BD%E5%90%8D%E6%96%87%E4%BB%B6.jpg)

> 96ms,37.2M。
```javascript []
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} pre 当前节点值的下限
 * @param {TreeNode} next 当前节点值的上限
 * @return {boolean}
 */
var isValidBST = function(root, pre = null, next = null) {
  if (!root) return true;
  // 在这里打印日志可以很好的观察到遍历顺序以及每个节点到底与哪些上下限进行了比较
  // console.log(root && root.val, pre && pre.val, next && next.val);
  if (pre && pre.val >= root.val) return false;
  if (next && next.val <= root.val) return false;
  return isValidBST(root.left, pre, root) && isValidBST(root.right, root, next);
};
```
