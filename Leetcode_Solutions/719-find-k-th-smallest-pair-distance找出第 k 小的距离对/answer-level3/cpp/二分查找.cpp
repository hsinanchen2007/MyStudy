设数组元素有n个，那么共有n*(n-1)/2个所谓的距离。这些距离的大小是有范围的，即最小的距离必大于等于0，最大的距离为数组的最大元素减去数组的最小元素。题目中所求的第k个最小距离就在其中。
我们可以用二分查找来找到这个目标距离，初始化l=0，r=最大距离。mid=(l+r)/2，计算出距离小于等于mid的数对的个数count。
1. 若count<k，则第k个最小距离不会在[l,mid]之间，故修改l=mid+1；
2. 否则，r=mid；(因为第k个最小距离在[l,mid]之间)；
```
int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());//nums数组一定要排序
        int l = 0, r = nums.back() - nums.front(), mid;
        while (l<r)
        {
            mid = (l + r) / 2;
            int count = findDistance(nums, mid);
            if(count<k)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    int findDistance(vector<int>& nums,int distance)//计算距离不会大于distance的数对个数
    {
        int res = 0, rightIndex = size - 1;//rightIndex初始化为最大元素的对应下标
        for (int i = nums.size() - 2; i >= 0;--i)//从右向左找  (从左向右找也可以)
        {
            while (rightIndex>i&&nums[rightIndex]-nums[i]>distance)
            {
                --rightIndex;
            }
            res += (rightIndex - i);
        }
        return res;
    }
```
