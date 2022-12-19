![截屏2020-02-08下午4.16.06.png](https://pic.leetcode-cn.com/7563f3306c149a9b819cac390336c45754f2d9d493135f6097522427feacac67-%E6%88%AA%E5%B1%8F2020-02-08%E4%B8%8B%E5%8D%884.16.06.png)


### 解题思路
一种比较容易理解的解法：
遍历数组，当遇到一个数比前一个数小的时候，只有两种替换方法，即：
1. 将前一个数替换为这个数
2. 将这个数替换为前一个数
替换完后，我们已经用完一次替换机会，分别检验两个替换后的数组，只要有一种符合非递减数列即可

### 代码

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        for (int i = 1; i < nums.length; i ++) {
            if (nums[i] < nums[i-1]) {
                int[] case1 = Arrays.copyOf(nums, nums.length);
                case1[i] = case1[i-1];

                int[] case2 = Arrays.copyOf(nums, nums.length);
                case2[i-1] = case2[i];

                return checkhelper(case1) || checkhelper(case2);
            }
        }
        return true;
    }

    public boolean checkhelper(int[] nums) {
        for (int i = 1; i < nums.length; i ++) {
            if (nums[i] < nums[i-1]) return false;
        }
        return true;
    }
}
```