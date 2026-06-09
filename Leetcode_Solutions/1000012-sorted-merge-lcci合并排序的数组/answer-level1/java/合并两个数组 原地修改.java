### 解题思路
一个普通的思路，将B中元素依次和A中元素比较，找到插入位置，就将A中剩余元素都顺序后移一位

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int i=0;//指向A数组元素
        int j=0;//指向B数组元素
        
        while(j<n){//遍历B数组，初始i、j都指向第一个元素
        	if(B[j]<A[i]||m+j==i){//如果B数组的元素小于A数组元素，或者A中数组均遍历完
                for(int k=m+n-1;k>i;k--){
                    A[k]=A[k-1];//将i开始的元素依次后移一位
                }
                A[i]=B[j];//空出来的位置插入j处的元素
                j++;//j指向B的下一个元素
            }else{
                if(i==m+n-1) break;
                i++;//否则将i指向A的下一个元素
            }
        }
    }
}
```