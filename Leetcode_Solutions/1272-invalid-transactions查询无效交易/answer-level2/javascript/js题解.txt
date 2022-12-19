### 解题思路
1.遍历比较，记录命中项，可能会多次触发，set保存以去重
2.根据记录从数组中取值，返回

### 代码

```javascript
/**
 * @param {string[]} transactions
 * @return {string[]}
 */
var invalidTransactions = function(transactions) {
    let tra = transactions.map(v=>{//转化数组方便取值
        return v.split(',')
    })
    let indexSet = new Set();//保存多条件触发项，去重
    for(let i = 0;i<tra.length;i++){
        if(tra[i][2]>1000){
            indexSet.add(i);//触发条件1
        }
         for(let j = i+1;j<tra.length;j++){//触发条件2
             if(tra[i][0] === tra[j][0] && Math.abs(tra[i][1]-tra[j][1])<=60 && tra[i][3] !== tra[j][3]){
                 indexSet.add(i)
                 indexSet.add(j)
             }
         }
    }
    return Array.from(indexSet).map(i=>{//返回转化数组
        return tra[i].join(',')
    })
};
```