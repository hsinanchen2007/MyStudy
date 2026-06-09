x每次取两个数中小的那个求和，首先排序，然后按两两分组，取小的那个求和即可
```
class Solution {
    public int arrayPairSum(int[] nums) {
        int i = 0;
        int coun = 0;
        Arrays.sort(nums);
        while(i < nums.length){
            coun = coun + nums[i];
            i = i + 2;
            if(i == nums.length)
                break;
        }
        return coun;
    }
}
```
