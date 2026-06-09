### 解题思路
因为军人在每一行都排在前，因此遇到第一个平民时j的值就是该行战斗力
power[j,i]的值表示第i行的战斗力为j,
### 代码

```javascript
/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {number[]}
 */
var kWeakestRows = function(mat, k) {
    let power=[];let result=[];
    for(i=0;i<mat.length;i++){
        let count=0;
        for( j=0;j<mat[0].length;j++){
            if(mat[i][j]==0) break;//因为军人在每一行都排在前，因此遇到第一个平民时j的值就是该行战斗力
        }
        power.push([j,i]);
    }console.log(power);
    power.sort(function(a,b){
        if(a[0]-b[0]==0){
            return a[1]-b[1];
        }
        return a[0]-b[0];
    });

    for(i=0;i<k;i++){
        result.push(power[i][1]);
    }
    return result;
  //return arr.slice(0,3);
};
```