### 解题思路
`       for(int i=Rs.length-2;i>=0;i--){`
这个循环要注意，是可以`=0`的

### 代码

```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] output = new int[nums.length];
        
        // for(int i=0;i<output.length;i++){
        //     output[i] = 1;
        //     for(int j=0;j<nums.length;j++){
        //         if(j == i) continue;
        //         output[i] = output[i] * nums[j];
        //     }
        // }
        if(nums.length == 1) return nums;
        
        int[] Ls = new int[nums.length];
        Arrays.fill(Ls, 1);
        int[] Rs = new int[nums.length];
        Arrays.fill(Rs, 1);
        for(int i=1;i<Ls.length;i++){
            Ls[i] = Ls[i-1] * nums[i-1]; 
        }
        for(int i=Rs.length-2;i>=0;i--){
            Rs[i] = Rs[i+1] * nums[i+1];
        }
        for(int i=0;i<nums.length;i++){
            output[i] = Ls[i] * Rs[i];
        }

        return output;
    }
}
```