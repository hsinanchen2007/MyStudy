### 解题思路
![image.png](https://pic.leetcode-cn.com/3929d4fad9e80fdd5add15e0be5319620287edbfd53a01223023b28afa941cf8-image.png)
- 通过 Reduce 叠加器得到总和
- 通过遍历判断 对 flag 进行验证是否是分成三段，如果flag是 3 说明数组分成三段
- 

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {boolean}
 */
var canThreePartsEqualSum = function(A) {
    let sum = (A.reduce((pre,next) => {return pre + next}))/3
    let temp = 0
    let flag = 0
    for(let i = 0; i < A.length; i++){
        temp += A[i]
        if(temp === sum){
            flag++
            temp = 0
            // sum 是 每一部分的和
            // 预防一种情况是 如果前面两端已经等于 sum， 如果最后那一部分整体都等于 sum  那么也返回 ture
            //类似 [10, -10, 10, -10, 10, -10, 10, -10]
            if(flag === 3){
                let tmp = 0
                for(let j = i + 1; j< A.length; j++){
                    tmp += A[j]
                }
                if(tmp === sum) return true
            }
        }
    }
    return flag === 3 ? true : false
};
```