### 解题思路
此处撰写解题思路
参考了（抄袭）上层的代码，利用了尾递归
### 代码

```javascript
/**
 * @param {number} A
 * @param {number} B
 * @return {number}
 */
var multiply = function(A, B,res = 0,cur = 0) {
    if(!A){
        return res;
    }   
    if(A & 1){
        res += B << cur;
    }
    cur++;
    A>>=1;
    return multiply(A,B,res,cur)
};
```