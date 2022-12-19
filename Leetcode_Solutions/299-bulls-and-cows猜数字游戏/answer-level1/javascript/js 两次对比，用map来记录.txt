### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} secret
 * @param {string} guess
 * @return {string}
 */
var getHint = function(secret, guess) {
    // 记录A的数量
    let countA = 0;
    // 记录B的数量
    let countB = 0;
    // 用map来记录在secret中没有匹配到的数
    let map = new Map();
    // 将guess中除了已经匹配到的数都放进此数组中
    let arr = [];

    for(let i=0; i<secret.length; i++){
        if(secret[i] == guess[i]) countA++;
        else{
            // key：secret[i]，value：该数出现的次数
            // 如果map中有该数，更新该数相对应的值
            map.has(secret[i]) ? map.set(secret[i],map.get(secret[i])+1) : map.set(secret[i],1);
            arr.push(guess[i]);
        }
    }

    for(let j=0; j<arr.length; j++){
        if(map.has(arr[j])){
            // 若是map.get(arr[j])的值大于1，那么说明该数出现了多次，则需更新该数的value；若为1，那么将该数从map中删除，避免重复对比
            map.get(arr[j]) > 1 ? map.set(arr[j],map.get(arr[j])-1) : map.delete(arr[j]);
            countB++
        }
    }

    return(countA+'A'+countB+'B')
};