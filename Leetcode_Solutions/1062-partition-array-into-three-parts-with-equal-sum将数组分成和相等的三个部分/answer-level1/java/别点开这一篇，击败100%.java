### 解题思路
如果可以被分成三部分，每一步都的大小都是 sum / 3

只要前两部分都等于sum / 3，那最后一部分也会等于sum / 3，所以没必要再计算最后的那部分。

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {

        int sum = 0;
        for(int num : A) sum += num;

        int temp = 0, count = 0;

        for(int i = 0; i < A.length; i++){
            temp += A[i];
            if(temp == (sum / 3)){
                temp = 0;
                count++;
            }
            if(count == 2 && i < A.length - 1){
                return true;
            }
        }
        return false;

    }
} 
```