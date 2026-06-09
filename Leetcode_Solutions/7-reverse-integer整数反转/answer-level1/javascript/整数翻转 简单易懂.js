## 思路
1.将整数转成数组
2.去除数组中的0
3.利用数组的reverse()将数组翻转，再转成字符串

## 代码
```
/**
 * @param {number} x
 * @return {number}
 */

var reverse = function(x) {
    //判断是否是负数
    let flag=x>0? 1:-1;
    //转成数组
    let arr=x.toString().split('');
    //如果是负数 去掉数组中' - '号
    if(flag===-1) arr.shift();
    //翻转数组
    arr.reverse();
    //如果数组中第一个元素为0 删除掉
    while(arr[0]==='0') {
        arr.shift();
    }
    // 将翻转后的数组转成字符串*是否是负数 得到结果
    let res=flag*arr.join('');
    let max=Math.pow(2,31)-1;
    let min=-Math.pow(2,31);

    return (res>max||res<min)? 0:res;
};
```
