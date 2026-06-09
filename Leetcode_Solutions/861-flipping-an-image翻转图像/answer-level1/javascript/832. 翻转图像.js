### 解题思路
翻转之后直接取反

### 代码

```javascript
/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var flipAndInvertImage = function(A) {
    for(let r = 0; r < A.length; r++){
        let c = 0, rc = A.length - 1
        
        while(c < rc){
            //交换
            let tmp = A[r][c]
            A[r][c] = A[r][rc]
            A[r][rc] = tmp
            
            //取反
            A[r][c] = Number(!A[r][c])
            A[r][rc] = Number(!A[r][rc])

            c++
            rc--
        }
        //奇数个
        if(c === rc){
            A[r][c] = Number(!A[r][c])
        }
    }
    return A
};
```