### 解题思路


### 代码

```java
class Solution {
    public static void main(String[] args) {
        Solution s = new Solution();
        int nums[] = {0,1,2,2,3,0,4,2};
        int val = 2;
        System.out.println("\n"+s.removeElement(nums,val));

    }
    public int removeElement(int[] nums, int val) {
        int result = 0;
        int i = 0;
        for(int j = 0;j < nums.length;j++){
            if(nums[j]!=val){
                nums[i] = nums[j];
                i++;
                //nums[i] = nums[j];
            }
        }
        //result = i+1;
        return i;
    }


}
```