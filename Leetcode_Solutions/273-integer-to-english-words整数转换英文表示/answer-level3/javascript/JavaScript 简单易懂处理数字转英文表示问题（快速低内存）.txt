### 解题思路

因为是转为英文表示，直接就想到银行对数字的书写格式，没三位分割一次，附带上不同的单位（无、千、百万、十亿）；【咱们题目数字最大到百亿级别】

依次处理切割后三位以内的数字，然后在利用不同的单位拼接起来

类似： **123 456 789 123 =>   fn(123) + "Billion" + fn(456) + "Million" + fn(789) + "Thousand" + fn(123) + "";**

处理三位数：
初始字符为空字符；
首先看百位数值 除以一百取整，大于0，则字符加等百位数值对应的个位数单词
1到19 分别对应不同单词(0不处理)
20~99 则是（20,30,...,90）整数位对应的单词 + 个位对应单词（0不处理）

这里为了方便处理拼接空格为题， 我在对应的单词的前面都加了一个空白字符；
最后再统一处理去除头尾空字符，将连续2个以上的空字符变为单个空字符

### 代码

```javascript
/**
 * @param {number} num
 * @return {string}
 */
var numberToWords = function (num) {
    if(num === 0) return "Zero";
  // 1到19
  const unitObj = {
    1: " One",
    2: " Two",
    3: " Three",
    4: " Four",
    5: " Five",
    6: " Six",
    7: " Seven",
    8: " Eight",
    9: " Nine",
    10: " Ten",
    11: " Eleven",
    12: " Twelve",
    13: " Thirteen",
    14: " Fourteen",
    15: " Fifteen",
    16: " Sixteen",
    17: " Seventeen",
    18: " Eighteen",
    19: " Nineteen"
  }
  // 20, 30 ~ 90
  const tenObj = {
    2: " Twenty",
    3: " Thirty",
    4: " Forty",
    5: " Fifty",
    6: " Sixty",
    7: " Seventy",
    8: " Eighty",
    9: " Ninety"
  }
  // 数字大小限制为Billion级别，所以只需要以下几个就行了
  const unitAry = ["", " Thousand", " Million", " Billion"];
  // 这个数决定选取当前的数字块后面加的单位
  let count = 0;
  let str = "";
  // 将数字按照3位分割 分割后的数字 除了后面附带的单位不一样，其他的都相同处理方法
  while (num > 0) {
    const newNum = num % 1000;
    const newNumStr = convertNumToStr(newNum);
    str = (newNumStr === "" ? "" : (newNumStr + unitAry[count])) + (str === "" ? "" : (" " + str));
    num = parseInt(num / 1000);
    count++;
  }

  function convertNumToStr(num) {
    let str = "";
    const n1 = parseInt(num / 100);
    if (n1 > 0) {
      str += unitObj[n1] + " Hundred";
    }
    let n2 = num % 100;
    if (n2 > 19) {
      const tenCount = parseInt(n2 / 10);
      const geCount = n2 % 10;
      str += tenObj[tenCount];
      if (geCount > 0) {
        str += unitObj[geCount];
      }
    } else if(n2 > 0) {
      str += unitObj[n2];
    }
    return str.trim();
  }
  return str.replace(/\s{2,}/g, " ");
};
```