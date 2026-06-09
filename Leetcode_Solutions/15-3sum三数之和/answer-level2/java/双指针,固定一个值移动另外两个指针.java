### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if(nums.length<3){
            return new ArrayList<>();
        }
        //首先数组排序
        Arrays.sort(nums);
        if(nums[0]>0){
            return new ArrayList<>();
        }
        List<List<Integer>> result=new ArrayList<>();
        for(int i=0;i<nums.length-2;i++){
            //去重,避免计算重复的值,必须nums[i]与nums[i-1]进行比较,
            //如果是nums[i]与nums[i+1]比较会丢失一次数据
            //比如例子-1,-1,2的情况,如果nums[i]与nums[i+1]进行比较,则拿不到结果
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            //定义两个指针
            int l=i+1,r=nums.length-1;
            while(l<r){
                //计算和
                int sum=nums[i]+nums[l]+nums[r];
                if(sum>0){
                    //去重
                    while(l<r &&nums[r]==nums[r-1]){r--;}
                    //因为数组排序了,所以如果sum>0说明右边界值太大,所以需要移动右指针,缩小右边界的值
                    r--;
                }else if(sum<0){
                    //去重
                    while(l<r&&nums[l]==nums[l+1]){l++;}
                    //同理,sum<0,说明左边边界太小,需要增加左边界值
                    l++;
                }else{
                    //满足情况的放到list中
                    result.add(Arrays.asList(nums[i],nums[l],nums[r]));
                    //去重
                    while(l<r &&nums[r]==nums[r-1]){r--;}
                    while(l<r&&nums[l]==nums[l+1]){l++;}
                    //移动两边的指针
                    r--;
                    l++;
                }
            }
        }
        return result;
    }
}
```