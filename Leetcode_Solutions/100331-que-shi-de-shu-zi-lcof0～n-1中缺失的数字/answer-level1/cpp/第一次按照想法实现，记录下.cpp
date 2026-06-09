### 解题思路
此处撰写解题思路
1.通过寻找字符串中不同的字符，然后查找出不同的位置，说明nums[i]与[0,n)之间有不同的数据，说明只要将nums[i]-1就是返回结果；
2.对于首项不为0，肯定返回0；
3.如果上述两项都满足，那么满足num[i]属于[0,n)，那肯定返回n
### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        string temp="";
        sort(nums.begin(),nums.end());
        if(nums[0]!=0){return 0;}
        
        for(int i=0;i<=nums[nums.size()-1];i++){
            temp+=to_string(i);
        }
        string res="";
        for(int i=0;i<nums.size();i++){
            res+=to_string(nums[i]);
            if(temp.find(res)==string::npos)
            {
                return nums[i]-1;
            }
        }
        return nums[nums.size()-1]+1;

    }
};
```