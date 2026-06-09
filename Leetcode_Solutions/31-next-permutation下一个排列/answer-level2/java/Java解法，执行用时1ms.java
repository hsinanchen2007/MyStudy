### 解题思路
解题规则：
假设i=len-1，数组从后到前走：
1. 发现后一位大于前一位，既nums[i]>nums[i-1];
2. 重排后一位到最后,即数组nums [i,len-1]；
3. 从当前位置向后找刚好大于nums[i-1]的数，然后交换位置；

### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
        int len = nums.length;
        if(len < 1){
            return;
        }
        for(int i=len-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                //System.out.println("nums[i] = " + nums[i]);
                for (int m=i,n=len-1;m<n;m++,n--){
                    int temp = nums[m];
                    nums[m] = nums[n];
                    nums[n] = temp;
                    //System.out.println("nums[m] = " + nums[m]);
                    //System.out.println("nums[n] = " + nums[n]);
                }
                for(int j=i;j<len;j++) {
                    if(nums[i-1]<nums[j]) {
                        int temp = nums[i - 1];
                        nums[i - 1] = nums[j];
                        nums[j] = temp;
                        //System.out.println("nums[i - 1] = " + nums[i - 1]);
                        //System.out.println("nums[j] = " + nums[j]);
                        break;
                    }
                }
                return;
            }
        }
        for (int m=0,n=len-1;m<n;m++,n--){
            int temp = nums[m];
            nums[m] = nums[n];
            nums[n] = temp;
        }
    }
}
```