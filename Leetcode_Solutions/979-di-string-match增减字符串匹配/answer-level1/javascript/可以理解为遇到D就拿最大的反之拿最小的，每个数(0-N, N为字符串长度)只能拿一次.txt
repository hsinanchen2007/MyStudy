### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {number[]}
 */
var diStringMatch = function(S) {
    const res = [];
    const arr = [];
    let l = 0;
    while(l<=S.length){ //初始化数组，元素为0-S.length
        arr.push(l);
        l++;
    }
    for(let s of S){
        if(s=='I'){
            res.push(arr.splice(0, 1)); //拿第一个也就是最小那个
        }else{
            res.push(arr.splice(arr.length-1, 1)); //拿末尾那个就是最大那个
        }
    }
    res.push(...arr);//剩下最后一个放在结果集的末尾
    return res;
};
```