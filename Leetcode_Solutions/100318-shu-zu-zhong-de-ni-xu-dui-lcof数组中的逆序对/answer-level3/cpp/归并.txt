一、前言：
    我滴老天鹅啊，这道题反反复复写，从早先的暴力到插入排序再到归并排序，中间发现过好多错呜呜呜，像无头苍蝇，四处乱撞；
    经常有逻辑问题和超时警告。反反复复折腾，最终把归并排序更理解了记住了。噗噗。我太弱了，欢迎大家指正，谢谢。
    写不出文绉绉的话，因为下次我自己再看还要重新理解，所以我以下的解释看起来很像外行人呐。。

二、思路：
1. 归并排序：先对半分（分到最后只有单个对单个的元素）；然后两个有序数组合并。
2. 累计求逆序数：注意不要出现重复。
    - 左右都还有剩的：
        - 若左边当前数a = nums[lpos] 大于 右边数b = nums[rpos]，则右边出来存到合并后的对应位置。
             可理解为：左边剩下的最小的数比右边这个数大，也就是说左边剩下的数都比b大，左边离开的数都比b小。
             即：左边剩下元素个数mid-(lpos-1) 为：未计算过的，和b构成逆序的对数。❤
        - 若左边当前数a 小于 右边数b，则左边出来存到合并后的位置。
             左<右此时不构成逆序。
    - 左侧还有剩的，右边都输出完了：
        - 左侧剩的都比右侧大，构成逆序，但是！划重点！在❤那里，对于右侧的这些元素来说，左侧能跟小右们构成逆序的对数已经计算过了，所以不用再计算了。
    - 右侧还有剩的，左侧都输出完了：
        - 右边数大于左边所有数，左<右此时不构成逆序。

三、代码：
```
class Solution {
public:
    int reversePairs(vector<int>& nums)  {
        int res = 0;
        vector<int>temp(nums.size(),0);
        MergeSort( nums, 0, (int)nums.size()-1, temp, res );
        return res;
    }
    void MergeSort( vector<int>& nums, int left, int right, vector<int>& temp, int &res ){
        if( left < right ){
            int mid = left+(right-left)/2; // 用left+right再/2，运行时间会多44ms？为什么呀？
            MergeSort( nums, left, mid, temp, res );
            MergeSort( nums, mid+1, right, temp, res );
            // 合并
            int lpos = left, rpos = mid+1, tpos = left;
            while( lpos<=mid && rpos<=right ){ // 当有一边输出完，就停止                
                if( nums[lpos] > nums[rpos] ){ // 左>右
                    temp[tpos++] = nums[rpos++];
                    res += mid-lpos+1;
                }else{ temp[tpos++] = nums[lpos++]; }
            }
            while( lpos <= mid ){ temp[tpos++] = nums[lpos++]; }
            while( rpos <= right ){ temp[tpos++] = nums[rpos++]; }
            while( left <= right ){
                nums[left] = temp[left];
                left++;
            }
        }
    }
};
```
