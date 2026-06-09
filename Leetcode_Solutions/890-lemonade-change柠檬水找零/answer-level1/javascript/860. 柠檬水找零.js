#### 解法：贪心选择
+ 题意每张账单只能是5、10、20
+ 柠檬水均是5元一份
+ 店家自己没有零钱
+ 解法与思路
  + 当收到20时
    + 优先匹配店家手里的一张10和一张5，如有返回true
      + 店家手里的10-- 
      + 店家手里的5-- 
    + 如没有重新匹配3张15，如有返回true
      + 店家手里的5-=3 
    + 如都没有返回false
  + 当收到10时
    + 优先匹配一张5如有返回true
      + 店家手里的5--，10++ 
    + 如没有返回false
  + 当收到5时
    + 店家手里的5++  
```javascript
/**
 * @param {number[]} bills
 * @return {boolean}
 */
var lemonadeChange = function(bills) {
    var five = 0;
    var ten = 0;
    var len = bills.length;
    for(var i = 0;i<len;i++){
        if(bills[i] == 5){
            five++;
        }else if(bills[i] == 10){
            if(five == 0){
                return false
            };
            five--;
            ten++;
        }else if(bills[i] == 20){
            if(ten > 0 && five > 0){
                ten--;
                five--;
            }else if(five >= 3){
                five -= 3;
            }else{
                return false;
            }
        }
    }
    return true;
};
```