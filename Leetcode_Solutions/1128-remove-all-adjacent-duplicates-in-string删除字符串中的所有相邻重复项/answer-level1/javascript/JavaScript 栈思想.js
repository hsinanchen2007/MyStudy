### 解题思路
本题可借助栈的思想完成，定义一个用于保存最终结果的数组jin[]，然后遍历形参的每一个字符，如果该字符和结果数组jin[]的最后一个元素(即栈顶元素)相等，则将结果数组的栈顶元素弹出，否则将遍历到的这个字符推入结果数组中。  
代码如下：
### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var removeDuplicates = function(S) {
    var jin = [];
    var len = S.length;
    var res = "";
    for (var i = 0;i < len;i++){
        if (S[i] != jin[jin.length-1]){
            jin.push(S[i]);
        }
        else {
            jin.pop();
        }
    }

    res = jin.join("");
    return res;
};
```
### 结果
![res.png](https://pic.leetcode-cn.com/6b243ab0fd55c01c5f3b98f6e9ef9b15c87fa7d51e22bd207de4513147c98d06-res.png)

