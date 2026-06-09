1. ### 解题思路
1.创建一个函数overflow来判断输入和输出的x是否溢出
2.x为正数时，先化为字符串，再转化为数组，利用数组的reverse方法进行翻转
3.翻转后的x数组利用join方法重新化为字符串
4.利用parseInt转化为数字型,再return x
5.x为负数时，先x=-x，再重复2，3，4  步骤    

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var overflow = function(x) {
    if(x>=(-(Math.pow(2,31))) && x<=((Math.pow(2,31))-1)) return x;
    else return 0;
}

var reverse = function(x) {
    if(Math.abs(overflow(x)) > 0){
        if(x>=0){
            var x = x+"";
            x=x.split("");
            x=x.reverse();
            x=parseInt(x.join(""));
            return overflow(x);       
        }
        else{
            x=-x;
            var x = x+"";
            x=x.split("");
            x=x.reverse();
            x=parseInt(x.join(""));
            return overflow(-x)
        }
    }
    else{
        return 0;
    }      
};
```