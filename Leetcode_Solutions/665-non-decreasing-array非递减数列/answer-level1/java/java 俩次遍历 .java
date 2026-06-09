### 解题思路
此处撰写解题思路
java 俩次遍历 
第一次纠正一次逆序
再出现 逆序就不是非递减数列
### 代码

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        for ( int i = 0; i < nums.length-1; i++ ) {
            // 第一次出现 逆序 纠正逆序
            if ( nums[i] > nums[i+1]){
                // [3,3,2,4] => [3,3,3,4] , [1,3,2,2] => [1,2,2,2]
                if ( i > 0 && nums[i-1] >= nums[i + 1] ) nums[i+1] = nums[i];
                else nums[i] = nums[i+1];
                break;
            }
        }
        // 如果还有逆序 返回false
        for ( int i = 0; i < nums.length-1; i++ ) {
            if ( nums[i] > nums[i+1]){
                return false;
            }
        }
        return true;
    }
}
```