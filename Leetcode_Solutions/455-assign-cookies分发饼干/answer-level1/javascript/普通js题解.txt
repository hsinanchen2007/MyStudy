### 解题思路
此处撰写解题思路

### 代码
首先 将 两个数组进行降序排列，优先满足胃口最大的。
当满足时 则到下一个饼干，一直到所有人被满足或者饼干派送完
```javascript
/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
    let g1 = g.sort((a,b)=>b-a);
    let s1 = s.sort((a,b)=>b-a);
    
    let i = 0;
    for( let g of g1){
        if(i===s1.length){
            break
        }
        if(g<=s1[i]){
            i++
        }
    }
    console.log('输出===>',i)
    return i
};
```