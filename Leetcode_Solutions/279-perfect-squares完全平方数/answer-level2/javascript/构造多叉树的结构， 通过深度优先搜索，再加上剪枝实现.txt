### 解题思路
构造多叉树的结构， 通过深度优先搜索，再加上剪枝实现。
想象一下 如何从 f（t) 推到f(n), f(n)有几个子节点取决于小于n有多少个完全平方数。见代码如下

另外还可通过递归实现。典型的递归算法
### 代码

```javascript
/**
			 * @param {number} n
			 * @return {number}
			 */
			var numSquares = function(n) {
				//1. 找出小于n的所有完全平方数
				var i = 1;
				var candidates = [];
				while(i * i <= n) {
					candidates.push(i * i);
					i++;
				}

				//2. 对于n，深度优先搜索，树状结构，n的子节点有  n - candidates[0] , ...... , n - candidates[size - 1]
				//2.1 结束条件是，搜到节点为0
				//2.2 每次迭代遍历一层
				//2.3 初始条件是，n为根节点放在queue
				var queue = [];
				queue.push({
					val: n,
					level: 0
				}); //初始是第0层
				var set = new Set();
				set.add(n);
				while(queue.length > 0) {
					var node = queue.shift();
				
					var childrens = findChildren(node);

					//验证退出条件
					var find = null;
					childrens.forEach((node) => {
						if(node.val == 0) {
							find = node.level; //如果该node为0，则表示root可以被从完全平方数累加得到，且完全平方数的数目为node的层级。 
						}
					});
					if (find){
						return find;
					}

					//继续迭代
					childrens.forEach((node) => {
						//避免遍历重复节点
						if (!set.has(node.val)){
							queue.push(node);
							set.add(node.val);
						}
						
					});
				}

				return -1; //没找到解，该题中如果n<1 ,则会出现该返回值

				//找到该节点的子节点， n的子节点有  n - candidates[0] , ...... , n - candidates[size - 1]
				function findChildren(root) {
					var childrens = [];
					for(var i = 0; i < candidates.length; i++) {
						var tempNode = root.val - candidates[i];
						if(tempNode >= 0) {
							childrens.push({
								val: tempNode,
								level: root.level + 1
							}); //层级+1
						}
					}
					return childrens;
				}

			};
```