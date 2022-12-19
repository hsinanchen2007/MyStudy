### 解题思路
1. 将数组转化为有序的数组，使用sort函数进行排序
2. 使用双指针进行处理。--一次遍历就可以解决问题。
3. 存在的难点：重复值的处理。
- 处理方法，出现重复值的时候，将坐标进行向左或者向右进行平移。
- 注意处理全部是0的元素，只能出现一次

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> list_all = new ArrayList<>();
        if(nums.length < 3) return list_all ;
        Arrays.sort(nums);// 进行排序 从小到大
        for(int i = 0;i< nums.length;i++){// 双指针方法进行处理
            int l = i + 1;
            int r = nums.length-1;
            if(0 < i && nums[i] == nums[i-1]) continue;// 去重  全部是0的情况
            while(l < r){// 要考虑去除重复数组的值
                List<Integer> list = new ArrayList<>();
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0) {
                    list.add(nums[i]);
                    list.add(nums[l]);
                    list.add(nums[r]);
                    list_all.add(list);
                    while(l < r && nums[r] == nums[r-1]) r--;// 去除重复的数值
                    while(l < r && nums[l] == nums[l+1]) l++;// 去除重复的数值
                    r--;
                    l++;
                }else if(sum >0){
                    r--;
                }else{
                    l++;
                } 
            }

        }
        return list_all;
        
    }
}
```