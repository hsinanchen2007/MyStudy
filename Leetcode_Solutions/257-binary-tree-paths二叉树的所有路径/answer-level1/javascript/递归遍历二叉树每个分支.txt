### 解题思路
看代码后面的注释会比较容易理解

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
 * @return {string[]}
 */
var binaryTreePaths = function(root) {
    if(!root)return []; //空节点，直接返回
    
    let res=[];
    function add(node, arr){
        arr.push(node.val); //把当前节点的值放进一个临时数组，原因是需要追溯整条线路
        if(node.left){
            add(node.left, arr); //如果有左节点，递归调用，酱紫就可以遍历全部左边的节点（线路）
        }
        if(node.right){
            add(node.right, arr); //同理，获取右边线路
        }
        if(!node.left && !node.right){
            res.push([...arr]) //如果是叶子节点（没有子结点），把线路拷贝一份出来，放进总的线路数组里面
        };
        arr.pop(); //把临时数组里面的元素弹出，是为了一层一层退出递归栈时清空里面的每层的记录
    }
    add( root, []);
    res = res.map(e=>e.join('->')); //把最后得到的路线数组，用->串起来
    return res;
};
```