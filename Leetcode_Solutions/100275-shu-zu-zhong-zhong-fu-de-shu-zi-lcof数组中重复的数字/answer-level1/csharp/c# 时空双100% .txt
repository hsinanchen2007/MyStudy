因为数组长度限制在100000,所以直接新建一个长度100000数组arr,如果某个数字num出现,arr[num]的值+1,因此只要arr[num]>1,就说明它重复了.第一次双百,有点开心
```
public class Solution {
    public int FindRepeatNumber(int[] nums) {
        int[] arr=new int[100000];
        for(int i=0;i<nums.Length;i++){
            arr[nums[i]]++;
            if(arr[nums[i]]>1)
                return nums[i];
        }
        return 0;
    }
}
```
