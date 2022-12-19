# 来源：
这种二分查找的思路来自于清华大学邓老师的数据结构里面的binarySearchC,这种方法实现非常简单，思路非常漂亮，课程可以在[B站](https://www.bilibili.com/video/av49361421?p=71)上搜索到。
# 思路：
在看到题目要求的时间复杂度$O(logn)$时就很容易想到是利用二分法进行查找了，显然一般来说二分法只能查找到一个元素的位置，所以在这个里面至少需要用到两次二分法进行查找。
## 第一次二分法：
第一次二分法查找到的是不小于当前元素的第一个元素，先上代码，然后会对代码进行证明：
```
vector<int> res = {-1, -1};
int lo = 0, hi = nums.size();
while(lo < hi){
    int mi = ( lo + hi ) / 2;
    nums[mi] < target ? lo = mi + 1 : hi = mi;
}
/* 
*  循环结束时lo即为不小于当前元素的第一个元素，由于是不小于，所以需要
*  对该元素判断，看是否是目标元素，如果不是就证明数组里面没有这个元素
*  直接返回[-1,-1]，如果是,将左边界赋值成lo，就完成了第一个位置查找。
*  如果查找的元素不存在且大于最大的元素，lo == nums.size() 所以需要
*  对这种情况单独进行判断。
*/
if(lo == nums.size()) return res;
if(nums[lo] == target)res[0] = lo;
else return res;

```
**算法证明：**
算法的核心就是代码:
```
nums[mi] < target ? lo = mi + 1 : hi = mi;
```
我们假设在任意时刻都满足[0,lo)的元素均比target小且[hi,n)的元素均不小于target，利用数学归纳法进行证明：
1. 初始时lo = 0, hi = n,所以[0,0)以及[n,n)均为空集显然成立。
2. 假设第m-1次循环时满足[0,lo)的元素比target小且[hi,n)元素不小于target，如图第二行所示
![binarySearch.png](https://pic.leetcode-cn.com/c2b170e446a0f9276a07246c639aaf4bd7f3a17e7d4b98609b63adab6e9f82ec-binarySearch.png)
3. 经过一次比较以后会出现以下两种情况：
>1.如果 x < target 则 lo = mi + 1 会变成第三行的情况，这个时候因为x都比target小那么[0,mi]肯定都是小于target的，所以[0,lo)的元素都比target小。
>2.如果 target <= x 则 hi = mi 会变成第一行的情况，这个时候因为x不小于target，所以[mi,n)肯定都是不小于target的，此时 hi = mi 所以[hi, n)都是不小于target的。
4. 综上可以得到每一次迭代假设都是成立的。
5. 终止条件是lo == hi, 不会出现lo > hi可以自行用两个元素举例。
6. 根据上面分析可以知道当lo == hi时，[0,lo)均小于target，[lo,n)均不小于target所以这个时候lo指向的就是不小于target的第一个元素，最后在进行一次判断来确定元素是否存在，存在时左边界就是lo。

## 第二次二分法
第二次二分法查找到的元素时大于target的第一个元素，先上代码：
```
hi = nums.size();
while(lo < hi){
    int mi = ( lo + hi ) / 2;
    target < nums[mi] ? hi = mi : lo = mi + 1;
}
res[1] = nums[lo - 1]; 
```
这个时候已经知道了左边界，所以没有必要再将lo变成0了，直接对[lo,n)进行查找就行了，同时也因为第一次查找已经确定了肯定有这个元素，所以直接对右边界进行赋值就可以了。
**算法证明**
这一块的核心代码是：
```
target < nums[mi] ? hi = mi : lo = mi + 1;
```
这一次假设任意时刻都满足[0,lo)的元素都不大于target,而[hi,n)的元素都是比target大的：
1. 初始时刻成立，并且假设第n-1次成立。
2. 在第n次迭代时，出现两种情况：
![binarySearch(last rank).png](https://pic.leetcode-cn.com/a8637b53338552b6704c07eb628955a3b1dd7c34ece9c59020f7cf3129f7dbbf-binarySearch\(last%20rank\).png)
>1.target < x 时, hi = mi, 会变成第一行的情况，因为x比target大所以，[hi,n)的元素都比target大
>2.x <= target时，lo = mi + 1, 会变成第三行的情况，因为x不大于target，所以[0,lo-1]都不会比target大
3. 所以经过迭代整个算法是成立的，同样在最后会收敛到lo == hi的情况，此时,[0,lo-1]都不大于target,而[lo,n)都大于target所以，lo指向的是大于target的第一个元素，如果元素存在lo-1就是元素的最后一个位置。

所以最终的代码为：
```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if(nums.size() < 1) return res;
        // 第一次二分查找，找到左边界
        int lo = 0, hi = nums.size();
        while(lo < hi){
            int mi = ( lo + hi ) / 2;
            nums[mi] < target ? lo = mi + 1 : hi = mi;
        }
        // 经评论区 @Kang M.X.指出，原答案在第一次遍历的时候如果查找元素不存在且大于最大值，会发生越界，所以需要单独对数组越界情况进行判断。
        if(lo == nums.size()) return res; 
        if( target == nums[lo]) res[0] = lo;
        else return res;
        // 第二次二分查找，找到右边界
        hi = nums.size();
        while(lo < hi){
            int mi = ( lo + hi ) / 2;
            target < nums[mi] ? hi = mi : lo = mi + 1;
        }
        res[1] = lo - 1;
        return res;
    }
};
```