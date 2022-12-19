# 方法:
1. 题目获取两个数组的中位数，那么遍历这两个数组到他们的mid(中间)位置即可
2. 将mid前的两个数存入事先声明好的长度为2的数组ary[0,0]
3. 接下来根据这两个数组的总长度判断直接返回中位数还是取其中间的两个数相加后的平均值。
# 图解:
1. 
![未命名文件 (1).png](https://pic.leetcode-cn.com/81685c1b090d5bc40ff6cd6500421b374fc506af432ada20a31449ad497774a0-%E6%9C%AA%E5%91%BD%E5%90%8D%E6%96%87%E4%BB%B6%20\(1\).png)

2. 
![未命名文件 (2).png](https://pic.leetcode-cn.com/99759ffe76e8fee7e6757ecd72620303497101fa17648e2e67e341697cd2765a-%E6%9C%AA%E5%91%BD%E5%90%8D%E6%96%87%E4%BB%B6%20\(2\).png)
3. 判断是一个中位数，还是二个中位数，然后根据对应规则返回结果集。
![2.png](https://pic.leetcode-cn.com/289c36c41d2ee1a3882c67cd0ae861b110e9ef9b812340137dfae78c1c771d1d-2.png)


```java []
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // 1. 下面这些情况进行处理
        // 一个数组为空，补上另一个数组，中值/2后还是原来的结果(类似于: 3 * 2 / 2还是原来的结果)
        if (nums1.length == 0) nums1 = nums2; 
        if (nums2.length == 0) nums2 = nums1; 
        if (nums1.length == 1 && nums2.length == 1) return (nums1[0] + nums2[0]) /2.0; // 对于这类型直接返回
        
        // 2. 声明基本变量
        int len = nums1.length + nums2.length; // 获取总长度
        int mid = len / 2 + 1,i = 0, j = 0; // 使运行到这里长度总>=3，mid中值的位置(3/2+1=2、4/2+1=3)
        int[] ary = new int[2]; // 创建用于存储中值的固定长度数组
        
        // 3. 核心代码
        while(i < nums1.length && j < nums2.length){ // 假定两个数字长度相同，和一个数组遍历到临界点的时候，刚好i + j == mid
            if(nums1[i] < nums2[j]) ary[(i + j )%2] = nums1[i++]; // 比较后赋值，在ary的0或1位置
            else ary[(i + j)%2] = nums2[j++];
            if(i + j == mid) break; // 达到中值临界点，主动退出循环
        }
        // 对两个数组长度不一，以及一个数组下标i或j先行达临界点(nums1.length=i或nums2.length==j)进行补充
        while (i + j < mid && i == nums1.length) ary[(i + j)%2] = nums2[j++];
        while (i + j < mid && j == nums2.length) ary[(i + j)%2] = nums1[i++];
        
        // 4. 判断后返回对应的运行结果
        if (len % 2 != 0) return ary[(i + j - 1)%2]; // 总长度为奇数，最后一个赋值就是中值。
        else return (ary[0] + ary[1]) / 2.0; // 总长度为偶数，直接返回他们相加的平均值。
    }
}
```
```python []
class Solution:
    def findMedianSortedArrays(self, nums1, nums2) -> float:
        # 1. 下面这些情况进行处理
        len1 = len(nums1)
        len2 = len(nums2)
        # 一个数组为空，补上另一个数组，中值/2后还是原来的结果(类似于: 3 * 2 / 2还是原来的结果)
        if len1 == 0: nums1 = nums2
        elif len2 == 0: nums2 = nums1
        if len1 == 1 and len2 == 1: return (nums1[0] + nums2[0]) / 2 # 这个情况直接返回

        # 2. 获取基本变量信息
        lenAll = len1 + len2
        mid = int(lenAll / 2 + 1) # 使运行到这里长度总>=3，mid中值的位置(3/2+1=2、4/2+1=3)
        i = j = 0 # 便利索引
        ary = [0, 0] # 存储中值的列表

        # 3. 核心代码
        while i < len1 and j < len2:
            # 假定两个数字长度相同，和一个数组遍历到临界点的时候，刚好i + j == mid

            if nums1[i] < nums2[j]:
                ary[(i + j) % 2] = nums1[i]
                i += 1
            else:
                ary[(i + j) % 2] = nums2[j]
                j += 1
            if i + j == mid: break # 达到中值 退出循环
        # 对两个数组长度不一，以及一个数组下标i或j先行达临界点(nums1.length = i或nums2.length == j)进行补充
        while i + j < mid and i == len1:
            ary[(i + j) % 2] = nums2[j]
            j += 1
        while i + j < mid and j == len2:
            ary[(i + j) % 2] = nums1[i]
            i += 1

        # 4. 判断后返回对应的运行结果
        if lenAll % 2 != 0:
            return ary[(i + j - 1) % 2] # 总长度为奇数，最后一个赋值就是中值。
        else:
            return (ary[0] + ary[1]) / 2 # 总长度为偶数，直接返回他们相加的平均值。
```
# 复杂度:
时间复杂度度: O(n)
空间复杂度: O(1)
100% 靠运气，不过90%+是没有问题的。 
![4f4547e9b6c53b373555213d62b169a.png](https://pic.leetcode-cn.com/fa298697aa12af077f011ae14eab7949d5ba6c4acd324021d264bfdc9f510e10-4f4547e9b6c53b373555213d62b169a.png)

被虐了这么久，自己想出来还是有点成就感的~
30题首次写贴，望各位大佬多多照顾，有错误的地方希望指正~
