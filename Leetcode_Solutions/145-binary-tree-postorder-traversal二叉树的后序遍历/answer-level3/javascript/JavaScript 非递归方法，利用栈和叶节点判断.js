因为如果要利用栈的话，在后序遍历中，顺序为左右父。
因此，我们需要经过父节点两次，一次遍历左，一次遍历右。
所以，需要区分左节点或者右节点是否已经遍历过。
所以我在节点上都加了flag用来标记是否已经走过这个节点了。

相当于我们走过的节点都要将他分割出树。以免重复遍历。


let postorderArr = [], nodeList = [], nowNode;
let postorderTraversal  = (root) => {
    postorderArr = [];
    if (!root) {
        return postorderArr;
    }
    nodeList = [], nowNode = root;
     while(nodeList.length > 0 || nowNode) {
        while (nowNode) {
            nowNode.flag = true;
            nodeList.push(nowNode);
            if (nowNode.left && !nowNode.left.flag) {
                nowNode = nowNode.left;
            } else if (nowNode.right && !nowNode.right.flag) {
                nowNode = nowNode.right;
            } else {
                nowNode = null;
            }
        }
        nowNode = nodeList.pop();
        if (!nowNode.right || nowNode.right.flag) {
             postorderArr.push(nowNode.val);
            nowNode = null;
        }
    }
    
    return postorderArr;
};