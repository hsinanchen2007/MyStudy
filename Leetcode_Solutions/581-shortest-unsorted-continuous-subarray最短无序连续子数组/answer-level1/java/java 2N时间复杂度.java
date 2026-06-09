### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findUnsortedSubarray(int[] nums) {
int[] ints = nums.clone();
        Arrays.sort(ints);
        int top = 0, bottom = 0;
        for (int i = 0; i < ints.length; i++) {
            if (nums[i] != ints[i]) {
                top = i;
                break;
            }
        }
        for (int i = ints.length - 1; i >= 0; i--) {
            if (nums[i] != ints[i]) {
                bottom = i;
                break;
            }
        }
        return (bottom - top) == 0 ? 0 : bottom - top + 1;
    }
}
```

克隆出来一个排序好的数组，然后再来进行判断，从前到后来进行判断。如果本身就是有序的 那么top = bottom = 0， 否则 就是 bottom-top +1