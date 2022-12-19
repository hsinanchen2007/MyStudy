```c++
// 作者：yangqinkuan
// 链接：https://leetcode-cn.com/problems/missing-ranges/solution/java-yong-yi-ge-zuo-bian-jie-zhi-zhen-zhu-yao-kao-/
class Solution {
    public:
    // 由于是排好序的数组,我们使用next表示下一个应该遍历到谁,next初始化为lower
        // 如果当前遍历遍历到的是next,那么表明是连续的继续,要注意更新next为nums[i]+1;
        // 如果遍历到的不是next,说明有缺失,但是我们要区分缺失一个(添加一个数字),还是缺少两个和以上(A->B的形式)
        // 最后我们还要看距离上界upper是否还差着 关于这个我们可以通过在nums后面插入一个upper+1来解决
        // 但是要特别注意越界的问题,所以所以我们的next使用long  同时没有在nums后插入upper+1 而是在循环外再进行讨论

    vector<string> findMissingRanges(vector<int>&nums, int lower, int upper) {
        vector<string> res;
        long next= lower; //刚开始的时候,我们应该要遍历的是lower
        for(int i=0;i<nums.size();i++){
            if(next+1==nums[i]){ // 我们该遍历4了 但是遍历的却是5 说明4缺失 只缺失一个数字 
                res.push_back(to_string(next)); //所以插入 "4"即可
            }else if(next+1<nums[i]){ //我们该遍历4了 但是遍历得却是10 说明4->9都缺失
                res.push_back(to_string(next)+"->"+to_string(nums[i]-1));
            }
            next= (long)nums[i]+1; //要注意更新next  为了防止溢出 还要把nums[i]先从int转成long
        }
        // 最后与upper比较
        if(next==upper) { 
           res.push_back(to_string(next)); //就差upper一个
        }else if(next<upper){
            res.push_back(to_string(next)+"->"+to_string(upper)); //差next->upper这个区间
        }
        return res;
    }
};
```