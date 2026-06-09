### 解题思路
十个二分九个错。
推荐先阅读：
二分查找模板解释：https://www.cnblogs.com/kyoner/p/11080078.html 
二分查找三种工作模式：https://leetcode-cn.com/explore/learn/card/binary-search/208/background/832/

该题实际求的是二分查找的左边界
1）香蕉的速度是二分的范围（1，max(piles[i])）
2）要达成H小时内的速度范围存在**左边界和右边界**，则取达成H小时的最小速度取左边界i。
小于i，则大于H小时；
大于i，则小于等于H小时。

如果是“可以在 H 小时内吃掉所有香蕉的**最大速度 K**”，则需要取右边界

以[30,11,23,4,20] H = 6为例
23,24,25,26,27,28,29都可以使H = 6,但是左边界是23，右边界是29


文章对二分查找：
1）基本的二分搜索
2）二分搜索的左边界
3）二分搜索的右边界

二分查找相关模板：
1）左边界模板：
```cpp
int left_bound(int[] nums, int target) {
    if (nums.length == 0) return -1;
    int left = 0;
    int right = nums.length; // 注意

    while (left < right) { // 注意
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid; // 注意
        }
    }
    return left;
}
```
2）右边界模板
```cpp
int right_bound(int[] nums, int target) {
    if (nums.length == 0) return -1;
    int left = 0, right = nums.length;

    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            left = mid + 1; // 注意
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    return left - 1; // 注意
```


二分查找相关函数：
1、binary_search(beg,end,val)
返回一个bool变量，以二分法检索的方式在[beg,end]之间查找val，找到返回true，找不到返回false。

2、lower_bound（beg,end,val）
返回一个迭代器，指向非递减序列**[first, last)**中的第一个大于等于（>=）val的位置
从左开右闭区间也可以看出，采用的模板左边界
 
3、upper_bound(beg,end,val)
返回一个迭代器，指向非递减序列**[first, last)**中的第一个大于 (>) val的位置。
从左开右闭区间也可以看出，采用的模板右边界+1；

注意：对于lower_bound & upper_bound()还有一个第四个参数greater<type>(),他会把不小于(>=)变为不大于(<=)得查找，把大于(>)变为小于(<)查找，因此使用时要求序列不是递增，而是递减！！！此外，还必须加头文件#include <functional>

4、equal_range(beg,end,val)
返回一个迭代器对(i,j)，其中i是在不破坏次序的前提下，value可插入的第一个位置（>=亦即lower_bound），j则是在不破坏次序的前提下，value可插入的最后一个位置（>亦即upper_bound）因此，[i,j)内的每个元素都等同于value，而且[i,j)是[beg,end)之中符合此一性质的最大子区间


### 代码

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {

        int result = 0;
        sort(piles.begin(), piles.end());
        int left = 1;
        int right = piles.back();
        while(left<right){
            int mid = left + (right - left) / 2;
            int count = 0;
            for (int j = 0; j < piles.size();j++){
                if(piles[j]%mid == 0){
                    count += piles[j] / mid;
                }else{
                    count += piles[j] / mid +1;
                }

                if(count>H){
                    break;
                }
            }

            if(count>H){
                left = mid+1;
            }else{
                right = mid;
            }

        }
        return left;
    }
};
```