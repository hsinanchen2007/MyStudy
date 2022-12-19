用两个对象来存储当前窗口的最大值和最大值索引。

实际上可以分析，在实行滑动窗机制时，什么样的情况下才需要对最大值进行更新：

1）当新添加进滑动窗口中的值比上一个窗口中最大值更大时，那也就说明这个新添加进来的值一定比当前窗口中的其他所有值都大，此时更新最大值的索引和最大值本身。

2）当新添加进滑动窗口中的值比上一个窗口中最大值更小，且上一个窗口中的最大值已经不在当前滑动窗口中时，重新寻找滑动窗口中的最大值和最大索引；

3）当新添加进滑动窗口中的值比上一个窗口中的最大值更小，但是上一个窗口中的最大值仍然存在于当前的滑动窗口中，此时不需要更新最大值。

上述判别条件伪代码如下：
```c++
        if(新值>=上一窗口中的最大值)
            更新当前窗口中的最大值的索引;
        else{
            if(上一个窗口中的最大值仍在当前窗口中)
                无需更新当前窗口最大值索引；
            else
                重新寻找当前长度为k的窗口中的最大值及其索引；
        }
```
代码如下：
```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int size = nums.size();
        int max_inx = findMaxInKNums(nums, 0, k);
        int max_val = nums[max_inx];
        res.push_back(max_val);
        if(size==k) return res;
        
        for(int i=1; i<size-k+1; i++){
            if(nums[i+k-1]>=max_val){
                max_inx = i+k-1;
                max_val = nums[i+k-1];
                res.push_back(max_val);
            }
            else{
                if(max_inx>=i) res.push_back(max_val);
                else{
                    max_inx = findMaxInKNums(nums, i, k);
                    max_val = nums[max_inx];
                    res.push_back(max_val);
                }
            }
        }
        return res;
    }
    int findMaxInKNums(vector<int> nums, int inx, int k){
        int max_val=nums[inx+0], max_inx=inx+0;
        for(int i=1; i<k; i++){
            if(nums[inx+i]>max_val){
                max_val = nums[inx+i];
                max_inx = inx+i;
            } 
        }
        return max_inx;
    }
};
```
