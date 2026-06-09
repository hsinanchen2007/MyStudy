### 解题思路
使用哈希表，键值对

### 代码

```javascript
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
    const l1=J.length,l2=S.length;
    let count=0;
    const obj={};
    for(let i=0;i<l1;i++)
    {
      obj[J.charAt(i)]=1;
    }
    for(let i=0;i<l2;i++)
    {
        if(obj[S.charAt(i)])
        {
            count++;
        }
    }
    return count;
};
```