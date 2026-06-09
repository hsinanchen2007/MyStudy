### 解题思路
抓破头皮才搞定
第一次以为不断迭代加一就行 
完事竟然还超时了
于是就不一次加一个了
咱判断如果大于等于 直接让它比前一个大一 加多少个值
直接算在总计数里面

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
    var minIncrementForUnique = function(A) {
    if(A.length==0)return 0
        A.sort((a,b)=>a-b)
        let cnt = 0
        for(let i=0;i<A.length-1;i++){
            if(A[i]>=A[i+1]){
                cnt += (A[i] -A[i+1] + 1)
                A[i+1] = A[i] + 1
            }
        }
        return cnt
    };
 
```