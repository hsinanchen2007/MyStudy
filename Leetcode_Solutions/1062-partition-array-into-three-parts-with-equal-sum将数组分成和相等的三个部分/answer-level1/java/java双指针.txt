### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for(int i: A){
            sum += i;
        }
        if(sum % 3 != 0 || A.length < 3){
            return false;
        }
        int tmp = sum/3;
        int left = 0;
        int right = A.length - 1;
        int leftsum = A[left];
        int rightsum = A[right];
        while(left + 1 < right){
            if(leftsum == tmp && rightsum == tmp){
                return true;
            }
            if(leftsum != tmp){
                left++;
                leftsum += A[left];
            }
            if(rightsum != tmp){
                right--;
                rightsum += A[right];
            }           
        }
        return false;
    }
}
```