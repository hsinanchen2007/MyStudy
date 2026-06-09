### 解题思路
先对源数组进行排序，然后定义两个数组，一个数组记录新集合的第一个值，第二个数组记录模拟值

### 代码

```java
class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        if(nums.length%k!=0){
            return false;
        }
        int len = nums.length/k;
        long[] current = new long[len];
        int[] first = new int[len];
        for(int i=0;i<current.length;i++){
            current[i] = -2147483649L;
        }
        Arrays.sort(nums);
        for(int i=0;i<nums.length;i++){
            for(int j=0;j<current.length;j++){
                if(current[j] == -2147483649L){
                    current[j] = nums[i];
                    first[j] = nums[i];
                    break;
                }
                if(current[j]+1==nums[i] && nums[i]-first[j]<k){
                    current[j] = nums[i];
                    break;
                }
                if(j>=current.length-1){
                    return false;
                }
            }
        }
        return true;
    }
}
```