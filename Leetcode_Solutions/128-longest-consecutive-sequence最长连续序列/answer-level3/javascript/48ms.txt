### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
// 计算包含元素n的连续序列长度
var longestConsecutive = function(nums) {
    if(nums.length <= 1){ return nums.length; }
    let leng1=0;
    const s = new Set(nums);// 去除重复值
    for(let iterator of s){
        let leng2 = 0;
        let i = iterator;
        while(s.has(i)){ // 前
            s.delete(i);
            leng2 += 1;
            i -= 1;
        }
        i = iterator+1;
        while(s.has(i)){ // 后
            s.delete(i);
            leng2 += 1;
            i += 1;
        }
        if(leng1<leng2){ leng1=leng2; }
    }
    return leng1;
};
```