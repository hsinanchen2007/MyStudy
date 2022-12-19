
### 代码
先给大家上代码，思路差不多一致，写法不同
后附我的题解
- 写法1
```javascript
var reverse = function(x) {
    var val = 1
    if(x < 0) {
        val = -1
    }
    x = Math.abs(x) + ''
    x = x.split('').reverse().join('') * val
    return x>(Math.pow(2,31)-1)||x<(Math.pow(-2,31))?0:x
};

```
- 写法2
```javascript
var reverse = function(x) {
    var val = x<0?-1:1
    var outNum = Math.abs(Math.pow(2*val,31)-(val===1?1:0))
    x = Math.abs(x) + ''
    x = x.split('').reverse().join('')
    return x>outNum?0:x*val
};
```
- 写法2再简化 （三行）
```javascript
var reverse = function(x) {
    var val = x<0?-1:1
    x = Math.abs(x).toString.split('').reverse().join('')
    return x>Math.abs(Math.pow(2*val,31)-(val===1?1:0))?0:x*val
};
```
### 解题思路
1. 先判断传进来的x是否为负数
    - 定义一个变量val存储
    - 若是负数，则为-1，
    - 若是正数，则为1
```javascript
// 例如：
if(x < 0) {
    val = -1
}

//更简单写法
var val = x<0?-1:1
```
2. 换成字符串进行操作
    - 若x是负值会影响操作，所以转换前将其进行绝对值处理
```javascript
//绝对值处理 + 隐式转换成字符串
x = Math.abs(x) + ''

//其他方法
x = Math.abs(x).toString()
```
3. 反转操作
    - 使用split将字符串切割成数组
    - 巧用数组的reverse()方法进行反转
    - 再将反转后的数组使用join('')串连成字符串
```javascript
x = x.split('')
x = x.reverse()
x = x.join('')

//可一连串进行操作
x = x.split('').reverse().join('')
```
4. 处理负数问题
```javascript
x = x*val
```
5. 处理溢出问题并返回
```javascript
if(x>(Math.pow(2,31)-1)||x<(Math.pow(-2,31))) {
    return 0
}else{
    return x
}

//用三目运算符编写
return x>(Math.pow(2,31)-1)||x<(Math.pow(-2,31))?0:x
```
6. 写法二的思路
    - 利用判断x正负的val值和溢出区间进行结合
    - 若x为负数时，要判断的区间是Math.pow(-2,31)
    - 若x为正数时，要判断的区间是Math.pow(2,31)-1)
```javascript
var outNum = Math.pow(2*val,31);
if(val===1){ //若val为正数
    outNum += 1
}

//利用三目运算简化
var outNum = Math.pow(2*val,31)-(val===1?1:0)
```
然后可以将outNum进行取绝对值，这样和x绝对值相比就只需要比大小啦~
而若无溢出，在返回的时候乘上val即可
```javascript
var outNum = Math.abs(Math.pow(2*val,31)-(val===1?1:0)
return x>outNum?0:x*val
```

### 后文
以上便是我的题解啦
执行用时大概在90ms以内，内存消耗37mb以内
![image.png](https://pic.leetcode-cn.com/494d65ff9af83af2ca07bed830870e635e4afefe127ae3ed8bf5c1d3df4a1638-image.png)

小白第一次发题解，若有不合适的地方，欢迎各位大神看官指正
（如发现雷同，纯属巧合）

>ps：比起想新方法，写题解真是太麻烦辣！
>大概做题我也不知道自己在想什么东东吧(┬＿┬)哈哈