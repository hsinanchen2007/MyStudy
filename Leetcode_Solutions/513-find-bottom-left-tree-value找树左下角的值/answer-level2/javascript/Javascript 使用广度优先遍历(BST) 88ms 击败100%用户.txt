>  整体思路是使用层序遍历， 然后根据最后一层的元素中从左到右找到有效值


![image.png](https://pic.leetcode-cn.com/91f873140fa97424fe7b08be3af96901e3345dff46a959ac0ce0d8e702d6efa0-image.png)

- 第一步: 使用递归广度优先遍历
- 第二步: 根据遍历的结果，通过树的最后一层，从左到右找第一个有效值并返回
```
var findBottomLeftValue = function (root) {
	let arr = [], tmp = []

	bst(root, 0)
	// 广度优先遍历
	/**
	 * @param {object} tree // 树
	 * @param {number} i // 深度
	 * @return {number}
	 */
	function bst(tree, i) {
		if (!tree) {
			arr[i] = arr[i] || []
			arr[i].push(null)
			return
		}

		arr[i] = arr[i] || []
		arr[i].push(tree.val)

		bst(tree.left, i + 1)
		bst(tree.right, i + 1)
	}

  // 上面的递归因为在终止条件时候添加了null，所以会多出来一组null，在这里通过length - 2 获取树的最后一层
	tmp = arr[arr.length - 2]

  // 寻找从左到右第一个不为null的元素,并返回
	for (let i = 0; i < tmp.length; i++) {
		if (tmp[i] !== null) {
			return tmp[i]
		}
	}
};
```