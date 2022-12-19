### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        int ret = 0 ;

        for (int i=0 ; i< 32 ; i++) {
            int bit = (1 << i) ;
            int count = 0 ;
            for (int j=0 ;j <nums.length ;j++ ) {
                if ((nums[j] & bit) != 0)
                    count ++ ;
            }
            if (count % 3 != 0)
                ret |= bit ;

        }
        return ret ;
    }
}
```