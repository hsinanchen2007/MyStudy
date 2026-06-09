### 解题思路
由于值的范围在【0,100】，设立一个大小为101的value数组记录每个数出现的次数。
然后记录比i小的数，记录在数组a中。
最后遍历nums，在a中寻找数，最后返回answer。
![image.png](https://pic.leetcode-cn.com/2ab6174df7e1e0d4dee1e73d5498e8bd485f3b0977029e1c27666817d92f50ef-image.png)

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