### 解题思路
暴力法：
从左到右寻找到第一个target为左位置，若遍历完没有则返回-1，右也直接返回-1即可。因为数组没有这数字。否则，从右到左寻找到第一个target为右位置。但是这样的算法时间复杂度是O(n)。
二分法：
记住一点：排序的数组，第一想到二分法，二分法就是基于有大小比较而生的方法。
二分法思路简单，但是细节复杂，左右边界的设置就是易错点。
1.while（left?right）是小于还是小于等于要看right的设置。a——right若为length，那么区间是左闭右开的，也就是当left==right的时候，[left，right）区间内没有元素，循环结束。b——若right为length-1，那么区间全闭，也就是[left,right]时，区间内还有一个元素，结束终止条件应该是left>right。所以a情况为<,b情况为<=，保证循环结束的时候，区间内没有元素。
2.left和right与middle的关系，也就是区间缩小的设置。当middle比较完后，就可以排除在外了。a情况下，right==middle即可，因为右开，left==middle+1，左闭。b情况下，left==middle+1，right==middle-1。
3.怎么缩小区间。寻找左边界时，我们要把区间往左边缩，也就是关注的是right。当middle处数==target时，right前移到此时middle的前一位置，当大于target时也是。因为要找到的是第一个target，所以大于等于它的数都不需要在区间。当小于时，left后移到此处的后一位置。最终，区间关闭时，right停留在第一个target的前一位置，此时left的位置前面说过，结束的位置必定是right+1处。所以返回left即可。若是右开，那么此时right在target位置，因为区间开的原因，区间里没有它。left==right，return谁都可以，为了方便，return left，毕竟我们找的是左边界。同样的逻辑，寻找右边界时，区间往右缩，关注的是left。小于等于的数不需要在区间，最后left停止在最后一个target的后一位置，因为左闭，所以两种情况一样，返回left-1即可。但还是探索下此时right的位置。若为开区间，此时left==right，若为闭区间，left需大于right，所以right此时在left-1位置。return right，便于理解。
总结一下3，寻找左边界时，大于等于target的数没用，排出区间，最后只需要记住，区间的右边界紧挨着的就是第一个target，1,2，（3）4,4,4,5,6，7。同理，5的左边就是target。根据right的设置，return就好。
4.最后一个问题，二分完没有时，有三种情况，target大于最大的数，寻找左边时，最后left会到数组的右界外。target小于最小的数，寻找右边时，right会到左界外。target大于最小，小于最大，但不在数组中。所以一定要有一个判别在不在数组中的操作。也就是要考虑极端情况。
5.细节至上，我也是想了好久才从区间这个角度上重新理解了二分法。
多说无益，代码献上。
### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        int length=nums.size();
        if(length<=0||target>nums[length-1]||target<nums[0])
        {
            return res;
        }
        int start=frontIndex(nums,target,0,length-1);
        int end=backIndex(nums,target,0,length-1);
        res[0]=start;
        res[1]=end;
        return res;
    }
    int frontIndex(vector<int>& nums,int target,int start,int end)
    {

        while(start<=end)
        {
            int middle=(start+end)/2;
            if(nums[middle]>=target)
            {
                end=middle-1;
            }
            else
            {
                start=middle+1;
            }
        }
        if(start>=nums.size()||nums[start]!=target)
            return -1;
        return start;
    }
    int backIndex(vector<int>& nums,int target,int start,int end)
    {

        while(start<=end)
        {
            int middle=(start+end)/2;
            if(nums[middle]<=target)
            {
                start=middle+1;
            }
            else
            {
                end=middle-1;
            }
        }
        if(end<0||nums[end]!=target)
            return -1;
        return end;
    }
};
```