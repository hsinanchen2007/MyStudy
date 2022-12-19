### 解题思路
直接看注释

### 代码

```cpp
/*暴力解法


*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {             
        if(0 == nums.size() || 0 >= k){//输入不合法时，直接返回数组
            vector<int> res_first;
            return res_first;
        }

        int size = nums.size();//输入数组的元素个数
        vector<int> res(size-k+1); //返回值，其大小初始化为：（nums.size()-k+1）   

        for(int i = k -1;i < size;i++){//从k-1开始遍历，直到最后一个元素。
            int max_value = nums[i-k+1];//当前窗口内的最大值。
            for(int j = i-k+1;j <= i;j++){//求窗口内的所有数据的最大值
                max_value = max(nums[j],max_value); 
            }
            res[i-k+1] = max_value;//保存最大值。
        }

        return res;
    }
};
```