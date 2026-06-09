在竞赛的时候题目翻译有问题，导致浪费了很多时间读题！！！   

这题的关键点在于判断某个节点的`left`、`right`、`parent`对应的节点的总数目
例如： 
![](https://pic.leetcode-cn.com/fe0e4e9f1cad328263e879beb47154cde722579c1f529d89a2593392f329983b-file_1564991715849)  
3号节点： 
`parent节点`的总数为：`8`   
`left节点`总数为：`1`   
`right节点`总数为：`1`  
第二人最佳选择肯定由`3`号节点对应的`parent`、`left`、`right`的根部直接截断截断  
截断后第二人独自占有了`8`个节点、第一人独自占有了`3`个节点  
因此题目转换为：
已知节点`3`的`left`、`right`、`parent`的节点数目，是否存在某一条枝干节点的数目大于剩余所有节点数目之和

```javascript
var btreeGameWinningMove = function(root, n, x) {
    let xNode;
    let all = tools(root);
    
    let part1 = xNode.leftChild;
    let part2 = xNode.rightChild;
    
    //父分支的节点数
    let part3 = (function(node){
        let p = xNode.p;
        if(!p)return 0;
        while(p.p){
            p=p.p
        }
        if(p.left===node){
            return p.leftChild-1-part1-part2+1+p.rightChild
        }else{
            return p.rightChild-1-part1-part2+1+p.leftChild
        }
    })(xNode);
    
    if(part1+part2+1<part3 || part1+part3+1<part2 || part2+part3+1<part1){
        return true;
    }
    return false;
    
    //求对应分支的节点数
    function tools(node){
        if(node.val===x){
            xNode=node;
        }
        let leftChild=0;
        let rightChild=0;
        if(node.left){
            node.left.p=node;
            leftChild = tools(node.left);
        }
        if(node.right){
            node.right.p=node;
            rightChild = tools(node.right);
        }
        node.leftChild = leftChild
        node.rightChild = rightChild;
        return leftChild+rightChild+1;
    }
};
```

优化版：  

```javascript
var btreeGameWinningMove = function(root, n, x) {
    let xNode;
    let all = tools(root);
    let part1 = xNode.leftChild;
    let part2 = xNode.rightChild;
    //parent分支对应的节点数
    let part3 = all-part1-part2-1;
    
    if(part1+part2+1<part3 || part1+part3+1<part2 || part2+part3+1<part1){
        return true;
    }
    return false;
    
    // node及其子节点的总节点数
    function tools(node){
        if(node.val===x){
            xNode=node;
        }
        // 左分支节点数
        let leftChild = node.leftChild = node.left?tools(node.left):0;
        // 右分支节点数
        let rightChild = node.rightChild = node.right?tools(node.right):0;
        // 总节点数
        return leftChild+rightChild+1;
    }
};
```