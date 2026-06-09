### 解题思路
题目的要求就是希望所有不同的数字出现次数能有相同的最大公约数，所以我们通过辗转相除法，将统计数组的前两个值a,b进行比较，其中会用到递归，获得最大公约数后与统计数组里剩余的值继续比较

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
    let gcb = (a,b)=>{
        //如果b为0，说明a就是b的最大公约数，否则继续用辗转相除法
        if(b==0){
            return a
        } else {
            return gcb(b,a%b)
        }
    }
    let str = deck.toString().split(','),group = [],tmp = {}
    //用对象将各卡牌次数存入
    str.forEach(item=>{
        tmp[item]=tmp[item]?tmp[item]+1:1
    })
    // for(let i in tmp){//循环tmp属性
    //     group.push(tmp[i])//将tmp属性对应的值放进数组group
    // }
    //获取tmp数组可枚举属性的值，也就分组的次数
    for (let v of Object.values(tmp)) {
        group.push(v)
    }
    //当group的长度大于1，说明至少有2组数可以求最大公约数
    while(group.length>1){
        // a和b的值取出比较
        let a = group.shift(),b = group.shift(),v = gcb(a,b)
        //如果a和b的最大公约数不为1，就继续求最大公约数
        if(v==1){
            return false
        } else {
            group.unshift(v)
        }
    }
    return group.length>0?group[0]>1:false
};
```