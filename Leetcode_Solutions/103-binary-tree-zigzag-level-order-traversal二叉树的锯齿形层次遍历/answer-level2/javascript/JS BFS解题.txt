### 解题思路
此处撰写解题思路
JS 实现BFS广度优先搜索。
BFS需要一个FIFO的队列来完成节点的遍历，由于JS没有可以直接使用的队列对象，需要自己通过数组方式实现一个队列。
使用BFS算法，通过标记位决定顺序还是逆序添加。

###BFS###
BFS 可以按照一定的模板实现
1、定义队列
2、循环遍历队列
3、对出列数据进行操作，并遍历其子树进队列
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
function Queue (){
    this.queue = [];
}
//加入队列
Queue.prototype.addQueue = function (x){
    this.queue.push(x);
    return true;
}
//从队列删除
Queue.prototype.delQueue = function (){
    if(this.isEmpty()){
       return false;
    }
    this.queue.shift();
    return true;
}
//获取队列头
Queue.prototype.front = function (){
    if(this.isEmpty()){
       return false;
    }
    return this.queue[0];
}
//队列判空
Queue.prototype.isEmpty = function(){
    return !this.queue.length
}
//队列长度
Queue.prototype.size = function(){
    return this.queue.length;
}
var zigzagLevelOrder = function(root) {
   let queue = new Queue();
   let result = new Array();
    if (root == null){
        return result;
    }
   queue.addQueue(root);
   let isReverse = false;
   while(!queue.isEmpty()){
       let size = queue.size();
       //console.log(size);
       let curl =new Array();
       for (let i = 0; i < size; i++){
          let cur = queue.front();
          //console.log(cur);
          if (cur.left !== null){
             queue.addQueue(cur.left)
          }
          if (cur.right !==null){
             queue.addQueue(cur.right)
          }
          curl.push(cur.val);
          queue.delQueue();
       }
       //console.log(queue);
        if (isReverse){
              result.push(curl.reverse());
          }else{
              result.push(curl);
          }
        isReverse=!isReverse;
   }
   return result;
};
```