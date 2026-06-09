### 用js自带的方法实现
Array.from()方法从一个类似数组或可迭代对象创建一个新的，浅拷贝的数组实例。
[具体见mdn文档](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Array/from)

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var printNumbers = function(n) {
    // 先用字符串拼接出打印出的最大数字
    let numstr = "";
    for(let i = 0; i < n; i++) {
        numstr += "9";
    }
    // Number(numstr) 将字符串转换成number
    // Array.from()中使用箭头函数，第一个参数是创建出array的长度或原始array数组
    // 第二个参数是箭头函数，生成数组的具体内容，这个函数中 (v, i) v代表原始array数组的值，i代表数组的索引
    // 因为打印是从 1 开始，所以索引要加1
    return Array.from(Array(Number(numstr)), (v, i) => i+1);
};
```
在题解中看到了大神使用Math的函数求出最大值
```
    let max = 0
	for(let i=0;i<n;i++){
        // Math.pow(x, y)  是求出 x的y次方
		max = max + 9*Math.pow(10,i)
	}
```
[js创建0-100数组的方法](https://www.cnblogs.com/zhishaofei/p/10146870.html)