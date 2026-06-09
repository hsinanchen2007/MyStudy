搞了蛮久，主要是一些边界条件没想全，最终还是过了，不容易啊，要记录一下
![image.png](https://pic.leetcode-cn.com/1445f3fdc671b973834fb674a941bdb110b35ec2bd5c90a285a9b71a8d9c3518-image.png)

### 解题思路
1、首先可以想到这个最小的正整数范围是[1,array.length+1]
2、所以范围之外的元素可以置为-1，范围内的数字可以对应到数组中的对应下标处，比如{3,4,-8,1} -> {1,-1,3,4}
3、然后再遍历数组，第一个为-1的元素的下标+1就是所求值
4、当然如果遍历完了都没有为-1的，说明所求为array.length+1，比如{1,2}

### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 1;
        }
        int len = nums.length;
        for (int i = 0; i < len;) {
            if (nums[i] > len || nums[i] <= 0) { // 范围之外
                nums[i] = -1;
                i++;
                continue;
            }
            int index = nums[i] - 1;
            if (index <= i) { // nums[i] - 1 值的位置在已经遍历过的部分
                nums[index] = 1; // 用正数1占坑，当然用下标+1占着也一样
                if (index != i) {
                    nums[i] = -1;
                }
            } else {
                int tmp = nums[index];
                if (tmp > len || tmp <= 0) { // 范围之外
                    nums[index] = index + 1;
                    nums[i] = -1;
                } else { // nums[index] 和nums[i] 交换
                    nums[index] = index + 1;
                    nums[i] = tmp;
                    if (nums[index] == nums[i]) { // 避免{2,2}的情况
                        nums[i] = -1;
                    }
                    continue; // i不自增，继续从i开始
                }
            }
            i++;
        }

        for (int i = 0; i < len; i++) {
            if (nums[i] <= 0) {
                return i + 1;
            }
        }
        return len + 1;
    }
}
```