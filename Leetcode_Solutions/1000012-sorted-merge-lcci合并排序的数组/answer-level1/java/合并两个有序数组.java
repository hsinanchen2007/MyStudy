### 解题思路
此处撰写解题思路
### 由于A无限长度，将ABh从后往前，依次比较，谁大从A的末尾开始放起
#### 此题主要注意，数组越界的问题。注意 i j 到0的情况

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
       int i=m-1;int j=n-1;
       int index=m+n-1;

       while(index>=0){
           if(i<0){
                A[index--]=B[j--];
            }
            else if(j<0){
                A[index--]=A[i--];
            }
            else if(j>=0&&A[i]<B[j]){
                 A[index--]=B[j--];}
            else if(i>=0&&A[i]>=B[j]){
                A[index--]=A[i--];
            }
            
       }


    }
}
```