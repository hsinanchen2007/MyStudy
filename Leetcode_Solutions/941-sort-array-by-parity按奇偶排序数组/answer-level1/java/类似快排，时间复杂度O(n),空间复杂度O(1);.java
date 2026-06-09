### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int low=0;
        int high=A.length-1;
        int temp=A[0];
        if(high<1)
           return A;
        while(low<high){
            while(low<high&&A[high]%2!=0)  high--;        
            temp=A[high];
            while(low<high&&A[low]%2==0) low++;       
            A[high]=A[low];
            A[low]=temp;
        }
        return A;
    }
}
```