
/**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/9/23
 * 
 * 解题思路: 主要弄明白两个四叉树合并的原则
 *  1.当遇到叶子节点的时候 叶子节点为True 合并结果为叶子节点 否则 合并结果为对方节点(不管对方是不是叶子节点,可能是一个子树,可能是一个真叶子节点,也可能是一个假叶子节点)
 *  2.当遇到的不是叶子节点 要进行递归
 *  3.最终进行判断 判断一个叶子节点的父节点所包含的四个节点是否都为 True 或者 False 是的话合并为该父节点(val 决定于 四个节点的值)
 *  
 *  这个题目不能对quadTree1 四叉树进行更改 直接饭quadTree1 ， 因为题目给出的非叶子节点有的val 为true 有的为false ,而结果返回中 中间节点(非叶子节点全部为false),就是题目说的：
 *  val只有在isLeaf == true 才有意义，否则权威false
 * 
 */

```
public Node intersect(Node quadTree1, Node quadTree2) {
    return Order(quadTree1,quadTree2);
}


//返回两个树合并之后的四叉树
public Node Order(Node quadTree1 ,  Node quadTree2){

    //如果有一个叶子节点 递归终止
    //当叶子节点为True 合并为叶子节点 否则 合并结果为非叶子节点的节点(对方节点)
    if(quadTree1.isLeaf){
        if(quadTree1.val){
            return quadTree1;
        }
        return quadTree2;
    }else if(quadTree2.isLeaf){
        if(quadTree2.val){
            return quadTree2;
        }
        return quadTree1;
    }

    //合并之后的各个分支
    Node topLeft = Order(quadTree1.topLeft, quadTree2.topLeft);
    Node topRight = Order(quadTree1.topRight, quadTree2.topRight);
    Node bottomLeft = Order(quadTree1.bottomLeft, quadTree2.bottomLeft);
    Node bottomRight = Order(quadTree1.bottomRight, quadTree2.bottomRight);

    //因为可能存在返回的都叶子节点 因此要判断一下返回的节点是否全部叶子节点 并且 都为 True 或者 False 这样要合并为一个大的节点
    if(topLeft.isLeaf && topRight.isLeaf && bottomLeft.isLeaf && bottomRight.isLeaf
        && topLeft.val == topRight.val && topLeft.val == bottomLeft.val && topLeft.val == bottomRight.val){
        return new Node(topLeft.val,true,null,null,null,null);
    }
    //否则的话保留各个分支节点 不进行合并
    return new Node(false,false,topLeft,topRight,bottomLeft,bottomRight);


}
```