### 解题思路
此处撰写解题思路
1.思路主要是利用队列，将二叉树的每个根节点的子节点压入队列，这样每次将每一层的所有节点存入队列中。
2.然后每一次迭代的时候，每次取出一个节点，然后再把这一个节点的孩子的节点存入队列中。
3.每次进入队列的时候，会给一个父节点下的孩子节点赋予一样的值，然后压入map中
4.这里在每一层检索是否满足要求的节点，不满足清空，满足返回。


老铁觉得好的话就麻烦点个赞吧，写题解实属不易！！！！
![BFS进入Queue的序列图.png](https://pic.leetcode-cn.com/9927a728158735eac1066d2e345c0f7b67d63acfb79c47b7d5633ff632f93885-BFS%E8%BF%9B%E5%85%A5Queue%E7%9A%84%E5%BA%8F%E5%88%97%E5%9B%BE.png)
### 代码

```javascript

/**
 * @param {TreeNode} root
 * @param {number} x
 * @param {number} y
 * @return {boolean}
 */
var isCousins = function (root, x, y) {
    let queue = [root]; //将整个二叉树放进队列里
    let mymap = new Map();//这里定义一个map主要是用来存放所有二叉树数值的
    var j = 0;
    while (queue.length) 
    {
        let len = queue.length;//每次计算队列长度，该长度为每一层的节点数

        for (let i = 0; i < len; i++) 
        {
            j++;//该计数器主要用来保证不再同一父节点的值不相同
            let node = queue.shift();//每次截取根节点
            if (node.left && node.right) //如果该节点有左右孩子，将孩子放进队列里，并且将每个孩子的value设置为一样，存入Map中
            {
                queue.push(node.left, node.right);
                mymap.set(node.left.val, j);
                mymap.set(node.right.val, j);
                continue;
            }

            else if (node.left != null) //如果有左节点，则将其存入队列里，并且给其设置Map值，存入map中
            {
                queue.push(node.left);
                mymap.set(node.left.val, j);
            }

            else if (node.right != null) //同上
            {
                queue.push(node.right);
                mymap.set(node.right.val, j);

            }
        }
        if ((mymap.has(x) == true && mymap.has(y) == true) && (mymap.get(x) != mymap.get(y))) //判断同一层是否有兄弟节点
        {
            return true;
        }

        else
        {
            mymap.clear();//没有兄弟节点，清空map,用于下一层的节点的存入
        }
       
    }
    return false;
};
```