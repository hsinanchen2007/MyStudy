* 执行用时 :84 ms, 在所有 JavaScript 提交中击败了100.00%的用户
 * 内存消耗 :36 MB, 在所有 JavaScript 提交中击败了75.00%的用户
 根据求二叉树最大深度递归方式进行修改，也是对节点进行编号，编号从0开始，
左子节点编号 = 父节点编号 * 2 + 1， 右子节点编号 = 父节点比那好 * 2 + 2；
存储每个层级的节点编号，进行计算。
![Snip20190907_10.png](https://pic.leetcode-cn.com/108f3bfc6594ec205bbbbd0524ae82bed09b59bb7c85d766583bc3abfa8a3214-Snip20190907_10.png)
```
var widthOfBinaryTree2 = function(root) {

    if (!root) return 0;

    var res = [], maxWidth = 1;
    recusion(root, 0, 0);
    return maxWidth;

    function recusion(root, level, num){

        if (res[level]){
            res[level].push(num);
        }
        else{
            res[level] = [num];
        }

        //计算最大宽度
        var tempArr = res[level];
        var tempWidth = tempArr[tempArr.length - 1] - tempArr[0] + 1;
        if (tempWidth > maxWidth) {
            maxWidth = tempWidth;
        }

        if (root.left){
            recusion(root.left, level + 1, num * 2 + 1);
        }
        if (root.right){
            recusion(root.right, level + 1, num * 2 + 2);
        }
    }
};

```
