### 解题思路
1、统计每个1的位置，以及1的个数为N
2、窗口在统计到的1之间滑动，每次滑动计算窗口的大小是否大于N，如果大于N则计算0的个数，也即是交换的次数； 如果小于N则继续移动right指针

看了其他人的思路，好像固定为N的滑动窗口也可以解决

![image.png](https://pic.leetcode-cn.com/8ecfffe30ad7600d583b25828ab06c613b78eaf22c75e1b146d273c4d69b8c25-image.png)

### 代码

```java
class Solution {
    public int minSwaps(int[] data) {
        if (data.length == 0) {
            return 0;
        }
        int[] arr = new int[data.length];
        int index = 0;
        for (int i = 0; i < data.length; i++) {
            if (data[i] == 1) {
                arr[index++] = i;
            }
        }
        if (index == 0) {
            return 0;
        }
        int left = 0;
        int right = 0;
        int sum = 1;
        int min = Integer.MAX_VALUE;
        while (left < index) {
            sum = 1;
            while (right < index && sum < index) {
                right++;
                sum = arr[right] - arr[left] + 1; // 可容纳的1的个数
            }
            if (sum < index) {
                break;
            }
            // 计算窗口内需要的0的个数，即为需要交换的次数
            int needNum = index - (right - left);
            int zeroNum = arr[right] - arr[left] - right + left;
            int delta = Math.min(needNum, zeroNum);
            min = Math.min(min, delta);
            left++;
        }
        return min;
    }
}
```