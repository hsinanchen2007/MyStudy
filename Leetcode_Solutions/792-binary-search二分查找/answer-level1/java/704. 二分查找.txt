
### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if((nums.length==1)&&(target==nums[0]))return 0;
        int left=0;
        int rigth=nums.length-1;
        while(left<=rigth){
            int minIndex=(left+rigth)/2;
            int minValue=nums[minIndex];
            if(minValue<target){
                left=minIndex+1;
            }else if(minValue>target){
                rigth=minIndex-1;
            }else{
                return minIndex;
            }
        }
        return -1;
    }
}
```