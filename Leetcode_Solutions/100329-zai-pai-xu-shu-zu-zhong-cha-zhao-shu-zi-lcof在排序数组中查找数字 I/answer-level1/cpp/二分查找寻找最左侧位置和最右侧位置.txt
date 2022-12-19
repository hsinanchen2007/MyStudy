### 解题思路
转化为寻找有序数组中第一个等于target的值的位置（最左侧）和最后一个等于target的值的位置（最右侧）
第一个等于target的值的位置(最左侧),代码如下:
```
int l = 0,r = len - 1;
while(l<=r){
    int mid = l+(r-l)/2;
    if(nums[mid]>=target) r = mid -1; // 容易理解 mid位置不小于k，那mid位置之前可能也有，所有要往前搜
    else l = mid + 1;  // 容易理解向后搜
}
```
三种情况分析:
1、全部大于target r == -1，l存储第一个大于target的值；
2、全部小于target，l==len，r位置存储第一个小于target的值;
3、存在等于target的值，l存储该值; 
4、不存在等于target的值，但是target在区间内，r存储第一个小于target的值，l存储第一个大于target的值。 

对于本题 只用判断l在合适区间内，值是否等于target即可

最后一个等于target的值
```
int l = 0,r = len - 1;
while(l<=r){
    int mid = l+(r-l)/2;
    if(nums[mid]<=target) l = mid+1;
    else r = mid - 1;
}
```
如果存在等于target的值，肯定在r位置上。注意r的区间。

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 二分查找 寻找最左侧出现的位置和最右侧出现的位置
        int len = nums.size();
        if(len<1) return 0;
        int left = 0,right = len-1;
        // 寻找左侧位置
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]>=target) right = mid-1;
            else left = mid+1;
        }
        int x;
        if(left<len){
            if(nums[left]==target) x = left;
            else return 0;
        }
        else return 0;
        // 寻找右侧位置
        left = 0; right = len-1; 
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]<=target) left = mid+1;
            else right = mid - 1;
        }
        int y;
        if(right>=0){
            y = right;
        }
        else return 0;
        // cout<<x<<" "<<y;
        return y-x+1;
    }
};
```