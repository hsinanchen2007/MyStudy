### 解题思路
最开始我的两种思路都是错的，我原本都没有考虑有序无序的问题，因为我觉得比大小可能不需要，但是其实我错了，我先把原先的思路说一下。
1.拿low和high比，low<high：high=mid-1;low>high:low=mid+1;原本可以运行，结果4,1,2,3，不通过。之后我又思考，与其比较两边不如我自己比较mid-1和mid+1，这样也能确定下一次的查找范围。
2.拿mid-1、mid+1和mid比，mid-1<mid:high=mid-1;mid+1<mid:low=mid+1;我以为又可以运行了，结果2,3,4,1，又不通过。

**************************************************************************************************
**************************************************************************************************
上面的思路是错的，这是我做题时候一步一步的思路
下面的思路是对的，通过上面的经验得到的
**************************************************************************************************
**************************************************************************************************
之后我又重新捋捋思路，我觉得我一开始不考虑有序无序的想法是不对的，于是我就重新思考，把有序无序的情况考虑一下，一个就四种情况。就是下面的代码
![image.png](https://pic.leetcode-cn.com/ed2301629e06692e224b6e0fd01371bc24b4b3bdbacdbd6accbda2500da38f9f-image.png)


### 代码

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            //越界不容易处理，感觉我处理越界有点麻烦，或者是整个思路有点问题，但是还是可以借鉴的
            if(mid==0&&nums[mid]<nums[mid+1])
                return nums[mid];
            else if(mid==nums.size()-1&&nums[mid]<nums[mid-1])
                return nums[mid];
            else if((mid!=0&&mid!=nums.size()-1)&&nums[mid]<nums[mid-1]&&nums[mid]<nums[mid+1])
                return nums[mid];
            if(nums[low]<=nums[mid])//前半部分有序,包含low==mid的情况
            {
                if(nums[low]>nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
            else//后半部分有序
            {
                if(nums[mid]>nums[mid-1])//mid-1一定存在,因为nums[mid]>mid[low]
                    high=mid-1;
                else
                    return nums[mid];
            }
        }
        return -1;
    }
};
```