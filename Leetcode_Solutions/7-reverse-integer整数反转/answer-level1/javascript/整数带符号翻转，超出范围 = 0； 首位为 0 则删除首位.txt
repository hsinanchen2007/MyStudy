### 解题思路
此处撰写解题思路
1. 将 x 分区处理；[-9, 9] 这中间的数据翻转为自身
2. 提供 firstZero 函数，处理翻转之后首位为0 的数组
3. firstZero 第二个参数  fuhao ; true = 正数；false = 负数
4. Math.pow(2,31) 2的31次方

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    x = Number(x);
    if(-10 < x && x < 10){
        return x;
    }
    if(x > 9){
        var numArr = x.toString().split('').reverse();
        x = firstZero(numArr, true);
        return x;
    } 
    if(x < -9){
        var newArr = x.toString().split('');
        newArr.splice(0,1);
        newArr.reverse();
        x = firstZero(newArr, false);
        return x;
    }
    function firstZero(arr,fuhao){
        if(arr[0] === '0'){
            arr.splice(0,1);
            firstZero(arr, fuhao);
        }
        if(arr[0] !== '0'){
            if(fuhao){
                num = ((arr.join('') - 0) > (Math.pow(2,31) -1) ? 0 : (arr.join('') -0));
            }
            if(!fuhao){
                num = ((0-arr.join('')) < -Math.pow(2,31) ? 0 : (0- arr.join('')))
            }
            return num;
        }
    }
};
```