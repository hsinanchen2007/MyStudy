### 解题思路
使用栈的思路解决：
1、如果为“(”入栈，如果为“)”出栈，深度为栈的长度
2、根据归类方法的比较，可以深度为奇数的归为一类，深度为偶数的归为一类（通过模2确定奇偶并入栈）

注意：归类入栈和括号入栈的顺序

### 代码

```javascript
/**
 * @param {string} seq
 * @return {number[]}
 */
var maxDepthAfterSplit = function(seq){
				var seqArr = seq.split('');
				var arr = [];
				var des = 0;
				var depthStack = []
				for(var i = 0;i<seqArr.length;i++){
					if(seqArr[i]=='('){
                        arr.push(des%2);
						depthStack.push(seqArr[i]);
						des = depthStack.length;
						
					}else{
						//arr.push(des%2);
						depthStack.pop();
						des = depthStack.length;
						arr.push(des%2);
					}
				}
				return arr;
			
};
```