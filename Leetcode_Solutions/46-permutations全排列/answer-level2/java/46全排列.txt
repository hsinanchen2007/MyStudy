1、回溯：在序列数组的每一个位置都可以选一个数字，选择好当前位置的元素后将指针右移到下一个位置，并进行下一位置的选择，直到找到一种完整的顺序并返回当前的排列，并回退上一轮选择其他的元素后继续后续选择。

```
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        ArrayList<Integer> nums_list = new ArrayList<Integer>();
        List<List<Integer>> result = new ArrayList();
        int Len = nums.length;

        for(int num:nums)
        {
            nums_list.add(num);
        }

        backtrack(Len, nums_list, result,0);

        return result;
    }

    private void backtrack(int Len, ArrayList<Integer> nums_list, List<List<Integer>> result, int nowPoint)
    {
        if (nowPoint == Len) result.add(new ArrayList<Integer>(nums_list));

        for (int i=nowPoint; i<Len; i++)
        {
            Collections.swap(nums_list,nowPoint, i);

            backtrack(Len , nums_list, result, nowPoint+1);

            Collections.swap(nums_list,nowPoint,i);
        }
    }
    
}
```