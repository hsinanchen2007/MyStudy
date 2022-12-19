### 解题思路
我们定义三个变量，5块、10块，初始化为0，收到的20一定收入口袋，不会被找零出去
遍历整个队伍，如果收到5块，five++
            如果收到10块，ten++，且这时候检查一下是否有5块可以找零，则判断five===0？为真直接返回false
            如果收到20块，此时，如果没有五块钱，则false，有一张或者两张五块，没有十块则false，
### 代码

```javascript
/**
 * @param {number[]} bills
 * @return {boolean}
 */
var lemonadeChange = function(bills) {
    var five=0,ten=0;
    for(var i=0;i<bills.length;i++){
        if(bills[i]===5){
            five++
        }else if(bills[i]===10){
            if(five===0){
                return false
            }
            five--;
            ten++;
        }else if(bills[i]===20){
            if(five===0||(five===1&&ten===0)||(five===2&&ten===0)){
                return false
            }else if(ten>=1){
                five--;
                ten--
            }else if(ten==0){
                five--;
                five--;
                five--;
            }
        }
    }
    return true
};
```