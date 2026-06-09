### 解题思路
BFS以及DFS

### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumOfLeftLeaves = function(root) {
    //1.BFS
		function bfs(root){
		    if(!root){
		        return 0;
			}
		    let queue = [root],res = 0;
		    while(queue.length > 0){
		        let temp = queue.shift();
		        if(temp.left) {
		            res += ( temp.left.left ||temp.left.right ) ?0:temp.left.val;
		            queue.push(temp.left);
		        };
		        if(temp.right){
		            queue.push(temp.right);
				}
			}
			return res;
		}
		//2.DFS
		function dfs(root){
		    let stack = [], res = 0,cur = null;
		    if(!root){
		        return 0;
			}else{
                stack.push(root)
                while(stack.length > 0){
                    cur = stack.pop();
                     if(cur.right){
                        stack.push(cur.right)
					}
                    if(cur.left){
                        stack.push(cur.left);
                        res += ( cur.left.left ||cur.left.right ) ?0:cur.left.val;
					}
                }
			}
			return res;
		}
		let res =bfs(root);
		return res;
};
```