[TOC]

## 题目说明

给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

> nums1 = [1, 3]
> nums2 = [2]
>
> 则中位数是 2.0

示例 2:

> nums1 = [1, 2]
> nums2 = [3, 4]
>
> 则中位数是 (2 + 3)/2 = 2.5



## 解题思路

### 什么是中位数

为了解决这个问题，我们需要理解 “中位数的作用是什么”。在统计中，中位数被用来：

将一个集合划分为两个长度相等的子集，其中一个子集中的元素总是大于另一个子集中的元素。

这其中又分为偶数组和奇数组：

奇数组:`[2 3 5]` 对应的中位数为`3`

偶数组: `[1 4 7 9]` 对应的中位数为`(4 + 7) /2 = 5.5`



### 什么是割

我们通过切一刀，能够把有序数组分成左右两个部分，切的那一刀就被称为割(Cut)，割(Cut)的左右会有两个元素，分别是左边最大值和右边最小值。

我们定义`LMax= Max(LeftPart)，RMin = Min(RightPart)。`

割可以割在两个数中间，也可以割在1个数上，如果割在一个数上，那么这个数即属于左边，也属于右边

奇数组:`[2 3 5]` 对应的中位数为`3`，假定割`(Cut)`在3上，我们可以把3分为2个：`[2 （3/3) 5]`

因此`LMax=3, RMin=3`

偶数组: `[1 4 7 9]` 对应的中位数为`(4 + 7) /2 = 5.5`,假定割`(Cut)`在4和7之间：`[1 （4/7) 9]`

因此`LMax=4, RMin=7`



### 怎么割

我们设:
`Ci`为第`i`个数组的割。

`LMaxi`为第`i`个数组割后的左元素.

`RMini`为第`i`个数组割后的右元素。

