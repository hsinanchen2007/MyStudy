层次遍历，模拟2个队列，一个用来存储每个层级的节点，一个用来存储对应节点的编号。
节点编号从上到下，从0开始，规则：左子节点编号 = 父节点编号 * 2 + 1，右子节点编号 = 父节点编号 * 2 + 2；
如图：![Snip20190907_10.png](https://pic.leetcode-cn.com/19da5ab89bd38bc8f8ef5838d8fbdb76108fb553a05322dc6527f4a25be8fb94-Snip20190907_10.png)
```
/**
 * @param {TreeNode} root
 * @return {number}
 * 第一种方式：递归
 * 执行用时 :84 ms, 在所有 JavaScript 提交中击败了100.00%的用户
 * 内存消耗 :36.7 MB, 在所有 JavaScript 提交中击败了37.50%的用户
 */
var widthOfBinaryTree = function(root) {

    if (!root) return 0;

    //queue存储节点，numArr存储节点对应的索引位置
    var queue = [root], numArr = [0], maxWidth = 1;

    while (queue.length) {
        //tempQueue存储每一层级所有的节点，tempNumArr存储对应节点的索引位置
        var tempQueue = [], tempNumArr = [];
        while (queue.length) {
            var node = queue.shift(), num = numArr.shift(); //取出栈底节点和索引

            if (node.left) {
                tempQueue.push(node.left);
                tempNumArr.push(num * 2 + 1);
            }
            if (node.right) {
                tempQueue.push(node.right);
                tempNumArr.push(num * 2 + 2);
            }
        }
        var tempWidth = 0;
        //计算tempNumArr中存储的这一层的宽度, 最后一位元素存储这一层级最大宽度的索引
        if (tempNumArr.length) {
            tempWidth = tempNumArr[tempNumArr.length - 1] - tempNumArr[0] + 1;
        }
        if (tempWidth > maxWidth) {
            maxWidth = tempWidth;  //更新最大宽度
        }

        //开始下一个层级的宽度计算
        queue = tempQueue;
        numArr = tempNumArr;
    }

    return maxWidth;
};

      
```
