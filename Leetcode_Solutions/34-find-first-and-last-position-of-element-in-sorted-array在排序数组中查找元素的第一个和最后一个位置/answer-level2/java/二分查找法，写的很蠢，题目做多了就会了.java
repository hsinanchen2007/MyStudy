### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
int[] arr = new int[]{-1,-1};
        if(nums.length==0||nums==null){
            return arr;
        }
        if(nums.length==1&&nums[0]!=target){
            return arr;
        }
        if(nums.length==1&&nums[0]==target){
            return new int[]{0,0};
        }
        int i= 0;
        int j= nums.length-1;
        while (i<=j){
            if(nums[i]==target){
                arr[0] = i;
            }else {
                i++;
            }
            if(nums[j]==target){
                arr[1] = j;
            }else {
                j--;
            }
            if(arr[0]!=-1&&arr[1]!=-1){
                if(nums[arr[0]]==target&&nums[arr[1]]==target){
                    return arr;
                }
            }
        }
        return arr;
    }
}
```