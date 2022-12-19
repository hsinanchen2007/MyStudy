
### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
if (A.length==0){
            return false;
        }
        int sum = 0;
        int j = -1;
        int k = -1;
        for(int i=0;i<A.length;i++){
            sum = sum + A[i];
        }
        if (sum % 3==0){
            int temp = 0;
            for(int i=0; i<A.length-2;i++){
                temp = A[i] + temp;
                if (temp == sum/3){
                    j = i;
                    break;
                }
            }
            if (j==-1){
                return false;
            }else{
                temp = 0;
                for(int i=j + 1; i<A.length-1;i++){
                    temp = temp + A[i];
                    if (temp==sum/3){
                        k = i;
                    }
                }
                if (k==-1){
                    return false;
                }else{
                    return true;
                }
            }
        }else{
            return false;
        }
    }
}
```