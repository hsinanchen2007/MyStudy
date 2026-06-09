### 解题思路
1.创建一个数组，其中P[i] = A[0]+A[1]+ ...+ A[i]（如果A[i]没有负数可以保证P[i+1]>P[i]）则本题转换为P[y]-P[x]>=k且y-x最小的值
2.使用双端队列保存滑动窗口值（js可以直接使用数组），每次循环在队列尾添加本次循环的下标j，记为滑动窗口末尾值，为了保证P[j+1]>P[j],因此while(queue.length!=0 && P[queue[queue.length-1]] >=P[j]){queue.pop()}，当queue.length!=0 && P[j]-P[queue[0]]>=K时判断最新的滑动窗口初始值

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var shortestSubarray = function(A, K) {
    let P = new Array(A.length+1).fill(0)
    for(let i=0;i<A.length;i++){
        P[i+1]= P[i]+A[i]
    }
    let queue=[],min=A.length+1;
    for(let j=0;j<P.length;j++){
        // 上次的和大于本次的和，即P[j-1]>P[j],则不存取本次的j
        while(queue.length!=0 && P[queue[queue.length-1]] >=P[j]){
            queue.pop()
        }
        while(queue.length!=0 && P[j]-P[queue[0]]>=K){
            // 当本次的P[j]>P[滑动窗口初始值]，则取最小长度
            min = Math.min(j-queue[0],min)
            // 并删除滑动窗口初始值，而后重新push进当前j，则滑动窗口上次结束值为初始值，当前j为滑动窗口结束值
            queue.shift()
        }
        queue.push(j)
    }
    return min<A.length+1?min:-1
};
```