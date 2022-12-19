ps：我写二分的习惯，一般都是if(left<right)，这样出来的结果肯定是我们想要的，如果是left = mid+1，mid = (left+right)/2，如果是取right = mid+1,就让mid = (left+right+1)/2，这样可以避免死循环。
话说那一题在154是hard难度，怎么到这就变成easy了。
难度在这
555555....5512345555....555
如果搜索到5的话，无法判断是该继续往左还是往右
于是，直接将二分写成递归形式，如果这种情况，左边和右边一起搜索。
```
class Solution {
public:
    int find(vector<int>& nums,int begin,int end)
    {
        while(begin<end)
        {
            if(nums[begin]<nums[end])
                return nums[begin];
            int mid = begin+(end-begin)/2;
            if(mid>0&&nums[mid]<nums[mid-1])
                return nums[mid];//这里肯定不能顺序往左边找的，这样就O(n)了
            if(nums[begin]==nums[end])
                return min(find(nums,begin,mid-1),find(nums,mid+1,end));
            else if(nums[mid]<nums[begin])
                end = mid;
            else
                begin=mid+1;
        }
        return nums[begin];
    }
    int minArray(vector<int>& nums) {
        return find(nums,0,nums.size()-1);
    }
};
```

还有下面这种处理方法：如果mid和右边相等，直接把right--，
但是这种方法在全部一样的时候复杂度会变成n，我还不如遍历一遍呢。
```
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0,right = numbers.size()-1;
        while(left<right){
            int mid = left+(right-left)/2;
            if(numbers[mid]>numbers[right])
                left = mid+1;
            else if(numbers[mid]<numbers[right])
                right = mid;
            else
                right--;
        }
        return numbers[left];
    }
};

```
