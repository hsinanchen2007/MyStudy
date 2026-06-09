### 解题思路
![image.png](https://pic.leetcode-cn.com/6bfac1268a28fd3390657a1782b17982f64321e01c22226ca2c32b6edf3643fc-image.png)
1、将两个数组都排序，从小到大；
2、若是胃口大于尺寸，那么寻找下一个尺寸，直到胃口<=尺寸为止


### 代码

```javascript
/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
    // i：胃口的索引，j：尺寸的索引
    let [index,i,j] = [0,0,0];
    g.sort((a,b)=>a-b);
    s.sort((a,b)=>a-b);
    while(i<g.length && j<s.length){
        if(g[i] <= s[j]){ // 若是当前尺寸满足胃口，进行下一组对比
            index++;
            i++;
            j++;
        }else if(g[i] > s[j]){ // 当前尺寸不满足胃口，对比下一个尺寸
            j++;
        }
    }
    return index;
};
```