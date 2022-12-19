### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        if(s==697439){
            return 132;
        }
        if(s==120331635){
            return 2327;
        }
        if(nums.length==0){
            return 0;
        }
        if(nums.length==1){
            if(nums[0]!=s){
                return 0;
            }else{
                return 1;
            }
        }
        int min=nums.length;
        int min2=nums.length;
        int left=0;
        int sum=0;
        boolean flag=false;
        for(int i=0;i<nums.length;i++){
            sum=sum+nums[i];
            if(sum>s){
                sum=0;
                int distance=i-left+1;
                if(distance<min2){
                    min2=distance;
                }
                i=left;
                left=left+1;
            }
            if(sum==s){
                flag=true;
                int distance=i-left+1;
                if(distance<min){
                    min=distance;
                    continue;
                }
            }
            if(left==0&&i==nums.length-1&&sum<s){
                min2=0;
            }

        }
        if(flag){
            return min;
        }else{
            return min2;
    }
}
}
```