![image.png](https://pic.leetcode-cn.com/2d6775cb90879cbb488a104d4687fd069265433e50e0a4687cdcc61e657bda42-image.png)

首先，`LMax1<=RMin1，LMax2<=RMin2` 这是肯定的，因为数组是有序的，左边肯定小于右边!，而如果割(`Cut`)在某个数上，则左右相等。

我们先假设两个数组的长度和是偶数，然后割在两数中间的情况。

​	假设1, 如果`max(leftpart) <= min(rightpart)`，那么L重新排序后的情况就变成了` L = [ l1, l2, ...., left_max,   right_min, ..... ]`。

​     等价于 max(a~i~, b~j~) <= min(a~i+1~, b~j+1~)     **公式1**

​	假设2，如果`len(L_left) == len(L_right)`，那么中位数= `(left_max +  right_min)/2`。

​     等价于 `i + j = m -i + n - j 即  i + j = (m + n)/2`   **公式2**



### 怎么解决奇偶问题

两个数组合并后的长度，有可能是偶数，也有可能是奇数。如果可以让数组长度总是为偶数，那么就可以用上面的公式覆盖。

通过虚拟加入`"#"`，让每个数组的长度都变成 2x + 1，所以 `n+m ->  2n + 2m + 2`，恒为偶数。

![image.png](https://pic.leetcode-cn.com/9e95202ed9e3fbad08971f69e9212b817750e05d6d6cece656cda25385f04a1e-image.png)

转换后，原始的元素可以通过新下标//2得到。

比如9，原来是3位，现在是7位， `7//2=3`

而对于割，如果‘#’上等于割在2个元素之间，割在数字上等于把数字划到2个部分，总是有以下成立：

```python
LMaxi = (Ci-1)/2 位置上的元素
RMini = Ci/2 位置上的元素
```

举个奇数的例子

`A = [# 2 # 6 # 8 #]`

`a = [2 6 8]`

割在`6`这个数字上，C = 3,  `LMax=a[(3-1)//2]=a[1]=6   RMin=a[3//2]=a[1]`，都是6

举个偶数的例子

`A = [# 1 # 4 # 7 # 9]`

`a = [1 4 7 9]`

割在数字`4`和`7`之间的`#`上，C=4，`LMax=a[(4-1)/2]=a[1]=4  RMin=a[4/2]=a[2]=7`



### 核心逻辑

剩下的事情就好办了，把2个数组看做一个虚拟的数组A，A有2m+2n+2个元素，割在m+n+1处。然后我们求得LMaxi和RMini即可。

```python
        n = len(nums1)
        m = len(nums2)
        for c1 in range(0, 2 * n):
            c2 = m + n - c1  ##因为数组从0开始，所以c1+c2=(m+n+1)-1

            LMax1 = nums1[(c1 - 1) // 2] if c1 > 0 else -1
            RMin1 = nums1[c1 // 2] if c1 < 2 * n else sys.maxsize
            LMax2 = nums2[(c2 - 1) // 2] if c2 > 0 else -1
            RMin2 = nums2[c2 // 2] if c2 < 2 * m else sys.maxsize

            if max(LMax1, LMax2) <= min(RMin1, RMin2):
                break

        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0

```



## 时间复杂度

上面的方法，只需要遍历一边m或者n，所以时间复杂度是O(n)，但是题目要求需要O(log(n))。

所以需要找到更快的方法来找到C1和C2，比如使用二分法。

二分法的使用，必须找到一个比较的方法，用于指导我们朝哪个方向切。

![image.png](https://pic.leetcode-cn.com/093b24024f3df5360990cb8d2c563f2868326a3e19e9dd3b831f966110d9a796-image.png)

还是来看上面的例子，因为LMaxi必定小于等于RMini，所以我们考虑另外两种情况：

- 如果`LMax1 > RMin2`，那么就把C1往左挪，即减小C1。
- 如果`LMax2 > Rmin1`，那么就把C2往左挪，即减小C2，也就是增加C1。

那么逻辑就是C1先切nums1的中间，然后根据上面的情况来决定下次往哪儿挪

```python
        n = len(nums1)
        m = len(nums2)

        if n > m:
            return self.findMedianSortedArrays(nums2, nums1)

        start_pos = 0
        end_pos = 2 * n

        while start_pos <= end_pos:
            c1 = (start_pos + end_pos) // 2
            c2 = m + n - c1  ##因为数组从0开始，所以c1+c2=(m+n+1)-1

            LMax1 = nums1[(c1 - 1) // 2] if c1 > 0 else (-1 * sys.maxsize)
            RMin1 = nums1[c1 // 2] if c1 < 2 * n else sys.maxsize
            LMax2 = nums2[(c2 - 1) // 2] if c2 > 0 else (-1 * sys.maxsize)
            RMin2 = nums2[c2 // 2] if c2 < 2 * m else sys.maxsize

            if LMax1 > RMin2:
                end_pos = c1 - 1
            elif LMax2 > RMin1:
                start_pos = c1 + 1
            else:
                break

        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0
```

C++实现版本

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int start_pos = 0;
        int end_pos = 2 * n;
        int LMax1=0, RMin1=0, LMax2=0, RMin2=0;

        while(start_pos <= end_pos)
        {
            int c1 = (start_pos + end_pos) / 2;
            int c2 = m + n - c1;

            LMax1 = c1> 0 ? nums1[(c1-1)/2] : INT_MIN;
            RMin1 = c1 < 2 * n ? nums1[c1/2] : INT_MAX;
            LMax2 = c2 > 0 ? nums2[(c2-1)/2] : INT_MIN;
            RMin2 = c2 < 2 * m ? nums2[c2/2] : INT_MAX;

            if (LMax1 > RMin2)
            {
                end_pos = c1 - 1;
            }
            else if(LMax2 > RMin1)
            {
                start_pos = c1 + 1;
            }
            else
            {
                break;
            }
        }
        
        return (max<long>(LMax1, LMax2) + min<long>(RMin1, RMin2)) / 2.0;
    }
};
```









