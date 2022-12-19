### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int Max_len=0;
        int len=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            vector<int>tem;  //临时存放的数组
            int j=i;
            int temp=1;
            int t;   //临时存储
            while(i!=nums[j]&&nums[j]!=-1)
            {
                temp++;
                t=nums[j];
                nums[j]=-1;   //此处已经被占用，以后如果找到这个地方，无须再往下查找
                j=t;
            }
            Max_len=max(Max_len,temp);
        }
        return Max_len;
    }
};
```