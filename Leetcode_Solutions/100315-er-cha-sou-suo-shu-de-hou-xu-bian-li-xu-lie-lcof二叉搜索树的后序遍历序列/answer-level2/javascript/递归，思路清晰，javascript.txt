### 解题思路
![image.png](https://pic.leetcode-cn.com/bd60e067249e26ab51fb60a83c54c23ac164145de0e33396aa2d046120a235ff-image.png)


### 代码

```javascript
/**
 * @param {number[]} postorder
 * @return {boolean}
 */
var verifyPostorder = function(postorder) {
    //后序遍历：左  右  根
    //思路：递归方法，写一个比较函数（[]），函数里面分离出根、左、右；
    //然后判断left里面的所有值是否都小于根，right里面的所有值是否都大于根，有一个不满足，直接返回false，若都满足，继续递归左、右（最后一个节点为根节点）
    //设置临界处，如果传入参数只有一个节点或为空，则返回true即可
    const len = postorder.length;
    if(len <= 1) return true;
    const root = postorder[postorder.length - 1];//根
    let i = 0;
    for( ; i < len; i ++) {
        if(postorder[i] >= root) break;
    }
    const left = postorder.slice(0,i);
    const right = postorder.slice(i,len - 1);//slice() --> [a, b)
    const res = left.every((item) => item < root) && right.every((item) => item >= root);
    if(res) {
        return verifyPostorder(left) && verifyPostorder(right);
    } else {
        return false;
    }
};
```