BFS 广度优先搜索，是一种邻近遍历,它总是先搜索最靠近根节点的节点。换句话讲，BFS就是按照层进行搜索，一层一层的遍历。
这种越靠近根节点越优先搜索到的顺序，很适合使用队列。队列是FIFO，先进先出的数据结构。越靠近根节点的先进队列，以此递进。
所以使用队列完成BFS的模板可以总结为：

```
//由于js 没有队列的数据结构，可以使用数组完成队列
let queue = [];
let result =[];
queue.push(root);// push入队列

while(queue.lenght){ //不断遍历队列，把所有符合要求的节点都遍历到
    for(let i = queue.lenght; i > 0 ; i-- ){ //按层遍历，如果需要计算层数，计算最短路径，最优解，需要按层遍历，如果不需要，则可以直接遍历队列
        let cur = queue.shift(); //借助数组的shift 弹出队列的头元素，实现先进先出
        let nerbo = getNext(cur); //得到cur节点的邻居符合要求的节点，因题而已，一般我们也会定义viewed数组，来标记访问过的节点，避免循环遍历和重复遍历
        for x of nerbo:
            queue.push(x);
    }
}

```


```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var levelOrder = function(root) {
    if(root === null)return [];
    let queue = [];
    let result =[];
    queue.push(root);
    while(queue.length > 0){
        // let temp = [];
        // let size = queue.length;
        for(let i = queue.length; i > 0; i--){
            let cur = queue.shift();
            // console.log(cur.val,i);
            result.push(cur.val);
            if(cur.left !==null){
                queue.push(cur.left);
            }
            if(cur.right !== null){
                queue.push(cur.right);
            }
        }

    }
    return result;

};
```
