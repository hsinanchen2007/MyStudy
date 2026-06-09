这次的收获：
1.排序是必须的
2.主要是第三个指针的去向（应该用循环来作为第三个指针）
3.记得用一个值存储最接近值
```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int l,r;
        sort(nums.begin(), nums.end(),less<int>());
        int close,result = nums[0] + nums[1] + nums[2];
        for(int i=0;i<nums.size()-2;i++){
            l = i+1,r = nums.size()-1;
            while(l<r){
                close = nums[l] + nums[i] + nums[r];
                if(abs(close-target)<abs(result-target)){
                    result = close;
                }
                if(close>target){
                    r--;
                }else{
                    if(close<target){
                        l++;
                    }else{
                        return target;
                    }
                }
            }
        }
        return result;
    }
};
```
