### 解题思路
1. 首先生成键值对，将键值按照从小到大排列而出
2. 还是从大到小进行取余、取商
3. 如果商数大于0，说明值有效，这时候就要拼接到结果`result`中
4. 在商有效的情况下，判断是否已经整除完，也就是判断一下余数是否为0，减少没必要的循环

### 代码

```javascript
 let roman_num_list = [{
        key: "I",
        value : 1
      },{
        key: "IV",
        value : 4
      },{
        key: "V",
        value : 5
      },{
        key: "IX",
        value : 9
      },{
        key: "X",
        value : 10
      },{
        key: "XL",
        value : 40
      },{
        key: "L",
        value : 50
      },{
        key: "XC",
        value : 90
      },{
        key: "C",
        value : 100
      },{
        key: "CD",
        value : 400
      },{
        key: "D",
        value : 500
      },{
        key: "CM",
        value : 900
      },
      {
        key: "M",
        value : 1000
      }];
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
      // result 为结果， flag 为 当前 被除数的标志位
      let result = '' , flag = roman_num_list.length - 1;
      while (flag >= 0) {
        let shang = parseInt(num / roman_num_list[flag]['value']) , yu = num % roman_num_list[flag]['value'];
        if(shang > 0){
          // 商数有效，将结果 拼接为字符串放入结果中
          result += roman_num_list[flag]['key'].repeat(shang);
          if( yu == 0 ){
            // 如果没有余数，说明已经整除完了，不需要进行其他操作
            flag = 0
          }
        }
        num = yu
        flag--
      }
      return result;
};
```