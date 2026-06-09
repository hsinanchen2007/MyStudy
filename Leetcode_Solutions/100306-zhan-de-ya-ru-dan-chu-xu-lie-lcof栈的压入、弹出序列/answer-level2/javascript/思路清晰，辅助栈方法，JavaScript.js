### 解题思路
![image.png](https://pic.leetcode-cn.com/41408cc9afffc4cc02a3b498260e8907fd9272755f86d360a1a8bf0fbbd6cb93-image.png)


### 代码

```javascript
/**
 * @param {number[]} pushed
 * @param {number[]} popped
 * @return {boolean}
 */
var validateStackSequences = function(pushed, popped) {
    //思路：首先循环pushed，依次将元素压入辅助栈中，并比较栈中第一个元素是否是pop中指针所指的元素，如果是则出栈，pop中指针指向下一元素；继续比较当前栈中第一个元素是否为pop所指元素，若是则出栈，继续比较下一个
    //如果不是，则继续压入栈，继续比较当前第一个元素是否为要找的元素，直到push中所有元素都压入栈中
    //如果到最后push中为空，而且当前辅助栈中第一个元素与pop中指针元素不相等，则返回false，反之true
    const pushLen = pushed.length;
    const popLen = popped.length;
    let auxiliaryStack = [];
    let pop = -1;
    let popPointer = 0;
    for(let i = 0; i < pushLen; i ++) {
        auxiliaryStack.push(pushed[i]);//压入元素
        pop ++;
        while(true) {
            if(auxiliaryStack[pop] === popped[popPointer] && pop >= 0) {//若二者相等
                auxiliaryStack.pop();//出栈
                pop --;//--
                popPointer ++;//++
            } else {
                break;
            }
        }
    }
    if(auxiliaryStack.length === 0) return true;
    return false;
};
```