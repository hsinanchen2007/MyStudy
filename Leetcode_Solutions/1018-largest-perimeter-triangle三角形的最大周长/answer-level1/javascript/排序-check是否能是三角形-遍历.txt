### 解题思路
 * 基本思路是首先排序，检查哪些可以组成三角形，然后遍历查找寻找出最大周长
 * 时间复杂度主要取决于sort函数的时间复杂度
 * 空间复杂度:O(1)

### 代码

```javascript
const largestPerimeter = A=>{
    A.sort((a,b)=>a-b);
    let res=0;
    for(let i=0;i<A.length-2;i++){
        if (A[i]+A[i+1]>A[i+2]){
            if(A[i]+A[i+1]+A[i+2]>res){
                res=A[i]+A[i+1]+A[i+2];
            }
        }
    }
    return res;
};
```