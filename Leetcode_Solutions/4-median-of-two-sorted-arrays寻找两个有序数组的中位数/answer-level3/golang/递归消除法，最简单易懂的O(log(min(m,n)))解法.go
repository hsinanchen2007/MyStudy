前几的解法很难看懂，甚是不友好。鄙人尝试从新的角度看问题。下面是自己对此题的理解，如果有不妥的地方，望大神斧正。
# 思路
在统计中，中位数被用来：
>将一个集合划分为两个长度相等的子集，其中一个子集中的元素总是大于或等于另一个子集中的元素。

### 和中位数无关的元素
假设一个集合A被中位数划分成两个长度相等的子集A1和A2，A1中的元素总是小于或等于A2中的元素。

![image.png](https://pic.leetcode-cn.com/3a476066b18ed5d79fb6514e2f528c6f80ec00d89d9a5f4483259ae7bb56be21-image.png)


如上图所示的集合A，其中位数是4.5。


当我们同时从A1和A2中移除任意n个元素（不移除A1最大元素和A2最小元素），集合A的中位数是不变的。

![image.png](https://pic.leetcode-cn.com/45a414524255dd00200b87d0e353680a787afb361ca89a6be803b4c5987f319f-image.png)

即我们移除A1中的1,2,3这三个元素中的任意n个，同时移除A2中的6,7,8这三个元素的任意n个，集合A的中位数还是4.5。
所以我称1,2,3,6,7,8这几个元素是**和中位数无关的元素**。即对称地移除他们时，对集合的中位数没有影响。

元素个数为奇数的情况稍有不同，但是也是类似的。

### 中位数的位置
回到这个题目上。

基于上述的原理，我们是否可以通过排除**和中位数无关的元素**，最终得到中位数？

此解法的重点是：要知道中位数的位置。（这不是扯淡吗，我知道中位数的位置直接返回不就完了。- -!）

我们这里不是求中位数的确切位置，而是求中位数的大概位置。

假设题目给出的两个有序集合为B1和B2,他们的长度为m和n。
设 midM = (m-1)/2（暂不考虑m=0的边界情况）
设 midN = (n-1)/2
如果n%2=0：
设midNP = midN + 1
否则midNP = midN

![image.png](https://pic.leetcode-cn.com/32bb274244782a1ece5e944b002ae9fdd8de1a41ea7bc0f7be3a655be264996c-image.png)


那么这两个集合的并集的**中位数的值median,必定是：2<=median<=7**。否则median无法将B1和B2的并集切分为等长的两部分。（证明过程就不给出了，数学比较差，但是代码运行结果证明这个推论是正确的。）

所以，根据上述推论可以得出，1,8是**和中位数无关的元素**。

![image.png](https://pic.leetcode-cn.com/f27361eabcd05264d07d36c88ecb069bc0491abbcf635a9ad12800a862e581f6-image.png)


消除元素1和8从而得到更短的两个集合，如下图。其并集中位数不变，还是4.5。

![image.png](https://pic.leetcode-cn.com/fef007ef9c699d483d4d6d39ed8455a88162873a901f0236cb24c5b8c473b85c-image.png)



接下来重复以上的步骤。由于每次排除元素的数量是较短集合的一半元素，所以经过log(min(m,n))次迭代之后，到达边界条件。

过程如动图：
![新建 Microsoft PowerPoint 演示文稿 (3).gif](https://pic.leetcode-cn.com/c999b04d9a985906fc0e0cda91c2b276c34c1e1fe041cb7cc5536c0078bb6c59-%E6%96%B0%E5%BB%BA%20Microsoft%20PowerPoint%20%E6%BC%94%E7%A4%BA%E6%96%87%E7%A8%BF%20\(3\).gif)


该算法的时间复杂度为O(log(min(m,n)))。

# 编码
利用上面说的特性，递归部分的实现就很明朗了：
```golang []
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	var m = len(nums1)
	var n = len(nums2)
	if n < m { // 确保nums1比nums2短，即确保m比n小
		var temp = nums1
		nums1 = nums2
		nums2 = temp
		m = len(nums1)
		n = len(nums2)
	}
	var midM = (m - 1) / 2
	var midN = (n - 1) / 2

	if m == 0 {...} // 处理长度为0的情况

	if m == 1 || m == 2 {...} //此处是边界条件处理，O(1)时间复杂度

	
	// n为奇数时，midNP==midN。n为偶数时，midNP==midN+1。
	var midNP = midN
	if n%2 == 0 {
		midNP++
	}

	if nums1[midM] == nums2[midNP] {//两值相等的情况下，其值就是中位数
		return float64(nums1[midM])
	}
	if nums1[midM] < nums2[midNP] {
		//消除nums1数组0至midM-1下标的元素，和nums2数组n-midM下标之后的元素
		return findMedianSortedArrays(nums1[midM:], nums2[:n-midM])
	}
	//消除nums2数组0至midM-1下标的元素，和nums1数组n-midM下标之后的元素
	return findMedianSortedArrays(nums2[midM:], nums1[:m-midM])
}

```
```python []
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1)
        n = len(nums2)
        if n < m:
            temp = nums1
            nums1 = nums2
            nums2 = temp
            m = len(nums1)
            n = len(nums2)

        mid_m = (m - 1) // 2
        mid_n = (n - 1) // 2

        if m == 0:
            return nums2[mid_n] if (n % 2) == 1 else (nums2[mid_n] + nums2[mid_n + 1]) / 2

        if m == 1 or m == 2://边界条件处理
            ...

        mid_np = mid_n if n % 2 == 1 else mid_n + 1

        if nums1[mid_m] == nums2[mid_np]:
            return nums1[mid_m]
        if nums1[mid_m] < nums2[mid_np]:
            return self.findMedianSortedArrays(nums1[mid_m:],nums2[:n-mid_m])
        return self.findMedianSortedArrays(nums1[:m-mid_m], nums2[mid_m:])

```



# 边界条件处理
最终到达边界的情况下，nums1的长度可能是1或者2。对于这两种情况，我们只需拿nums1剩下的数和nums2中间几位数进行排序，就能得到中位数。
由于进行排序的数组长度最长是6，故其时间复杂度为O(1)。

完整代码如下：

```golang []
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	var m = len(nums1)
	var n = len(nums2)
	if n < m { // 确保nums1比nums2短，即确保m比n小
		var temp = nums1
		nums1 = nums2
		nums2 = temp
		m = len(nums1)
		n = len(nums2)
	}
	var midM = (m - 1) / 2
	var midN = (n - 1) / 2

	if m == 0 { // 处理长度为0的情况
		if n%2 == 1 {
			return float64(nums2[midN])
		}
		return float64(nums2[midN]+nums2[midN+1]) / 2
	}

	if m == 1 || m == 2 { // 边界条件
		if n < 3 { // n小于3的情况下，取nums2所有元素和nums1的元素进行排序
			for i := 0; i < n; i++ {
				nums1 = append(nums1, nums2[i])
			}
		} else if n%2 == 1 { // n大于2且为奇数的情况下，取nums2中间3位和nums1的元素进行排序
			for i := midN - 1; i < midN+2; i++ {
				nums1 = append(nums1, nums2[i])
			}
		} else { // 其他情况下，取nums2的中间4位和nums1的元素进行排序
			for i := midN - 1; i < midN+3; i++ {
				nums1 = append(nums1, nums2[i])
			}
		}
		sort.Ints(nums1)
		m = len(nums1)
		midM = (m - 1) / 2

		if len(nums1)%2 == 1 {
			return float64(nums1[midM])
		} else {
			return float64(nums1[midM]+nums1[midM+1]) / 2
		}
	}


	// n为奇数时，midNP==midN。n为偶数时，midNP==midN+1。
	var midNP = midN
	if n%2 == 0 {
		midNP++
	}

	if nums1[midM] == nums2[midNP] {
		return float64(nums1[midM])
	}
	if nums1[midM] < nums2[midNP] {
		//消除nums1数组0至midM-1下标的元素，和nums2数组n-midM下标之后的元素
		return findMedianSortedArrays(nums1[midM:], nums2[:n-midM])
	}
	//消除nums2数组0至midM-1下标的元素，和nums1数组n-midM下标之后的元素
	return findMedianSortedArrays(nums2[midM:], nums1[:m-midM])
}

```
```python []
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1)
        n = len(nums2)
        if n < m:
            temp = nums1
            nums1 = nums2
            nums2 = temp
            m = len(nums1)
            n = len(nums2)

        mid_m = (m - 1) // 2
        mid_n = (n - 1) // 2

        if m == 0:
            return nums2[mid_n] if (n % 2) == 1 else (nums2[mid_n] + nums2[mid_n + 1]) / 2

        if m == 1 or m == 2:
            if n < 3:
                nums1.extend(nums2)
            elif n % 2 == 1:
                nums1.extend(nums2[mid_n - 1:mid_n + 2])
            else:
                nums1.extend(nums2[mid_n - 1:mid_n + 3])
            nums1.sort()
            m = len(nums1)
            mid_m = (m - 1) // 2
            return nums1[mid_m] if m % 2 == 1 else (nums1[mid_m] + nums1[mid_m + 1]) / 2

        mid_np = mid_n if n % 2 == 1 else mid_n + 1

        if nums1[mid_m] == nums2[mid_np]:
            return nums1[mid_m]
        if nums1[mid_m] < nums2[mid_np]:
            return self.findMedianSortedArrays(nums1[mid_m:],nums2[:n-mid_m])
        return self.findMedianSortedArrays(nums1[:m-mid_m], nums2[mid_m:])
```


谢谢各位观看