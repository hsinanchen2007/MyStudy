### 解题思路
1. 快排实现最低时间复杂度的排序 O（NlogN）。
2. 第一层从左到右遍历数组，时间复杂度O（N），注意边界条件，如果值大于0 那么停止循环，后续不会再有符合的数据了。
3. 第二层循环依次遍历 将当前i值，和左右边界值 相加判断结果是否大于0.大于0 右边界往左，小于0 左边界往右，等于0就把三个数装到结果里。
4. 注意重复结果的问题，每次for循环，三个地方要检查，也是该题最坑的地方，花在边界上的时间简直比题目本身还要多了。
5. 原本把 int right = nums.length -1; 写到for循环外，以为是固定值，结果被坑惨了。漏掉一堆结果还找不到原因...
6. 最终时间复杂度 O（NlogN）+ O（N）+ O（N）。

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> list = new ArrayList();
        if (nums.length < 3) return list;
        quickSort(nums,0,nums.length -1);
        for (int i = 0; i< nums.length; i++){
            int left = i+1;
            int right = nums.length -1;
            int num = nums[i];
            if (num > 0){
                break;
            }
            if (i>0 && nums[i] == nums[i-1])
            {
                continue;
            }
            while (left < right){
                if (nums[left]+nums[right] + nums[i]>0){
                    right--;
                }else if (nums[left]+nums[right] + nums[i]<0){
                    left++;
                }else{
                    list.add(Arrays.asList(nums[i],nums[left],nums[right]));
                    left++;
                    right--;
                    while (left< right && nums[right] == nums[right -1]){
                        right--;
                    }
                    while (left< right && nums[left] == nums[left +1]){
                        left++;
                    }
                }
            }
        }
        return list;
    }

    public void quickSort (int[] nums,int left,int right)
    {
        int i = left,j = right;
        if (i>j) return;
        while (i<j){
            while (nums[j] >= nums[left] && i<j){
                j--;
            }
            while (nums[i] <= nums[left] &&i<j){
                i++;
            }
            if (i<j){
                exchange (nums,i,j);
            }
        }
        exchange(nums,j,left);
        quickSort (nums,left,j-1);
        quickSort (nums,j+1,right);
    }
    public void exchange(int[] nums,int a,int b)
    {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
```