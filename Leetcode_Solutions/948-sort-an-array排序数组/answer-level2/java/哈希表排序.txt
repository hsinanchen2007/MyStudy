```


class Solution {
    public int[] sortArray(int[] nums) {
        int idx = 0;
        int[] temp = new int[100001]; //计数数组,包含正负数值范围
        int[] res = new int[nums.length]; //结果数组

        for(int i=0;i<nums.length;i++){
            temp[nums[i]+50000]++; //所有元素+50000，去除负数下标，并对重复元素计数
        }

        for(int i=0;i<temp.length;i++){
            for(int j=0;j<temp[i];j++)
             //按从小到大顺序插入数组，包含重复插入,插入数值还原为nums[i];
                res[idx++] = i-50000;
        }

        return res;
    }
}
```
