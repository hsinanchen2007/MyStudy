### 解题思路
规规矩矩的二分查找

### 代码

```java
class Solution {
    public int arrangeCoins(int n) {
        int low = 1;
        int high = n;

        while(low <= high){
            int mid = low + ((high - low)>>1);
            if(find(mid, n))
                high = mid -1;
            else
                low = mid + 1;
        }

        return high;
    }

    boolean find(int mid, int target){
        long sum = (1+ (long)mid)* (long)mid /2;
        return sum > target;
    }
}
```