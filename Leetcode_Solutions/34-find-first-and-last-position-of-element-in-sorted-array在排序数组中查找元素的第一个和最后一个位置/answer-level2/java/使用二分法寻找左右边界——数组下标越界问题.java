### 解题思路
拿到该题目后，根据题中所给的要求即将时间复杂度限制在log(n)水平，想到需要使用二分法。分析该题目，发现所给的数组为升序有序数组，并且其中有可能出现重复的元素。
初步的思路为先使用二分法寻找左边界或右边界，找到之后重新初始化left和right参数，再使用二分法找到另外一个边界。
由于返回的结果为数组，故先定义结果数组`result = {-1, -1}`，然后对所给的有序数组进行检测，如果为空数组或null，直接返回初始化的result。
然后先寻找右边界，关键代码如下：
```java
while(left < right){
    int mid = (left + right) >>> 1;
    // 先找右边界
    if(nums[mid] == target){
        left = mid + 1;
    }
    else if(nums[mid] > target){
        right = mid;
    }
    else if(nums[mid] < target){
        left = mid + 1;
    }
}
// 这里如果跳出则left = mid = right，如果left==0且结束比较说明target < nums[0]，target不在nums序列中
if(left == 0){return result;}
```
如果`nums[mid] < target`，说明第一个可能的target必在mid的右侧（至少为`mid+1`）；如果`nums[mid] == target`，由于nums[mid]已经与target完成比较，故需要将left右移；如果`nums[mid] > target`，说明第一个可能的target必在mid的左侧。这里可能会出现一个问题，就是为什么不令`right = mid + 1`？
这里的写法可以追溯到初始时的left与right的赋值。这里令`left = 0, right = nums.length`，我们的搜索区间为`[left, right)`即左闭右开区间。如果需要改变right的值，显然我们已经完成nums[mid]与target的比较，由于区间右侧为开区间，不包括mid，故令`right = mid`而非`right = mid+1`。
while循环结束之后，我们添加了如下语句:
```java
if(left == 0){
    return result;
}
```
该段代码也是右边界寻找算法中需要注意的细节。当`target < nums[0]`时，显然应该返回[-1,-1],该情况下左边界left并没有移动，即此时`left == 0`是成立的。那么除了正确返回未找到信息，该段代码还有什么用处呢？这就要结合下面的代码说明。
```java
int right2 = nums[left-1] == target ? left-1 : -1;
```
这里right2即为找到的右边界，将其进行初始赋值是为了缩小寻找左边界过程中二分查找的范围，提高查找效率。由于每次为left赋值为`left = mid + 1`，这样当`right == mid + 1`时，显然满足`right == left`，循环跳出，这时就出现一个问题即nums[mid]并没有与target进行大小比较，于是需要增加一个nums[left-1]与target的比较。此时nums[left]与target一定不相等，而nums[left-1]与target可能相等。
继续回到上面提到的问题，如果不加上`left == 0`的处理语句，显然`left-1 == -1`，会发生数组下标越界问题。
![1.PNG](https://pic.leetcode-cn.com/e5c8721ea29865f337e815de97aa57f58498843300f984860e3769c3768a2a7e-1.PNG)

对right2和left2进行赋值后，继续使用二分法寻找左边界，最终返回result数组即可。

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] result = {-1, -1};
        if(nums == null || nums.length == 0){return result;}
        int left = 0;
        int right = nums.length;
        while(left < right){
            int mid = (left + right) >>> 1;
            // 先找右边界
            if(nums[mid] == target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
        }
        // 这里如果跳出则left = mid = right，如果left==0且结束比较说明target < nums[0]，target不在nums序列中
        if(left == 0){return result;}
        int right2 = nums[left-1] == target ? left-1 : -1;
        // 最终得到的右边界为left亦即right
        // 再找左边界
        if(right2 == -1){return result;}
        result[1] = right2;
        int left2 = 0;
        while(left2 < right2){
            int mid2 = (left2 + right2) >>> 1;
            // 寻找左边界
            if(nums[mid2] == target){
                right2 = mid2;
            }
            else if(nums[mid2] > target){
                right2 = mid2;
            }
            else if(nums[mid2] < target){
                left2 = mid2 + 1;
            }
        }
        // 最终得到左边界为left2
        result[0] = left2;
        return result;
    }
}
```