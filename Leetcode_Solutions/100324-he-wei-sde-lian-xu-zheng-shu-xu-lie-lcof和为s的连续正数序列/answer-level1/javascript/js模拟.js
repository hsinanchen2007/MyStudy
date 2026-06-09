### 解题思路
注意判断个数为奇数还是偶数

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    
    let res=[];
    for(let i=2;i<target/2;i++){
        let avg=Math.floor(target/i);
        let left,right;
        if(i%2===0){
            left=avg - i/2 +1;
            right=avg + i/2;
        }else if(i%2===1){
            left=avg - (i-1)/2 ;
            right=avg + (i-1)/2;
        }
        if(left>0 && (left+right)*i===2*target){
            let tem=[];
            for(let i=left;i<=right;i++){
                tem.push(i);
            }
            res.push(tem);
        }
    }
    return res.sort((a,b)=>{
        return a[0]-b[0];
    });
};
```