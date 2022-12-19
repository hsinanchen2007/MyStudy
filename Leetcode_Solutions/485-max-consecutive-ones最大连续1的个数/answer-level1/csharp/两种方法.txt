```
public class Solution {
    public int FindMaxConsecutiveOnes(int[] nums) {
        // string str = String.Join("",nums);
        // string[] arr = str.Split("0");
        // int num = 0;
        // for(int i = 0;i<arr.Length;i++){
        //     if(arr[i].Length > num){
        //         num = arr[i].Length;
        //     }
        // }

        int total = 0;
        int num = 0;
        for(int i = 0;i<nums.Length;i++){
            if(nums[i] == 0){
                if(total > num){
                    num = total;
                }
                total = 0;
            }else{
                total+=1;
            }
        }
        if(total > num){
            num = total;
        }
        return num;
    }
}
```