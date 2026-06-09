一般来说，这种数值范围是0~n-1，数组大小是n的题目都可以用以下三种方法来做:

1.桶排序来做，复杂度最坏会到达n，但是一般情况是不会到达这个复杂度的。
```
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=i){
                if(nums[i]==nums[nums[i]])
                    return nums[i];
                swap(nums[nums[i]],nums[i]);
            }
        }
        return -1;
    }
};
```
2.通过标记下标来做，比如有2，我们就把数组第二位标记成负数，如果某一位被标记了两次，那么就是重复的数，注意0的负数还是0，要特殊处理
```
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int zerocnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])]<0)
                return abs(nums[i]);
            if(nums[i]==0)
                zerocnt++;
            if(zerocnt>1)
                return 0;
            nums[abs(nums[i])]= -nums[abs(nums[i])];
        }
        return -1;
    }
};
```
3.以上空间复杂度是1，在空间复杂度为n的情况下，可以通过数组或者map标记来做
```
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            if(mp.count(nums[i])==0)
                mp[nums[i]]=1;
            else
                return nums[i];
        return -1;
    }
};
```