# 16 最接近的三个数字之和
>给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。


## 思路：
1. 最开始想到的是效仿15题的思路，先排序，然后对三个数中最小的一个数nums[i]遍历
2. 令 left = i+1；right = n-1；
3. 但是，在效仿的时候，被15题的思路带跑偏了。下面是几点不同！！
		
- 错误1：一开始对最小的数进行距离判断，但是不应该，因为很有可能加上其他数以后的距离更近！！
```
if(abs(nums[i]-target) >= abs(res-target)){
                // 当前最小的数，距离target的距离已经大于当前最接近的就略过
                continue;
 }
```

- 错误2：认为对于已经判断过的第二个数和第三个数，可以跳过，但是这样就把第二个数和第三个数一样的机会去掉了。[-20,-19,-19,-19,18,20],会把-20 -19 -19 的情况略过！！但是在15题中，我们是判断no.1+no.2+no.3 == 0，才跳过，除非[0,0,0,0]，一开始第二个数和第三个数就一样，我们在no.1不变的情况下，no.3缩小到和no.2一样，是不会也等于0的。
	
```
while(left<right && nums[left] == nums[left+1]){
                        left++;// 去掉重复的组合，节省时间
 }
 while(left<right && nums[right] == nums[right-1]){
                        right--;
 }
```

## 代码：
```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 19999;// 当前找到的最接近的和
        // res是三个数之和，找到使得abs(res-target)的res。
        int n = nums.size();

        if(n < 3){
            return 0;
        }

        // 可以借鉴第15题，先排序，然后对三个数中最小的一个数遍历
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            int left = i+1;
            int right = n-1;
            // 讨论过的最小的数，可以略过
            if(i!=0 && nums[i] == nums[i-1]){
                continue;
            }
            while(left < right){
                
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(sum-target) <  abs(res-target)){
                    res = sum;
                    // 找到了dis=0，直接返回
                    if(abs(res-target) == 0){
                        return res;
                    }
                }
                // 要把距离更变小
                if(sum > target){// 如果sum是大于target的，sum变小才能靠近target
                    right--;
                }else{
                    left++;
                }
            }  
        }
        return res;
    }
};
```