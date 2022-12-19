### 解题思路
见注释

### 代码

```javascript
var verifyPostorder = function(postorder) {
    if (postorder.length != 1) {
        var root = postorder.pop(); // 弹出数组最尾  数组改变
        var key = postorder.length; // 初始值
        // 找出左右子树的分界点
        for(let index in postorder) {
            if (postorder[index] > root) {
                key = index;
                break;
            }
        }
        // 如果分界点是0，说明没有左子树
        if (key != 0) {
        	// 劫取数组，left存储左子树
            var left = postorder.slice(0,key);
            console.log(left)
            // 如果左子树里 有比根结点大的说明顺序错误
            for (let i in left) {
            	if (left[i] > root) {
            		return false;
            	}
            }
            if(!verifyPostorder(left))
            	return false;
        }
        // 如果分界点还是初始值，说明没有右子树
        if (key != postorder.length) {
        	// right存储左子树
            var right = postorder.slice(key);
            console.log(right)
            // 如果右子树里 有比根结点小的说明顺序错误
            for (var i in right) {
            	if (right[i] < root) {
            		return false;
            	}
            }
            if(!verifyPostorder(right))
            	return false;
        }
    } 
    
    return true;
};
```