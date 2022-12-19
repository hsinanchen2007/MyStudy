### 解题思路
按照***题43思路完成如下，就是不明白为什么一定取模才行？

### 代码

```javascript
/**
 * @param {number} d
 * @param {number} f
 * @param {number} target
 * @return {number}
 */
const mod = Math.pow(10,9)+7;
var numRollsToTarget = function(d, f, target) {
    var df = [];
    for(let i=0;i<f;i++){
        df[i] = 1;
    }
    for(let i=1;i<d;i++){
        let newDf = [];
        for(let k =0;k<(i+1)*f;k++){
            newDf[k] = 0;
            for(let j=Math.max(0,k-f);j<Math.min(k,df.length);j++){
                newDf[k] =(newDf[k] + df[j])%mod;
            }
        }
        df = newDf;
    }

    return df[target-1] || 0;
};

```