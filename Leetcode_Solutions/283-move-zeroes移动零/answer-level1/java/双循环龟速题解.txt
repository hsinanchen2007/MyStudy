### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int i =0;
        boolean a =true;
        for(;;){
            for(int j = i;j<nums.length;j++){
                if(nums[j]!=0){
                    a = false;
                    if(nums[i] == 0&&i!=j){
                        nums[i] = nums[j];
                        nums[j] = 0;
                    }
                    break;
                }
            }
            if(a){return;}
            i++;a = true;
        }
    }
}
```