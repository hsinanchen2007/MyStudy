### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        boolean flag=true;//只有一次修改的机会
        for(int i=1;i<nums.length;i++){
            if(nums[i-1]>nums[i]){
                if(flag)
                    flag=false;
                else return false;
                if(i>1&&nums[i]<nums[i-2]){//当前元素比前2个元素都小，应该把当前元素赋值为前一个元素
                    nums[i]=nums[i-1];
                }else {//把前一个元素修改为当前元素
                    nums[i-1]=nums[i];
                }
            }
        }
        return true;
    }
}
```