#### 方法一: 一次遍历 

**直觉**

本问题被称为 [荷兰国旗问题](https://en.wikipedia.org/wiki/Dutch_national_flag_problem)
，最初由 [Edsger W. Dijkstra](https://baike.baidu.com/item/艾兹格·迪科斯彻/5029407?fromtitle=Dijkstra&fromid=1880870&fr=aladdin)提出。
其主要思想是给每个数字设定一种颜色，并按照荷兰国旗颜色的顺序进行调整。

![image.png](https://pic.leetcode-cn.com/3ab6cc20bb91835c2722c688c2f894e407289333bae839a930957461e810a957-image.png)

我们用三个指针（p0, p2 和curr）来分别追踪0的最右边界，2的最左边界和当前考虑的元素。

![image.png](https://pic.leetcode-cn.com/5b3d372e0bfb293ca3aac12e90421d7612c9e75b78b579f954c42ebfe74705d4-image.png)

本解法的思路是沿着数组移动 `curr` 指针，若`nums[curr] = 0`，则将其与 `nums[p0]`互换；若 `nums[curr] = 2` ，则与 `nums[p2]`互换。

**算法**

- 初始化0的最右边界：`p0 = 0`。在整个算法执行过程中 `nums[idx < p0] = 0`.

- 初始化2的最左边界 ：`p2 = n - 1`。在整个算法执行过程中  `nums[idx > p2] = 2`.

- 初始化当前考虑的元素序号 ：`curr = 0`.

- While `curr <= p2` :

    - 若 `nums[curr] = 0` ：交换第 `curr`个 和 第`p0`个 元素，并将指针都向右移。 
    
    - 若 `nums[curr] = 2` ：交换第 `curr`个和第 `p2`个元素，并将 `p2`指针左移 。
    
    - 若 `nums[curr] = 1` ：将指针`curr`右移。 

**实现**

<![image.png](https://pic.leetcode-cn.com/2823021bb0ce1c12afd4320592b5a42f7644969b389f66de623c5c53afd0b7c0-image.png),![image.png](https://pic.leetcode-cn.com/fe866418cf2c4a3f952e306244154bedf08de877cd32c90a3360037083f824f3-image.png),![image.png](https://pic.leetcode-cn.com/cf9424fc35b46c2cc22245bcabd1a6c9174b45330fa3583ad1d0b7ffccd24467-image.png),![image.png](https://pic.leetcode-cn.com/f46f4c36b5e934da0970336fd1d354bf8ab62fe8b839e0941983363187527912-image.png),![image.png](https://pic.leetcode-cn.com/5b5fcb1b0d97634f98a48367c3d165627f70774ca9509b7a1842cb54aef725c8-image.png),![image.png](https://pic.leetcode-cn.com/2e3068fdf815aba9a9aae31b8c9fcd2046ddf60b807018380ae95bb3c4c81d56-image.png),![image.png](https://pic.leetcode-cn.com/2a52a5f05c7ae0fedaaf7ed868e811d7527ace707dd62a9ca35c56eca1508b16-image.png),![image.png](https://pic.leetcode-cn.com/37d97fa81e2a9c8c745792aea95cb4662a1e3b8995f56ec6cccd2f24ab7c6376-image.png),![image.png](https://pic.leetcode-cn.com/c572ca6c0f8597650e78a46c0a0d9a911385f8c3abde37323426a96e5abad130-image.png),![image.png](https://pic.leetcode-cn.com/796a2abd8b7c06df30eab6c9e379c0b5e7d8691ed8643c2558eaa2dca0a3440b-image.png),![image.png](https://pic.leetcode-cn.com/6c85efd7087ee544a9182fc473150a5ec209eb166d3d6a22555afd3952d858e9-image.png),![image.png](https://pic.leetcode-cn.com/c5cc0460d604522a6cd4026059acb87d6bb83626f5d0cd84cfb41cdf99ebf618-image.png),![image.png](https://pic.leetcode-cn.com/6182aa82356ca67139d2a7fc686832694e1edd3b925a3b51f8b0d53c3688ee1a-image.png)>

```Java [solution1]
class Solution {
  /*
  荷兰三色旗问题解
  */
  public void sortColors(int[] nums) {
    // 对于所有 idx < i : nums[idx < i] = 0
    // j是当前考虑元素的下标
    int p0 = 0, curr = 0;
    // 对于所有 idx > k : nums[idx > k] = 2
    int p2 = nums.length - 1;

    int tmp;
    while (curr <= p2) {
      if (nums[curr] == 0) {
        // 交换第 p0个和第curr个元素
        // i++，j++
        tmp = nums[p0];
        nums[p0++] = nums[curr];
        nums[curr++] = tmp;
      }
      else if (nums[curr] == 2) {
        // 交换第k个和第curr个元素
        // p2--
        tmp = nums[curr];
        nums[curr] = nums[p2];
        nums[p2--] = tmp;
      }
      else curr++;
    }
  }
}
```

```Python [solution1]
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        '''
        荷兰三色旗问题解
        '''
        # 对于所有 idx < p0 : nums[idx < p0] = 0
        # curr是当前考虑元素的下标
        p0 = curr = 0
        # 对于所有 idx > p2 : nums[idx > p2] = 2
        p2 = len(nums) - 1

        while curr <= p2:
            if nums[curr] == 0:
                nums[p0], nums[curr] = nums[curr], nums[p0]
                p0 += 1
                curr += 1
            elif nums[curr] == 2:
                nums[curr], nums[p2] = nums[p2], nums[curr]
                p2 -= 1
            else:
                curr += 1
```

```C++ [solution1]
class Solution {
  public:
  /*
  荷兰三色旗问题解
  */
  void sortColors(vector<int>& nums) {
    // 对于所有 idx < p0 : nums[idx < p0] = 0
    // curr 是当前考虑元素的下标
    int p0 = 0, curr = 0;
    // 对于所有 idx > p2 : nums[idx > p2] = 2
    int p2 = nums.size() - 1;

    while (curr <= p2) {
      if (nums[curr] == 0) {
        swap(nums[curr++], nums[p0++]);
      }
      else if (nums[curr] == 2) {
        swap(nums[curr], nums[p2--]);
      }
      else curr++;
    }
  }
};
```


**复杂度分析**

* 时间复杂度 :由于对长度 $N$的数组进行了一次遍历，时间复杂度为$O(N)$ 。
 
* 空间复杂度 :由于只使用了常数空间，空间复杂度为$O(1)$ 。

