1. 将数组转化为链表形式：数组 [1,3,4,2,2]

current / index  | 0 | 1 | 2 | 3 | 4
---|---|---|---|---|---
next / num[index]| 1 | 3 | 4 | 2 | 2
`index`为当前值的索引，`num[index]`为下个一值的索引`next index`。上表中的数组表示成链表如下图，方框中为`index, num[index]`

![pic.jpg](https://pic.leetcode-cn.com/a19d828c32d6d25a303c0cf4504ec2c627242584ce07b64c6488d2bcd200e47e-pic.jpg){:width=400}
{:align=center}

2. 利用【142_环形链表 II】的方法，找到环入口，即为重复数字
    1. 设：`slow`指针移动速度为1，`fast`指针移动速度为2；`slow`指针在环内移动（非环部分）长度为a，`slow`指针在环内移动长度为b
    2. 两指针相遇时候，`slow`指针移动距离为a+b，`fast`指针移动距离为2(a+b)，可知两指针距离差a+b即为整数倍的环长
    3. 从head移动a的距离为入环点；由2可知从head开始移动a+(a+b)的距离也为入环点，即将A点继续移动距离a则可到达入环点
    4. 将`slow`指针移动回head，同时同速移动两个指针，相遇点即为入环点
> 说明：因为数组中不含0，所以不会因为`index = 0, num[0] = 0`导致死循环；对于其他位置`index = num[index]`，若该值重复则会自身成环，若无重复则不会被遍历到

```java [-Java]
public class FindTheDuplicateNumber {
    public int findDuplicate(int[] nums) {
        if (nums.length <= 1) {
            return -1;
        }
        // 共同起点是0
        int fast = nums[nums[0]];
        int slow = nums[0];
        // 第一次相遇
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // 寻找入环点，注意起点是0
        slow = 0;
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
}
```