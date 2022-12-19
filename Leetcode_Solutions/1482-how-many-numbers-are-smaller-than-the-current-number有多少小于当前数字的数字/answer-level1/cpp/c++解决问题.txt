### 解题思路
因为值的范围【0,100】，定义一个长度为101的数组来记录各个数出现的次数。
然后一次遍历nums，对于其中每一个值，统计比他小的数，并加入answer中。
最后返回answer。
![image.png](https://pic.leetcode-cn.com/506966695649b0e59826202498899cd65634a7e3c43bb2b964066d3ff6602c47-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int value[101]={0};
        vector<int> answer;
        for(int i=0;i<nums.size();i++)
        {
            value[nums[i]]++;
        }
        for(int i=0,sum=0;i<nums.size();i++)
        {
            sum=0;
            for(int j=0;j<nums[i];j++)
                sum+=value[j];
            answer.push_back(sum);
        }
        return answer;
    }
};
```