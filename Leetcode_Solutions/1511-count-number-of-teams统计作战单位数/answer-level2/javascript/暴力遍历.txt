### 解题思路

 * 遍历一遍，i,j,k 先做>的情况，修改支持<
 * count
 * 满足 i > j > k 同时 rating[i] > rating[j] > rating[k]
 * i范围 0 ~ len - 3, j: i + 1 ~ len - 2 k:j + 1 ~ len - 1
 
### 代码

```javascript
/**
 * 遍历一遍，i,j,k 先做>的情况，修改支持<
 * count
 * 满足 i > j > k 同时 rating[i] > rating[j] > rating[k]
 * i范围 0 ~ len - 3, j: i + 1 ~ len - 2 k:j + 1 ~ len - 1
 * 
 * @param {number[]} rating
 * @return {number}
 */
var numTeams = function(rating) {
    let count = 0;
    const len = rating.length;
    if(len < 3) return count;

    //大于 小于
    for(let i = 0; i < len - 2; i++) {
        for(let j = i + 1; j < len - 1; j++) {
            if(rating[i] > rating[j]) {
                for(let k = j + 1; k < len; k++) {
                    if(rating[j] > rating[k]){
                        count ++;
                    }
                }
            }
            
            if(rating[i] < rating[j]) {
                for(let k = j + 1; k < len; k++) {
                    if(rating[j] < rating[k]){
                        count ++;
                    }
                }
            }
        }
    }

    return count;
};
```