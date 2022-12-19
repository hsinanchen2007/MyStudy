### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result=new ArrayList<>();
        List<Integer> list;
        int temp=0;
        //排序
        for(int i=0; i<nums.length ; i++){
            for(int j=i; j<nums.length ; j++){
                if(nums[i]>nums[j]){
                    temp=nums[i];
                    nums[i]=nums[j];
                    nums[j]=temp;
                }
            }
        }
        for(int j=0 ;j<nums.length-2;j++){
            //排序后首位去重（去掉首位重复的情况）
            if(j>0&&nums[j]==nums[j-1]) {
                continue;
            }
            for(int i =j+1, r=nums.length-1;i<nums.length-1&&r>=j&&i<r ;){
                list=new ArrayList<>(3);
                if(nums[i]+nums[j]==-nums[r]){
                    //末位去重，注意：重复了就将指针向前移动
                    if(r<nums.length-1&&nums[r]==nums[r+1]){
                        r--;
                    }else {
                        list.add(nums[j]);
                        list.add(nums[i]);
                        list.add(nums[r]);
                        result.add(list);
                        //找到则继续
                        i++;r--;
                    }
                }else if (nums[i]+nums[j]>-nums[r]){
                    r--;
                }else {
                    i++;
                }
            }
        }
        return result;
    }
}
```