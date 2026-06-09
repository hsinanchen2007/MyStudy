### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        //一次遍历
        int len = A.length;
        int[] a = new int[len];
        int j=0,k=1;
        while(j<len && k<len){
            for(int i=0; i<len; i++){
                if(A[i]%2==0){
                    a[j]=A[i];
                    j+=2;
                }
                else{
                    a[k]=A[i];
                    k+=2;
                }
            }
        }
        return a;
    }
}
```