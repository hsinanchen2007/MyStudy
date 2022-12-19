### 解题思路
1.先排序 2.有重复且不是大小王直接跳错误 3.判定最大差值只要小于4即可

### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
        
        //先排序
        for(int i=0;i<5;i++){
            
            for(int j =i+1;j<5;j++){
                int temp = 0;
                if(nums[i]>nums[j]){
                    temp=nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }else if(nums[i]==nums[j]&&nums[i]!=0){
                //如果有相等的数且不是大小王，直接判定
                    return false;
                }
            }
        }
        //数下大小王
        int n=0;
        for(int k=0;k<5;k++){
            if(nums[k]==0){
                n++;
            }
        }
        //只要满足除去0后，最大差值小于4就行
        if(nums[4]-nums[n]<=4){
            return true;
        }
        return false;
    }
}
```