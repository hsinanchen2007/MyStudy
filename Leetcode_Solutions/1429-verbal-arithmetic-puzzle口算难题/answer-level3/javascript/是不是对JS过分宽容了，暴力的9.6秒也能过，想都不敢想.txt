一直在想有没有优雅点的解题方式，纠结到了竞赛结束，看到众人的答案，原来都是暴力深搜+剪枝。

![屏幕快照 2019-12-29 13.25.11.png](https://pic.leetcode-cn.com/308e4812315f71bcb378f27507ac0620e33e570920b2c2e86733934689094021-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-29%2013.25.11.png)

```
var isSolvable = function(words, result) {
    const table = {};
    let fac = 1;
    for(let i = result.length-1;i>=0;i--){
        const c = result.charAt(i);
        if(table[c]){
            table[c].r += fac;
        } else {
            table[c] = {r:fac,m:0};
        }
        if(i == 0){
            table[c].m = 1;
        }
        fac *=10;
    }
    for(let i = 0;i<words.length;i++){
        const word = words[i];
        fac = 1;
        for(let j = word.length-1;j>=0;j--){
            const c = word.charAt(j);
            if(table[c]){
                table[c].r -= fac;
            } else {
                table[c] = {r:0-fac,m:0};
            }
            if(j == 0){
                table[c].m = 1;
            }
            fac *=10;
        }
    }
    const keys = Object.keys(table);
    const usedNum = new Array(10);
    usedNum.fill(0);
    const numMap = {};
    function loop(index){
        if(index == keys.length){
            let result = 0;
            for(let key in table){
                const val = numMap[key];
                result += val * table[key].r;
            }
            return result == 0;
        }
        const key = keys[index];
        for(let i = table[key].m;i<10;i++){
            if(usedNum[i] == 0){
                usedNum[i] = 1;
                numMap[key] = i;
                if(loop(index+1,usedNum,numMap)){
                    return true;
                }
                usedNum[i] = 0;
            }
        }
        return false;
    }
    return loop(0);
};
```
