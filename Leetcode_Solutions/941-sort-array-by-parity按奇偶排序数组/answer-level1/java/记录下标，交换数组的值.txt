### 解题思路
记录偶数下标，交换数组的值

### 代码

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        //在此之前的都是偶数
        int index=0;
        for(int i=0;i<A.length;i++){
            if(A[i]%2==0){
                //找到一个偶数，将他与index对应的值相交换
                int k=A[index];
                A[index]=A[i];
                A[i]=k;
                index++;
            }
        }

        return A;
    }
}
```