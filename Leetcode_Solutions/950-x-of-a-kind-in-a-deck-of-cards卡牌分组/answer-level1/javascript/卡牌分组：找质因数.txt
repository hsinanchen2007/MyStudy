### 解题思路
1. 首先是分组，把相同的元素通过一个对象check 存储起来
2. 知道分组中长度最小的组，并计算其长度
3. 如果长度小于2，直接返回false
4. 否则找出改最小长度数值的所有质因数
5. 遍历质因数， 并使用开始的所有组的长度数值（肯定是大于最小长度的）对所有质因数取余
6. 如果有其中任一一个质因数满足让所有的组的长度对其取余后等于0（也可以是说所有长度在改质因数下可以被平均分配），便表示存在这样的组合，返回true

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
    // deck = group * X
    // 分组
    let check = {};
    deck.forEach((item, index) => {
        if(!check[item]){
            check[item] = [];
        }

        check[item].push(item);
    })

    let keys = Object.keys(check);
    let values = Object.values(check);

    let arr = [];
    values.forEach(item=>arr.push(item.length));
    let min = Math.min(...arr); // 找出组中长度最小的组

    if(min < 2) return false;

    // 找出min 的所有质因数
    let zys = []
    for(let i=2; i<= min; i++){
        if(min%i===0) zys.push(i)
    }
    zys.sort((a,b)=>b-a)
    console.log(zys);

    let flag = false;
    zys.forEach(otm=>{
        let res = arr.filter(item=>item%otm !== 0);
        if(res.length > 0){

        }else{
            flag = true;
        }
        
    })
    return flag;
};
```