### 解题思路
[2, 3, 1, 0, 2, 5, 3]
nums[0]=2
nums[0] !=nums[2],交换num[0]和nums[2]
[1, 3, 2, 0, 2, 5, 3]
nums[0]=1
nums[0] !=nums[1],交换nums[0]和nums[1]
[3, 1, 2, 0, 2, 5, 3]
nums[0]=3
nums[0] !=nums[3],交换nums[0]和nums[3]
[0, 1, 2, 3, 2, 5, 3]
nums[0]=0   i++
......
nums[3]=3   i++
nums[4]=2   而nums[4]==nums[2],  return 2
### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int>num=nums;  //如果直接用nums也行，不过下面交换数组中的值的时候会影响到传入的数组
        int n=num.size();
        for(int i=0;i<n;i++)
        {   if(num[i]==i)     // 如果当前的元素放在对的位置，i++
            continue;
            if(num[i]==num[num[i]])//num[i]的正确已经被它的相同的值占领了，说明num[i]重复   
            return num[i];     
            int temp=num[i];   //把num[i]放在正确的位置
            num[i]=num[temp];
            num[temp]=temp;
            i--;   //保持当前i不变
        }
        return -1;
    }
};
```