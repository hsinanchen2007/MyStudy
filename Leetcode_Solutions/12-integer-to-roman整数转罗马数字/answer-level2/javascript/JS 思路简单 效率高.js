### 解题思路
没有考虑什么贪心不贪心,就单纯得一位一位求，速度也还可以，超越99.9%
### 代码

```javascript
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    function TurnFive(n, one, five, ten){
        if(n != 0){
            if(n < 4){
                return one.repeat(n);
            }
            if(n == 4){
                return one + five;
            }
            if(n < 9){
                let times = n-5;
                let I = one.repeat(times)
                return five + I;
            }
            if(n == 9){
                return one + ten;
            }            
        }
        return "";
    }
    let than = Math.floor(num / 1000);
    let hon = Math.floor(num % 1000 / 100);
    let ten = Math.floor(num % 1000 % 100 /10);
    let ge = Math.floor(num % 1000 %100 % 10);
    return TurnFive(than, "M", "", "") + 
            TurnFive(hon, "C", "D", "M") + 
            TurnFive(ten, "X", "L", "C") + 
            TurnFive(ge, "I", "V", "X");
};
```