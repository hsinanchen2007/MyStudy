### 解题思路
left[i]存放nums[i]的左侧的和
right[i]存放nums[i]的右侧的和
dp:用前一个数的左右的和得出下一个数左右的和
### 代码

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size=nums.size();
        if(size==0)
            return -1;
        int sum=0,left[size],right[size];
        for(int i=0;i<size;i++)
            sum+=nums[i];
        left[0]=0;               //left[0]代表nums[0]左边的和
        right[0]=sum-nums[0];    //right[0]代表nums[0]右边的和
        left[size-1]=sum-nums[size-1];
        right[size-1]=0;
        if(left[0]==right[0])
            return 0;
        for(int i=1;i<size-1;i++)      //前一个数的左右和得出下一个数的左右和，动规
        {
            left[i]=left[i-1]+nums[i-1];
            right[i]=right[i-1]-nums[i];
            if(left[i]==right[i])
                return i;
        }
        if(left[size-1]==right[size-1])
            return size-1;
        return -1;
    }
};
```