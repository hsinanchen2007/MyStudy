### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    var sum = [];  //创建空数组
    if (num1.length < num2.length){  //比较字符串长度 在短的字符串前拼接0使长度相等
        for (var i = 0; num2.length !== num1.length; i++){
            num1 = "0" + num1
        }
    }else if (num2.length < num1.length){
        for (var i = 0; num1.length !== num2.length; i++){
            num2 = "0" + num2
        }
    }
    for (var s = 0; s < num1.length; s++){   //空数组用0填满到字符串的长度
        sum.unshift(0)
    }
    for (var a = num1.length - 1; a >= 0; a--){   
        sum[a] = (num1[a] | 0) + (num2[a] | 0) + (sum[a] | 0 )   //每个字符转为数字相加
         if (sum[0] > 9 && (num1 !== "0")){     //   针对 出现 0，0和11，9的情况
            sum[0] = sum[0] % 10
            sum.unshift(1)     
        }
        else if (sum[a] > 9){
            sum[a] = sum[a] % 10   //又相加大于9的 取余数   
            sum[a - 1] ++       //然后上一位相加
        }
    }
    sum = sum.join("")  //数组转字符串
    return sum
}
```