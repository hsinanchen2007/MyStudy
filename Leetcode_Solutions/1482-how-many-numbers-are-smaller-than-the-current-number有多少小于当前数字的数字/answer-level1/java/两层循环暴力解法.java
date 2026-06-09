### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int count=0;
        int[] arr=new int[nums.length];
            for(int i =0;i<nums.length;i++){
                count=0;
                for(int j=0;j<nums.length;j++){
                    if(nums[j]<nums[i]){
                        count++;
                    }
                    
                }
               
                arr[i]=count;
            }
            return arr;
    }
}
```