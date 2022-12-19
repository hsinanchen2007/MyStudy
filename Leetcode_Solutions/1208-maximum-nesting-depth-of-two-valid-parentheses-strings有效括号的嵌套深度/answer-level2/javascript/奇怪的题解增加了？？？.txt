![image.png](https://pic.leetcode-cn.com/f7407527907e92532dabacf004c6680b94cdf8af25db451f4e6d0cd4752b005f-image.png)

### 解题思路
???

### 代码

```javascript
/**
 * @param {string} seq
 * @return {number[]}
 */
var maxDepthAfterSplit = function(seq) {
    let s1 = s2 = 0,res=[];
    for(let i=0;i<seq.length;i++){
        if(seq[i] === '('){
            if(s1 <= s2){
                s1++;
                res.push(0);
            }else{
                s2++;
                res.push(1);
            }
        }else{
            if(s1 <= s2){
                s2--;
                res.push(1);
            }else{
                s1--;
                res.push(0);
            }
        }
    }
    return res;
};
```