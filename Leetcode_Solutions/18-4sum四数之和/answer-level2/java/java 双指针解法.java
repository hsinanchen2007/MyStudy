不难理解，看代码看代码
```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Arrays.sort(nums);//排序
        int len = nums.length;
        // for(int i=0;i<len;++i){
        //     System.out.print(nums[i]);
        // }
        if(nums==null||len<4)//长度小于四，直接返回。测试用例好像没有长度小于四的，去掉也行
            return result;
        for(int i=0;i<len-3;++i){
            if(nums[i]>target/4)//最小的数都大于target的1/4，后面的不用看了
                break;
            if(i>0 && nums[i]==nums[i-1])//去重
                continue;
            for(int j=i+1;j<len-2;++j){
                if(j>i+1 && nums[j]==nums[j-1])//去重
                    continue;
                int low = j+1;
                int high = len-1;
                while(low<high){
                    //System.out.println(low);
                    if(nums[high]<target/4)//最大的都小于targer的1/4，后面的不用看了
                        break;
                    int sum = nums[i]+nums[j]+nums[low]+nums[high];
                    if(sum==target){
                        //System.out.println(""+i+" "+j+" "+low+" "+high);
                        result.add(Arrays.asList(nums[i],nums[j],nums[low],nums[high]));
                        while(low<high && nums[low] == nums[low+1]) ++low;//跳过相同的值
                        while(low<high && nums[high] == nums[high-1]) --high;//跳过相同的值
                        ++low;
                        --high;
                    }else if(sum<target){//和小于目标值，low增大，使和增大
                        while(low<high && nums[low] == nums[low+1]) ++low;
                        ++low;
                    }else{//和大于目标值，high减小，使值减小
                        while(low<high && nums[high] == nums[high-1]) --high;
                        --high;
                    }
                }
            }
        }
        return result;
    }
}
```
