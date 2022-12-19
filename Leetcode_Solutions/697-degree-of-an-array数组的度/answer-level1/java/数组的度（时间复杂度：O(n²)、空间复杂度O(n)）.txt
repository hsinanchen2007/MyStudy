基本思路：
1. 用map记录数组中每个元素出现的次数，并计算出最大度
2. 遍历map，找到和最大度相同的键值
3. 从左和右分别遍历原数组，计算等于最大度的子数组的长度
4. 取最小的子数组长度

```
class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, Integer> m = new HashMap();//计算每个元素的出现次数

        //统计每个元素出现的次数
        for (int i = 0; i < nums.length; i++) {
            int x = nums[i];
            if (m.get(x) == null)  
                m.put(x, 1);
            else
                m.put(x,m.get(x)+1);
        }

        int maxDegree = 0;//记录最大度
        int key = 0;//记录最大度的下标
        for (Map.Entry<Integer, Integer> entry : m.entrySet()) {
            if(maxDegree < entry.getValue()){
                key = entry.getKey();
                maxDegree = entry.getValue();
            }
        }
        int minLen = Integer.MAX_VALUE;
        for (Map.Entry<Integer, Integer> entry : m.entrySet()) {
            if(entry.getValue() == maxDegree){
                key = entry.getKey();
                int i = 0,j = nums.length-1;
                //从左遍历数组
                for (i = 0; i < nums.length; i++) {
                    if(nums[i] == key){
                        break;
                    }
                }
                //从右遍历数组
                for (j = nums.length-1;j >= 0;j --){
                    if(nums[j] == key)
                        break;
                }
                //找出最短的
                if(minLen > j - i + 1)
                    minLen = j - i + 1;
            }
        }
        return  minLen;
    }
}
```