### 解题思路
先排序
然后一次遍历

### 代码

```java
class Solution {
    public int[] missingTwo(int[] nums) {
        Arrays.sort(nums);
        int a = -1;
        int b = -1;
        int carry = 0;
        int i = 1;
        for (; i <= nums.length;) {
            if (nums[i - 1] > i + carry) {
                if (a == -1) {
                    a = i+carry;
                } else {
                    b = i+carry;
                }
                carry++;
                continue;
            }else{
                i++;
            }
        }
        if (a == -1 && b == -1) {
            a = i;
            b = i + 1;
        } else if (a > 0 && b == -1) {
            int last = nums[nums.length - 1];
            if (i < last) {
                b = i;
            } else {
                b = last + 1;
            }
        }
        return new int[]{a, b};
    }
}
```