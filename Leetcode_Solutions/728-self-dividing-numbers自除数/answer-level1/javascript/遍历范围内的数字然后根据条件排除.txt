### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 */
var selfDividingNumbers = function(left, right) {
    //判断数字n的各个位是否能被n整除
    const isSelfDevidable = n => {
        const m = n;
        let flag = true;
        while(n>1){
            if(m%(n%10)!=0)return false; //如果不能马上返回false，也就是不符合要求
            n=Math.floor(n/10);   /*继续获取下一位*/
        }
        return true; //到这里就表示这个数各位都能被n整除，返回true
    }

    const res = [];
    while(left<=right){
        if(left%10==0){left++; continue;}; //如果这个数里包含0，即不符合要求
        if(left<10)res.push(left); //如果这个数小于10，肯定符合要求，所以加入结果集
        else if(isSelfDevidable(left))res.push(left); //如果这个数>10，就判断它是不是自除数
        left++; //获取下一个数
    }
    return res;
};
```