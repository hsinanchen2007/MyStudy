### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int totalsum = 0;
        for(int i = 0; i < A.length; i++){
            totalsum += A[i];
        }
        if(totalsum % 3 != 0){
            return false;
        }
        int target = totalsum / 3;
        int cur = 0, i = 0;
        while(i < A.length){
            cur += A[i];
            if(cur == target){
                break;
            }
            i++;
        }

        if(cur != target){
            return false;
        }

        int j = i + 1;
        while(j < A.length - 1){
            cur += A[j];
            if(cur == target * 2){
                return true;
            }
            j++;
        }
        return false;
    }
}
```