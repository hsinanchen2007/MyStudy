### 解题思路
看代码

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {

    let res = 0;
    let i = 0;
    let arry = [];
    while(i<s.length){
        //判断数组是否存在
        if(arry.includes(s[i])){
            //如果存在就把第一个删除
            arry.shift()
            //继续遍历
            continue
        }else{
            arry.push(s[i])
        }
        //返回res和arr长度最大值
        res = Math.max(res,arry.length);
        i++
    }

    return res
};
```