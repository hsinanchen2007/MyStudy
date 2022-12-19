####  首尾双指针



- 定义头指针 $left$ ，尾指针 $right$ .
- $left$ 一直往右移，直到它指向的值为偶数
- $right$ 一直往左移， 直到它指向的值为奇数
- 交换 $nums[left]$ 和 $nums[right]$  .
- 重复上述操作，直到 $left == right$ .



![](https://pic.leetcode-cn.com/f25bd8d3c3fd5d30969be2954685a21f67e254a6487c6d9d27edf6589a0fca55.gif)



#### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if ((nums[left] & 1) != 0) {
                left ++;
                continue;
            }
            if ((nums[right] & 1) != 1) {
                right --;
                continue;
            }
            swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};
```





#### 快慢双指针

- 定义快慢双指针 $fast$ 和 $low$ ，$fast$ 在前， $low$ 在后 .
- $fast$ 的作用是向前搜索奇数位置，$low$ 的作用是指向下一个奇数应当存放的位置
- $fast$ 向前移动，当它搜索到奇数时，将它和 $nums[low]$ 交换，此时 $low$ 向前移动一个位置 .
- 重复上述操作，直到 $fast$ 指向数组末尾 .



![](https://pic.leetcode-cn.com/f607c90cfd7578d65a24a6aa513297900b681cfb72563168532765b636fd0c55.gif)


#### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int low = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] & 1) {
                swap(nums[low], nums[fast]);
                low ++;
            }
            fast ++;
        }
        return nums;
    }
};
```

#### 最后

感谢您的观看！欢迎大家留言，一起讨论交流。

至此您已经掌握了解决此题的两种方式，如果这篇文章对您有帮助，您可以扫描下方二维码关注我的公众号“小小算法”，感谢您的支持！

![小小算法.png](https://pic.leetcode-cn.com/1776597b2773892787b2a16738cd78feb346c5a5290273bce69275b0b66a0a95-%E5%AE%A3%E4%BC%A0%E5%9B%BE2.png)