# 第一种方法 遍历法

瀑布思维的产物：将二进制字符串化的x和y的长度进行比较，之后使用padStart()填充成一样的长度，最后再两个字符串一起遍历，这个方法最蠢也最慢……只恨自己计算机基础知识太菜：

```
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    if(x === y) return 0;
    x = x.toString(2);
    y = y.toString(2);
    let count = 0;
    if(x.length > y.length) {
        y = y.padStart(x.length, "0");
        for(let i = 0; i < x.length; i++) {
            if(y[i] !== x[i]) count++;
        }
    } else {
        x = x.padStart(y.length, "0");
        for(let i = 0; i<y.length; i++) {
            if(y[i] !== x[i]) count++;
        }
    }
    return count
};
```

#第二种方法 异或法（遍历）

看了评论的提示，可以使用异或的性质将不同的位数取出，然后遍历一遍即可：

```
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    if(x === y) return 0;
    x = (x^y).toString(2)
    y = 0
    for(let i = 0; i < x.length; i++) {
        if(x[i] === "1") y++
    }
    return y
};
```



#第三种方法 异或法（split())

然后自己又思考了一下，感觉还能活用JS里split()的性质：根据方法内的参数将字符串根据参数划分为参数数量+1长度的数组。所以我们return的时候要length-1

```
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    if(x === y) return 0;
    x = (x^y).toString(2)    
    return x.split('1').length-1
};
```
