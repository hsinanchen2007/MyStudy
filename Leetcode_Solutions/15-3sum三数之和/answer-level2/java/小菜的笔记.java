### 解题思路
此处撰写解题思路
注意数组排序后的去重，且排序后才用左右双指针。不然得到的数组有重复的。
### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> list = new ArrayList();
        int len=nums.length;
        if(len<3) return list;
        Arrays.sort(nums);
        for(int i=0;i<len;i++){
            if(nums[i]>0)break;//数组升序，若第一个大于0，则和大于0
            if(i>0&&nums[i]==nums[i-1])continue;//找到第一个不重复的数字，即去重
            int L=i+1;
            int R=len-1;
            while(L<R){
                int sum=nums[i]+nums[L]+nums[R];
                if(sum==0){
                list.add(Arrays.asList(nums[i],nums[L],nums[R]));
                while(L<R&&nums[L]==nums[L+1])L++;//去重
                while(L<R&&nums[R]==nums[R-1])R--;
                L++;
                R--;
            }
            else if(sum<0)L++;
            else if(sum>0)R--;
            }
            
        }
        return list;

    }
}
```