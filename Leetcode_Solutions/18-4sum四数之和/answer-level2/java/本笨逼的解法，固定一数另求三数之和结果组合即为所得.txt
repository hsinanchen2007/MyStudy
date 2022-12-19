思路看代码注释。
```
class Solution {
    //没得思路试试3sum
    public  List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> list = new ArrayList();
        if(nums==null||nums.length<4){
            return list;
        }
        Arrays.sort(nums);
        //固定一数
        for(int i=0;i<=nums.length-4;i++){
            //去重
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            //求三数和为target-num[i]的结果集
            List<List<Integer>> temp = threeSum(nums,i,target-nums[i]);
            if(temp!=null){//有结果集
                for(List<Integer> result : temp){
                    result.add(nums[i]);
                    //得到四数和为target的结果集
                    list.add(result);
                }
            }
        }
        return list;
    }
    //三数之和的求解其中i是指三个数必须从下标大于i的数据中选出。
    public  List<List<Integer>> threeSum(int[] nums,int i,int target){
        List<List<Integer>> list = null;
        if(nums.length-4<i){
            return list;
        }
        for(int j=i+1;j<=nums.length-3;j++){
            //这个if其实可有可无
            if(nums[j]>target&&target>0){
                break;
            }
            if(j>i+1&&nums[j]==nums[j-1]){
                continue;
            }
            int l = j+1;
            int r = nums.length-1;
            while(l<r){
                int sum = nums[j]+nums[l]+nums[r];
                if(sum==target){
                    if(list==null){
                        list = new ArrayList();
                    }
                    List<Integer> temp = new ArrayList();
                    temp.add(nums[j]);
                    temp.add(nums[l]);
                    temp.add(nums[r]);
                    list.add(temp);
                    while(l<r&&nums[l]==nums[l+1]) l++;
                    while(l<r&&nums[r]==nums[r-1]) r--;
                    l++;
                    r--;
                }else if(sum<target) l++;
                else r--;
            }
        }
        return list;
    }
}
```
ps：一次编译通过还是很有成就感的！应该还有更好的解法但我这种笨逼只能想到这了