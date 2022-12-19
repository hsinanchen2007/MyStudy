### 解题思路
1.可以自己先构造几个关键测试用例来测试一下自己的代码：（1）空数组（2）1个元素、2个元素、3个元素、4个元素
2.不需要计算右侧和，右侧和可以用总数和与左侧和做运算得到。

### 代码

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans=-1;
        if(nums.size()==0)return -1;
        int leftSum=0,all_sum=0;//右侧和用整体和减去左侧和和中心元素
        for(int i=nums.size()-1;i>=0;i--){
            all_sum+=nums[i];
        }//返回除第一个元素外所有元素的和作为初始的rightSum

        for(int i=0;i<=nums.size()-1;i++){//这道题的关键是，需要遍历每一个元素。
            //从第一个元素开始，将它作为中心元素
            if(leftSum==(all_sum-leftSum-nums[i])){
                ans=i;
                break;//有多个答案时，遇到第一个满足条件的就跳出
            }
            leftSum+=nums[i];
        }        
        return ans;
    }
};
```