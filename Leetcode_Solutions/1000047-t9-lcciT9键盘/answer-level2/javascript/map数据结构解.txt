### 解题思路
使用map数据结构直接可以对应kv搜索
再遍历使用includes判断即可
![image.png](https://pic.leetcode-cn.com/1e06db46957f188736cf7f0a93b866f824638e9f16ad84c4e96342515ec554bc-image.png)

### 代码

```javascript
/**
 * @param {string} num
 * @param {string[]} words
 * @return {string[]}
 */
var getValidT9Words = function(num, words) {
    let map = new Map()
    let result = new Array()
    map.set(2,['a','b','c'])
    map.set(3,['d','e','f'])
    map.set(4,['g','h','i'])
    map.set(5,['j','k','l'])
    map.set(6,['m','n','o'])
    map.set(7,['p','q','r','s'])
    map.set(8,['t','u','v'])
    map.set(9,['w','x','y','z'])
     words.map(x=>{
        if(x.length !== num.length){
            return false
        }
        for(let i = 0;i<num.length;i++){
            if(!map.get(Number(num[i])).includes(x[i])){
                break
            }
            if(i === num.length-1){
                result.push(x)
            }
        }
    })
    return result
};
```