```
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    
    
    if(numRows === 0) return [];
    let result = [];
    for(let i=0;i<numRows;i++){
        let temp = [];
        for(let j=0;j<=i;j++){
            if(j>0 && j<i){
               temp.push(result[i-1][j-1]+result[i-1][j])
            }else{
                temp.push(1)
            }
        }
        result.push(temp);
    }

    return result

};
```
