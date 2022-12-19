### 解题思路
根据题目限制的范围，只要100001个桶就可以放下所有的数字，  
遍历数组，根据当前数字将50000+当前数字的桶数量加一，  
最后根据桶中的数字，数字是几就替换原数组中的几个位置，值为桶的索引-50000，将数组填满，  
注意，这里只要插入的数量达到原数组长度，就可以break了。
### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        int[] ints = new int[100001];
        for (int num : nums) {
            ints[num + 50000]++;
        }
        int idx = 0;
        for (int i = 0; i < ints.length; i++) {
            if (i > 0) {
                for (int j = 0; j < ints[i]; j++) {
                    nums[idx] = i - 50000;
                    idx++;
                }
                if (idx == nums.length) {
                    break;
                }
            }
        }
        return nums;
    }
}
```