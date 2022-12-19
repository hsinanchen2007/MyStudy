### 解题思路
![image.png](https://pic.leetcode-cn.com/a7a15181674da8e2ecbafbe3769833732f26a529573e99963c0c9d8db3dc5344-image.png)
一开始想用序列化，把所有node加上null都放到一个array里面，然后按照1，2，4，8...2^n的规则来分行，感觉越走越绕，看到队列两字才反应过来。

1. 参数root放进队列
2. 队列长度1，一个爷爷出队列，取值，然后两个爸爸进队列
3. 队列长度2，两个爸爸出队列，取值，然后四个儿子进队列
4. 队列长度4，四个儿子出队列，取值，然后八个孙子进队列
5. 队列只出不进了，则子子孙孙有穷尽也。。。


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
 * @return {number[][]}
 */
var levelOrder = function (root) {
    if(!root) return [];
    
    let ret = [],
        retArr = [],
        curr = [],
        que = [root],
        len = 0;

    while (que.length != 0) {
        len = que.length;
        ret = [];
        for (let i = 0; i < len; i++) {
            curr = que.shift();
            ret.push(curr.val);
            if (curr.left) que.push(curr.left);
            if (curr.right) que.push(curr.right);
        }
        retArr.push(ret);
    }

    return retArr;

};
```