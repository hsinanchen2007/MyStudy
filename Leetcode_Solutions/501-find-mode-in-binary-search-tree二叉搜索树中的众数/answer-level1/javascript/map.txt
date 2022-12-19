### 解题思路
将每个节点的值和次数存到一个全局 map中，将其转化为数组并进行排序，找到与最大次数相同的值存入数组中

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
 * @return {number[]}
 */

var findMode = function(root) {
    var map = new Map();
    mapNum(root);
    var l=[];
    map = [...map];
    map.sort((a, b) => b[1] - a[1])
    for (let i = 0; i < map.length; i++) {
    if (i === 0 || map[i][1] === map[i - 1][1]) {
      l.push( map[i][0] );
    } else {
      break;
    }
  }

    return l;

    function mapNum(node){
    if(node === null) return[];
    if(!map.has(node.val)){
        map.set(node.val,1)
    }else{
        map.set(node.val,map.get(node.val)+1);
    }
    mapNum(node.left);
    mapNum(node.right);
}
};

