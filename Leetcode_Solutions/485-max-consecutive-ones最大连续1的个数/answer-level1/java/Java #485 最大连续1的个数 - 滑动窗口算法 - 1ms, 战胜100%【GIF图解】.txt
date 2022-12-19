### 解题思路
**常规思路：**
这道题的一种常规做法就是遍历数组，记录连续1的个数，比较是否是当前最大个数。
![485最大连续1的个数2.gif](https://pic.leetcode-cn.com/e00a4f940ef991d8e5d5417fc917408bce288d8274b83ce9715ae40b474a5602-485%E6%9C%80%E5%A4%A7%E8%BF%9E%E7%BB%AD1%E7%9A%84%E4%B8%AA%E6%95%B02.gif)

**常规遍历代码：**
```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int length = nums.length;
        int max  = 0;
        int count = 0;
        
        // 遍历数组
        for (int i = 0; i < length; i++){
            if (nums[i] == 1){
                // 记录连续1的个数
                count++;
            }else {
                // 比较是否是当前最大个数
                if (count > max)
                    max = count;
                // 归零，寻找下一个连续序列
                count = 0;
            }
        }
        
        // 因为最后一次连续序列在循环中无法比较，所以在循环外进行比较
        return max > count?max:count;
    }
}
```
执行用时：执行用时 : 2 ms, 在所有 Java 提交中击败了 99.02% 的用户

---

**滑动窗口思路：**
当输出或比较的结果在原数据结构中是连续排列的时候，可以使用滑动窗口算法求解。
将两个指针比作一个窗口，通过移动指针的位置改变窗口的大小，观察窗口中的元素是否符合题意。
1. 初始窗口中只有数组开头一个元素。
2. 当窗口中所有元素为 1 时，右指针向右移，扩大窗口。
3. 当窗口中存在 0 时，计算连续序列长度，左指针指向右指针。
![485最大连续1的个数.gif](https://pic.leetcode-cn.com/800477dcf6ed4922a9fc279d1918b43292acb6eb87564008a5a061e5ac995eb1-485%E6%9C%80%E5%A4%A7%E8%BF%9E%E7%BB%AD1%E7%9A%84%E4%B8%AA%E6%95%B0.gif)

```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int length = nums.length;
        int left = 0;
        int right = 0;
        int maxSize = 0;
        
        while(right < length){
            //当窗口中所有元素为 1 时，右指针向右移，扩大窗口。
            if (nums[right++] == 0){
                //当窗口中存在 0 时，计算连续序列长度，左指针指向右指针。
                maxSize = Math.max(maxSize, right - left - 1);
                left = right;
            }
        }
        // 因为最后一次连续序列在循环中无法比较，所以在循环外进行比较
        return Math.max(maxSize, right - left);
    }
}
```
执行用时：执行用时 : 1 ms, 在所有 Java 提交中击败了 100.00% 的用户

---

博客：www.lxiaocode.com