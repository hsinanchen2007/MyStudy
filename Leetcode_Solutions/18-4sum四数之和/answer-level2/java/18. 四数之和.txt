/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/18
 *
 * 解题思路: 故额定两个指针 其余两个指针在他们的右端移动
 *
 * 注意: 这中题目主要思路是  排序 固定n-2个指针 其余指针在右端后进行相向移动 1.两个重复判断(固定指针与前一位不重复/当获取一组target移动指针与后一个不能相等)  2.循环内更新l r指针
 *
 */
```
public List<List<Integer>> fourSum(int[] nums, int target) {
    List<List<Integer>> lists = new ArrayList<>();
    Arrays.sort(nums);
    int l = 2;
    int r = nums.length-1;
    for(int i = 0;i < nums.length-3;i++){
        if(i >0 && nums[i-1] == nums[i]) continue; //重复判断1
        for(int j = i+1;j < nums.length-2;j++){
            if(j > i + 1 && nums[j - 1] == nums[j])continue;//重复判断1
            l = j+1;
            r = nums.length - 1;
            while(l < r){
                int sum = nums[i] + nums[j] + nums[l] + nums[r];
                if(sum == target){
                    lists.add(Arrays.asList(nums[i],nums[j],nums[l],nums[r]));
                    while(l < r && nums[l] == nums[l+1]) l++; //重复判断2
                    while(l < r && nums[r] == nums[r-1]) r--; //重复判断2
                    r--;
                    l++;
                }else if(sum > target){
                    r--;
                }else{
                    l++;
                }
            }
        }
    }
    return lists;
}
```