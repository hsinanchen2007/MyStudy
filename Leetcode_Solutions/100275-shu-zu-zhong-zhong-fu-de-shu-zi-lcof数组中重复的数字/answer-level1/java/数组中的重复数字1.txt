### 解题思路
哈希

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
       int[] array=new int[100000];
       int i;
       for(i=0;i<nums.length;i++){
           array[nums[i]]++;
           if(array[nums[i]]==2){
               break;
           }
       }
       //System.out.println(nums[i]);    
        return nums[i];
    }
}
```