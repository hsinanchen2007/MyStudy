- 思想：拷贝数组，进行排序，逐个值进行比较，从第一个不一样到最后一个不一样，中间有多少数字，即为输出值
- 要点1：拷贝数组，而非数组的引用
- 要点2：不能依次比较有多少个不一样，中间可能会有排序前后同位置的元素，要比较首尾只差
- 要点3：避免完全一致的情况，last可赋初值为-1，first为0

```
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int[] temp = nums.clone();
        Arrays.sort(temp);
        int length = nums.length;
        int first = 0;
        int last = -1;
        boolean isFirst = true;
        
        for(int i=0; i<length; i++)
        {
            if(nums[i]!=temp[i] && isFirst==true)
            {
                first = i;
                last = i;
                isFirst = false;
            }
            else if(nums[i]!=temp[i])
            {last = i;}
        }
        
        return (last-first+1);
        
    }
}
```
