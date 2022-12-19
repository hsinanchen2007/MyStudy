### 双指针
同样维护三个指针，第一个指针i从0开始一直到num.size（）-1，第二个指针left从i+1开始，第三个指针right从最后一个开始。
sum=nums[i]+nums[left]+nums[right]
(1) 当|target-sum|<|target-res|时，说明找到更加接近的了，将答案替换成当前的sum。
(2) 当target>sum，说明sum还不够大，因此left++
(3) 当target<sum，说明sum太大了，因此right--
(4) 当target==sum，说明差距为0，直接返回作为答案。
### 时间/空间复杂度
时间复杂度：O(n2)
空间复杂度: O(1)
### 代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<0) return 0;
        int left,right;
        sort(nums.begin(),nums.end());
        int res=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();++i){
            left=i+1;right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(abs(target-sum)<abs(target-res)){
                    res=sum;
                }
                
                if(sum>target) right--;
                else if(sum<target) left++;
                else return res;
            }
        }
        return res;
    }
};
```