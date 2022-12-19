### 解题思路
此处撰写解题思路

1. 取走的目标值先置-1，便于发现是否是空位
2. 找到不匹配的位置的数时，不停的跳跃，直至找到的数是当前循环位置 或者 目标值为-1 就结束循环
### 代码

```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> result = new ArrayList<>();
        int targetTemp = -1;
        for (int i = 0; i < nums.length; i++) {
            // 位置匹配
            int baseCurrent = nums[i];
            if (baseCurrent == i + 1 || baseCurrent == -1) {
                continue;
            } else {
                nums[i] = -1; // 取走这个值，置空
                int current = baseCurrent;
                targetTemp = nums[current - 1];//当前i存的值，也是目标位置，这里为了进循环
                nums[current - 1] = current;
                while (targetTemp != -1) {
                    int t = nums[targetTemp - 1];// 取走目标位置的值,也是下一个目标位置
                    if (targetTemp == t) {
                    // 当前目标位置就是这里 就不用了再跑了
                        break;
                    }
                    nums[targetTemp - 1] = targetTemp; // 目标位置赋值
                    targetTemp = t;
                    if (t == -1) {
                        // 这里存的-1，没有后续比较的意义了
                        break;
                    }
                    // 比较最新值是否符合当前i的循环
                    if (targetTemp == i + 1) {
                        nums[i] = targetTemp;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == -1) {
                result.add(i + 1);
            }
        }
        return result;
    }
}
```