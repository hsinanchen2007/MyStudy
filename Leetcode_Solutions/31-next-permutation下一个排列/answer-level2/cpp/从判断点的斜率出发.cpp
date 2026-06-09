### 解题思路
主要分为三步，第一步是寻找斜率异常的点，第二步是在峰点后进行排序，第三步是根据峰点的序找点并插入

### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while((i>0)&&(nums[i]<=nums[i-1])){
            i --;
        }//此步骤为寻找峰点
        int j = i;
        while(j<=(i+nums.size()-1)/2){
            int tem = nums[j];
            nums[j]=nums[nums.size()+i-j-1];
            nums[nums.size()+i-j-1]=tem;
            j++;
        }//峰点往后进行排序
        if(i==0){
            return;
        }
        else{
            j=i;
            int con = nums[i-1];
            while(con>=nums[j]){
                j++;
            }
            nums[i-1]=nums[j];
            nums[j]=con;
            return;
        }//对低点进行替换
    }
};
```