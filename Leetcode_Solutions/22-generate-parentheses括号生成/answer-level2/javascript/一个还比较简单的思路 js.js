### 解题思路
思路是从左到右的插入思想，第一次为一个括号，下一次要在`（）`中的`（`右边插入一个`（）`，这样会得到两个可能，对应n为2的答案，当下一次也就是n为3的时候，就要在上面获得的两个答案中的字符串里面，在最后一个`（`右边插入`（）`。具体思想如下：
##### n = 1
()
##### n = 2
(**()**)
()**()**
##### n = 3
(()) -> ((**()**)),(()**()**),(())**()**
()() -> ()(**()**),()()**()**

所以需要两个循环来这样一直遍历下去

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    if (n == 0) {
        return [];
    }
    if (n == 1) {
        return ["()"];
    }
    let resultArray = ["()"];
    let i = 1;
    while (i < n) {
        let tempArray = [];
        for (let j = 0;j < resultArray.length; j++) {
            let tempStr = resultArray[j];
            let beginIndex = tempStr.lastIndexOf("(") + 1;  
            for (let index = beginIndex; index <= tempStr.length; index++) {
                var sss = tempStr;
                tempArray.push(sss.slice(0,index) + "()" + sss.slice(index));
            }
        }
        i ++;
        resultArray = tempArray;
    }
    return resultArray;
};
```