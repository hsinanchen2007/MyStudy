### 解题思路
![QQ图片20200117102129.png](https://pic.leetcode-cn.com/318265d4940f32f0ae022e0af4c3f5455755beea6c548ce47d380edd7dce6be0-QQ%E5%9B%BE%E7%89%8720200117102129.png)

1. 先找分界点，在上一问的基础上，找分界点有2个问题
    + 可能最后剩余的两点相等，此时选low
    + 左右相等，此时认准一边（如右边）一直比较，由于右边数的特殊性，只要有一个数不等于nums[mid]，此时已可确定右边无序。

2. 在分界点的基础上，两次二分。
3. 最后要注意，bool类型  -1也是true。

### 代码

```cpp
class Solution {
public:
     int binary_search(vector<int> nums,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                low = mid+1;
            else
                high = mid-1;
        }
            return -1; 
    }

    int find_dot(vector<int>nums,int low,int high)
    {
        if(low<high-1)
        {
            int mid =  (low+high)/2;
            if(nums[mid]<nums[high])//右侧有序
                return find_dot(nums,low,mid);
            else if(nums[mid]>nums[low])
                return find_dot(nums,mid,high);
            else //两边相同，继续比
            {
                int i;
                for(i=high;i>mid&&nums[i]==nums[mid];i--);
                if(i==mid)//右边有序
                    return find_dot(nums,low,mid);
                else
                    return find_dot(nums,mid,high);

            }
        }
        else
        {
            if(nums[low]==nums[high])
                return low;
            return high;
        }
            
    }

    bool search(vector<int>& nums, int target) {
    if(nums.size()==0)
        return false;
    int dot = find_dot(nums,0,nums.size()-1);
    if(nums[dot]==target)
        return true;
    else
    {
        int status = binary_search(nums,0,dot-1,target);
        if(status!=-1)
            return true;
        else
            return binary_search(nums,dot+1,nums.size()-1,target)!=-1?true:false;
    }
    }
    
};
```