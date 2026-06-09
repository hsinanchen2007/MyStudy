方法一：228ms
思路：中序遍历中数组存的是节点，之后依次对节点的左右子节点进行修改
```javascript
var increasingBST = function(root) {
    let res = [];
    inOrderNode(root);
    for(var i = 0; i < res.length-1; i++){//注意要用var，如果按我的思路（即，最后那个节点特殊处理）的话用let会错
        res[i].left = null;
        res[i].right = res[i+1];
    }
    // 最后那个节点
    res[i].left = res[i].right = null;
    
    // 注意要从0开始，为什么？可能是因为要求返回的是一个根节点叭
    return res[0];

    // 注意存的是节点
    function inOrderNode(root){
        if(!root)return null;
        inOrderNode(root.left);
        res.push(root);
        inOrderNode(root.right);
    }
};
```
方法二：332ms 来自[官方题解](https://leetcode-cn.com/problems/increasing-order-search-tree/solution/di-zeng-shun-xu-cha-zhao-shu-by-leetcode/)方法一
思路：中序遍历的数组存的是值，之后在数组基础上构造新的树
```javascript
var increasingBST = function(root) {
    let res = [];
    inOrderNode(root);
    console.log(res);
    let ans = new TreeNode();
    let cur = ans;
    for(let i of res){
        cur.right = new TreeNode(i);
        cur = cur.right;
    }
    return ans.right;
    
    function inOrderNode(root){
        if(!root)return null;
        inOrderNode(root.left);
        res.push(root.val);
        inOrderNode(root.right);
    }
}
```
方法三：348ms 来自[官方题解](https://leetcode-cn.com/problems/increasing-order-search-tree/solution/di-zeng-shun-xu-cha-zhao-shu-by-leetcode/)方法二
思路：在中序遍历的同时也在构造新树
```javascript
var increasingBST = function(root) {
    let res = new TreeNode();
    let cur = res;
    inOrderNode(root);
    
    return cur.right;
    //不加right：[undefined,null,1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
    //加了right：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

    // 注意存的是节点
    function inOrderNode(node){
        if(!node)return null;
        inOrderNode(node.left);
        node.left = null;
        res.right = node;
        res = node;
        inOrderNode(node.right);
    }
};
```

不知道其他大佬有没有更快的解决方法，这三个方法用js运行太慢了

加一个非递归的方法，但是还没解决报错的原因..
```javascript
var increasingBST = function(root) {
    let s = [];
    let res = new TreeNode();
    let p = res;
    
    while(root || s){
        if(root){
            s.push(root);
            root = root.left;
        }else{
            let cur = s.pop();
            root = cur.right;//这句报错。目测是因为s.pop()会弹出空，但是我没想到解决方法
            cur.left = null;
            p.right = cur;
            p = p.right;
            
        }
    }
    return res.right;
}
```
