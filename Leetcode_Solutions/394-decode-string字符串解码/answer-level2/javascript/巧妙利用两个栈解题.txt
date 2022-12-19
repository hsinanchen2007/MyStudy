### 解题思路
+ 首先声明两个变量，resStr 拼接字符串，repet 重复次数。
+ 题目需要拼接字符串，分别用两个栈来保存两个变量。
+ 总体遍历一遍s，根据遍历到不同的字符做出操作：
    1. 当遇到数字时，累积 repet 值
    2. 当遇到字母时，直接拼接到 resStr 后面
    3. 当遇到 '[' 时，将之前的 resStr 和 repet 分别压入各自的栈中，保存当前状态
    4. 当遇到 ']' 时，取出栈中的 repet，将当前 resStr 重复 repet 次，赋值给临时变量 temp，然后和之前存放的 resStr(也就是存放repetStack栈顶元素) 拼接起来

具体参照以下代码

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var decodeString = function(s) {
    // 用两个栈来存放当前状态，前者是重复次数，后者是累积字符串
    let repetStack=[],resStack=[];
    //拼接字符串
    let resStr = "";
    //表示重复次数
    let repet = 0;
    // 遍历s
    for(let i=0;i<s.length;i++){
        let cur = s.charAt(i);
        if(cur == '['){
            //双双压入栈中,保存当前状态
            repetStack.push(repet);
            resStack.push(resStr);
            //置空，准备下面的累积
            repet = 0;
            resStr = "";
        }else if(cur == ']'){
            // 取出当前重复次数栈中的值，也就是当前字符串的重复次数
            let count = repetStack.pop();
            // 根据重复次数生成重复字符串，赋值给temp，和resStr拼接
            let temp = "";
            for(let i = 0;i<count;i++){
                temp += resStr;
            }
            // 和前面已经求得的字符串进行拼接
            resStr = resStack.pop() + temp;
        }else if(cur>='0' && cur<='9'){
            // repet累积
            repet = repet*10 + (cur-'0');
        }else{
            //字符累积
            resStr += cur;
        }
    }
    return resStr;
};
```