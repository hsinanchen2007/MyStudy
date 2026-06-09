**遇到的坑**

1. 做这题遇到的坑比较多，最开始采用的方法是将输入的二进制字符串转为十进制，但是提交的时候遇到下面的问题：

![image.png](https://pic.leetcode-cn.com/a3894bb873ea534f1eaf5dbc96cd167b4e08f2129950fd5eaefa08bff35d0f9e-image.png)

数据太大，超限了...

2. 后面改成不转10进制直接处理原字符串：如果末尾字符为 '0'，就去掉；如果末尾为 '1' 就进位
然后用JavaScript处理字符串的时候又遇到了下面的坑：

`在 JavaScript 中，无法直接通过 '1' + 1 的方式得到 '2'，会得到 '11'`

`在 JavaScript 中，对于字符串 s = “1101” 来说，是可以通过下标 i 访问字符串中的元素 s[i] 的，但是无法通过下标赋值的方式修改 s 中的元素，即 s[i] = 'x' 的方式是无效的。`

最后花了挺多时间总算是解出来了：


```javascript []
/**
 * @param {string} s
 * @return {number}
 */
var numSteps = function(s) {
    var len = s.length;
    var step = 0;
    while(len != 1){
        if(s[len - 1] == '0'){
            len--;
        }else{
            var carry = 1;
            for(var i = len - 1; i >= 0; i--){
                if((s[i] - '0') + carry == 2){
                    s = s.slice(0,i) + '0' + s.slice(i+1);
                    carry = 1;
                }else{
                    s = s.slice(0,i) + '1' + s.slice(i+1);
                    carry = 0;
                    break;
                }
            }
            if(carry) { s = '1' + s; len++; }
        }
        step++;
    }
    return step;
};
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```


