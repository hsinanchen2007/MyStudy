### 解题思路
先合并，再冒泡排序

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} m
 * @param {number[]} B
 * @param {number} n
 * @return {void} Do not return anything, modify A in-place instead.
 */
var merge = function(A, m, B, n) {
    for(var i=m,j=0;i<m+n;i++){
            A[i]=B[j];
            j++;
    }
     for(i = 0 ;i<m+n-1;i++){
            //第i趟比较
            for(j = 0 ;j<m+n-i-1;j++){
                //开始进行比较，如果arr[j]比arr[j+1]的值大，那就交换位置
                if(A[j]>=A[j+1]){
                    var temp=A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                }
            }

        }
};
```