利用正则表达式的规则与 paseFloat 的特性（当然，这不是最优解）
```
// 先以任意一个字符拼成字符串
var strArr = nums.join("@") + "@";

// 暴力清空数组
nums.length = 0;

// 正则表达式匹配（以 - 开头（可选，主要针对负数），整数 + 设定的字符，可以出现1到多次，并全局匹配）
// 回调函数处理捕获组，再用 parseFloat 截取数字部分
strArr.replace(/(-?\d+@)\1*/g, (whole, part) => {
    nums.push(parseFloat(part));
});

return nums.length;
```
