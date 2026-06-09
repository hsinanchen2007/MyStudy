```
class Solution {
    //需要满足要求（1）数组大小非常大，不能先存储再遍历得到数组长度（2）每个等于 给定数字 的 元素被选择的概率相等。
    //证明参考https://blog.csdn.net/tywwwww/article/details/98351439
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums=nums;
    }
    
    int pick(int target) {
        int flag=1;//是否第一个满足要求的
        int res;
        
        int ind=-1;
        int cnt=1;//等于target的数的 个数
        for(auto c:nums){
            ind++;
            if(flag==1){//第一个满足要求的数的 ind 赋值给 res
                if(c==target){
                    res=ind;
                    flag=0;
                    
                }
                continue;
            }
            //第二个及之后等于target的元素是否被选择的概率p=1/(cnt+1)，至于为什么是这样，看链接
            if(c==target){
                if((rand()%(cnt+1))==cnt){
                    res=ind;
                }
                             
                cnt++;
            }    
            
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

/*
执行用时 :88 ms, 在所有 C++ 提交中击败了99.01%的用户
内存消耗 :18.7 MB, 在所有 C++ 提交中击败了95.00%用户
*/
```

