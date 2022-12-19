### 解题思路
使用容器HashMap，把数组中数字的值当作KEY，数组下标当作Value，如果找到了下标相同的两个数就放弃，继续查找

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> arr=new HashMap<Integer,Integer>();
        for(int i=0;i<nums.length;i++) arr.put(nums[i],i);
        int i=0;
        int j=-1;
        for(;i<nums.length;i++) {
            if(arr.containsKey(target-nums[i])) {
                j=arr.get(target-nums[i]);
                if (i==j) continue;
                else break;
            }
        }
        int [] res=new int[2];
        res[0]=i;
        res[1]=j;
        return res;
    }
}
```