![image.png](https://pic.leetcode-cn.com/76fc99fef39b3684b09f66c8e1cdc7f081b738f665985fc8baf3955303ddaff0-image.png)

### 解题思路
 &emsp; **找到decrease的地方，这样就定位了两个有序数组，然后我大不了就在两个数组中分别使用二分查找呗**
 #### 问题转化成：如何找到decrease的地方？
 - dicrease 一定发生在最大值的地方，而最大值是唯一的，所以我们就先找到这个最大值，最大值的下一个位置（如果有），就是第二个有序数组起始的地方。
 #### 问题转化成：如何找到最大值？
可以采用二分法：(注意：**第二个数组的所有元素都比第一个数组的元素小**)
 - 假设我现在有了left和right，然后有了个mid。
    * 如果mid比left大，那么最大值可能是mid，也可能在mid往右的部分，于是我让left = mid。
    * 如果mid比left小，那么最大值肯定不是mid，并且最大值在mid往左的部分（往右会更小），所以我让right = mid-1.
其他细节就不说了，可以再看下注释。<br>

（有收获的话求个赞。）


### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int left = 0, right = nums.size()-1;
        if(nums[left]<nums[right]) return helper(nums,left,right,target);// 并没有分界点，那么直接二分查找
        while(left<right){// 二分法找最大值
            int mid = left+(right-left+1)/2;
            if(nums[mid] == target) return mid;// 找的时候顺便看下是否已经找到target了。该句可省略。
            if(nums[mid]>=nums[left]){// 注意此时mid一定在第一个有序数组中，因为第二个有序数组整个都比left小。
                left = mid;
            }else if(nums[mid]<nums[left]){// 注意此时mid一定在第二个有序数组中，所以mid肯定不是（我们要找的是最大值，也是第一个数组的最后一个元素）
                right = mid-1;
            }
        }
        int desIndex = left+1; // 第二个数组的起始下标
        if(desIndex<nums.size()){ 
            if(target<=nums[nums.size()-1]){// 如果target比第二个数组的最大值还小，那么只要在第二个数组中找一下就好了，找到就返回，找不到的话就肯定在整个数组中也没有。
                return helper(nums,desIndex,nums.size()-1,target);
            }else{
                return helper(nums,0,desIndex-1,target);
            }
        }else{
            return helper(nums,0,desIndex-1,target);
        }
    }
    int helper(vector<int>& nums,int left, int right,int target){ // 最基本的二分法找target   
        while(left<right){
            int mid = left+(right-left)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid]<target){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        if(nums[left] == target){
            return left;
        }
        return -1;
    }
};
```