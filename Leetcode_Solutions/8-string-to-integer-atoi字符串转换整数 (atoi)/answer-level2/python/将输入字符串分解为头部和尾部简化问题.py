**为了将问题简化，将输入的字符串定义为两部分：**
1.由空格、加号、减号组成的头部（可能为空）
2.头部结束之后的尾部

**这样的话可以方便地对原始字符串进行分开处理：**
1.头部的处理：很简单，对空格、加号、减号分别处理就行
2.尾部的处理：也很简单，只要不是数字，就结束计算

**而从头部进入尾部的标志如下：**
1.头部只要不是空格、加号、减号，都说明头部结束进入尾部

代码如下：
```javascript []
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    var max = Math.pow(2, 31) - 1;
    var sum = 0, sign = 1;
    var headIsNotOver = true; // 默认头部未结束
    for(var i = 0; i < str.length; i++){
        if(headIsNotOver){
            if(str[i] == ' ') continue;
            // 只要出现一次 '-' 或者 '+' ，则头部结束
            if(str[i] == '-') { sign = -1; headIsNotOver = false; continue; }
            else if(str[i] == '+') { headIsNotOver = false; continue; }
            // 如果不是上面三种情况则也说明头部结束
            headIsNotOver = false;
        }
        // 进入尾部
        if('0' <= str[i] && str[i] <= '9'){
            sum = sum * 10 + (str[i] - '0');
            if(sum > max) return sign > 0 ? max : - max - 1;
        }else{
            break; 
        }
    }
    return sign * sum;
};
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
