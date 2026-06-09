### 解题思路
一副牌有三张王是没想到的。

### 代码

```java
class Solution {
    // 两个0，1~13.判断是否是顺子
    public boolean isStraight(int[] nums) {
        if(nums.length != 5)
            return false;
        Arrays.sort(nums);
        int count = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 0){
                count += 1;
                continue;
            }
            else{
                break;
            }
        }
        int i;
        for(i = count; i < nums.length - 1;){
            if(nums[i] + 1 == nums[i+1]){
                i++;
                continue;
            }
            else{
                if(count == 0){
                    return false;
                }
                else{
                    count -= 1;
                    nums[i] += 1;
                }
            }
        }
        if(count > 0)
            return true;
        else if(count == 0 && i == 4)
            return true;
        else
            return false;
    }
}
```