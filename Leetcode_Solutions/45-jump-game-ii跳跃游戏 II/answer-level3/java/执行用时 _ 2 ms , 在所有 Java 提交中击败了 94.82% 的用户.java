### 解题思路
 就是每次走的时候，判断这次步数+下次能走的步数最大，按照这个走法，走的步数最少。

### 代码

```java
class Solution {
    public int jump(int[] nums) {
        if(nums.length==1){
            return 0 ;
        }
        int count = 0;
        int currentPosition = 0;
        while(currentPosition<=nums.length-1&&nums[currentPosition]+currentPosition<nums.length-1){
            int maxStep = nums[currentPosition];
            int nextStep = currentPosition+1;
            int max = 0;
            for(int i=1;i<=maxStep;i++){
                if(nums[currentPosition+i]!=0 && nums[currentPosition+i]+i>max){
                    max = nums[currentPosition+i]+i;
                    nextStep = currentPosition+i;
                }
            }
            currentPosition = nextStep;
            count++;
        }
        return count+1;
    }
}
```