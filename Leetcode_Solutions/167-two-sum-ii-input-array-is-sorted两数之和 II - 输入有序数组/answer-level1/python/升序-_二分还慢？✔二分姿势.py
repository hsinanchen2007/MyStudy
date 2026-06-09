### 解题思路
此题是两数之和的变形，既然题目给出升序，那么一定会想到一个二分法！（条件反射）
但是个人认为题目测试用例可能有问题，可能没有负数这种用例。

首先第一题.两数之和，使用双指针被打的满地找牙
```python []
def twoSum(nums: int, target: int) ->list:
    sort_nums = list(sorted(range(len(nums)),key=lambda k: nums[k]))
    head = 0
    tail = len(nums) - 1
    temp_sum = nums[sort_nums[head]] + nums[sort_nums[tail]]
    while temp_sum != target:
        if temp_sum > target:  # 大了，尾巴移动
            tail -= 1
        else:  # 小了，头部移动
            head += 1
        # 更新总和
        temp_sum = nums[sort_nums[head]] + nums[sort_nums[tail]]
    return [sort_nums[head], sort_nums[tail]]
```
被hash法完爆，因为时间复杂度为$O(nlog(n))$，对元素排序存下标值大小顺序。
而此题已经排序好了，那么双指针大法就ok了。

### 代码一、双指针
题目说了升序且一定有唯一解，就直接双指针，直到有`numbers[left]+numbers[right]=target`成立返回ok。
```python []
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1
        while left < right:
            if numbers[left] + numbers[right] < target:
                left +=1
            elif numbers[left] + numbers[right] > target:
                right -= 1
            else:
                return [left + 1, right + 1]
```
```c []
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
	*returnSize = 0;  // 弱智？当索引好了
	int left = 0, right = numbersSize - 1;
	int *res = (int *)malloc(sizeof(int) * 2);
	while (left <= right) {
		if (numbers[left] + numbers[right] == target) {
			res[(*returnSize)++] = left + 1;
			res[(*returnSize)++] = right + 1;
            return res;
		}else if (numbers[left] + numbers[right] > target) {
			right--;
		}else left++;
	}
    return NULL;  // 注意没有此会编译出错，没返回
}
```

### 代码二、第二个数二分查找
既然题目给出升序，感觉没用到？跟二分法扯不上关系？未免有点啥的。（其实在双指针扫描夹进就用到数组有序）
```python []
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        index, right = 0, len(numbers) - 1
        while index < right:
            left, diff = index + 1, target - numbers[index];
            while left <= right:
                mid = (right + left) >> 1
                if numbers[mid] == diff:
                    return [index + 1, mid + 1]
                elif numbers[mid] > diff:
                    right = mid - 1
                else:
                    left = mid + 1
            index += 1
```
![内二分最慢.jpg](https://pic.leetcode-cn.com/c9c49c816ad664e6aa2bff87e8ca2481cd877cd741af3425141318a63f86e593-%E5%86%85%E4%BA%8C%E5%88%86%E6%9C%80%E6%85%A2.jpg)
这效率还慢！不应该更快？比上面一次次地移动快很多吧。奇异了

### 代码三、先二分找右指针范围
参考了评论一些题解，先确定右指针的范围确实比上面二分查第二个数快很多。
比如：
`[0,1,3,5,9,12,....],target=4`:首先`right`直接可以定位到5处，然后再进行双指针，这样快多了，不管5后面还有多少数据，一定比从最右端移动强。
bisect_right上界函数返回索引i,在nums[:i]的元素小于等于target，因此可以限定查找范围。但是可能上界是数组长度，因此判断下。

```python []
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        from bisect import bisect_right
        left, right = 0, min(len(numbers) - 1, bisect_right(numbers, target))  # 最大右边界
        while left <= right:  # 闭合都无所谓，因为有答案
            if numbers[left] + numbers[right] < target:
                left += 1
            elif numbers[left] + numbers[right] > target:
                right -= 1
            else:
                return [left + 1, right + 1]
```

![确定右指针范围.jpg](https://pic.leetcode-cn.com/c8af410d4fc59373288ebc299a6c5f314b5a81c9cf1ad9e8087189bebd40b1cd-%E7%A1%AE%E5%AE%9A%E5%8F%B3%E6%8C%87%E9%92%88%E8%8C%83%E5%9B%B4.jpg)
**问题**:感觉测试用例有点问题，这样做的行为会导致负数出现的可能被pass，返回空。
`[-2,-1,0,0,0,2,2,5,5,7,7,7,7,9,11,12,13], 8`:这种放在上面代码中直接再查找右边界的时候就会把9去掉，而本题显然应该是`-1,9`才是结果，但是测试用例才17个，应该没有这种情况。

### 代码四、两头`跳跃`夹击
`[1,2,5,7,9],target=8`查找8
![大da.gif](https://pic.leetcode-cn.com/75766ddfe9d0fc31a22daf266bc08cdaa173314053c2dc4b77bc764d77b83f2a-%E5%A4%A7da.gif)
两侧都是二分寻找，找到最适合的位置，即使有负数的情况也不会漏掉，因为不去限定区间。
```python []
class Solution:
    def bisect(self, nums: List[int], left: int, right: int, target: int, isleft: bool) -> int:
        """If target exists in nums, return its true index.
        If not, if you look for the left, return the mid, otherwise return to mid-1.
        [1, 3, 5],3,:return 1
        [2, 3, 4],6,isleft=1:return 2
        [2, 3, 5],4,isleft=0:return 3
        """
        while left <= right:
            mid = (right + left) >> 1
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        return left if isleft else left - 1
        
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1
        while left < right:
            if numbers[left] + numbers[right] < target:
                left = self.bisect(numbers, left + 1, right, target - numbers[right], 1)
            elif numbers[left] + numbers[right] > target:
                right = self.bisect(numbers, left + 1, right, target - numbers[left], 0)
            else:
                return [left + 1, right + 1]
```
```c []
int bisect(int *nums, int left, int right, int target, bool isleft) {
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (nums[mid] == target) return mid;
		else if (nums[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return isleft ? mid : mid - 1;  // 左查询返回mid，右查返回mid-1
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
	*returnSize = 0;  // 弱智？
	int left = 0, right = numbersSize - 1;
	int *res = (int *)malloc(sizeof(int) * 2);
	while (left <= right) {
		if (numbers[left] + numbers[right] == target) {
			res[(*returnSize)++] = left + 1;
			res[(*returnSize)++] = right + 1;
		}else if (numbers[left] + numbers[right] > target) {
			right = bisect(numbers, left + 1, right, target - numbers[left], 0);
		}else left = bisect(numbers, left + 1, right, target - numbers[right], 1);
	}
	return res;
}
```
![最快python.jpg](https://pic.leetcode-cn.com/e12612621bf5025d3d578047caa59ecb69b3a7988e71e5197a6222cb3819beb0-%E6%9C%80%E5%BF%ABpython.jpg)