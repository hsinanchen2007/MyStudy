### 解题思路
发现数组相关的题，貌似都可以用双指针解决？！
先将给定数组排序：直接Arrays.sort(nums)
然后每次循环确定三个数中的一个数不变，然后通过两个指针分别指向不变数的右边的第一个和最后一个
之后在循环中遍历数组，找出sum=0的三个数：
sum < 0 : 把left向右移
sum > 0 : 把right向左移
sum == 0：先把重复的数去掉，再将left向右移，同时将right向左移

最后循环结束，找出所有的结果，返回list
### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> list=new ArrayList<>();
        int length=nums.length;
        if(length<3){
            return list;
        }
        Arrays.sort(nums);
        for(int i=0;i<length;i++){
            if(nums[i]>0){
                break;
            }
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int left=i+1;
            int right=length-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum<0){
                    left++;
                } else if(sum>0){
                    right--;
                }else{
                    list.add(Arrays.asList(nums[i],nums[left],nums[right]));
                    while(left<right&&nums[left]==nums[left+1]){
                        left++;
                    }
                    while(left<right&&nums[right]==nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return list;
    }
}
```