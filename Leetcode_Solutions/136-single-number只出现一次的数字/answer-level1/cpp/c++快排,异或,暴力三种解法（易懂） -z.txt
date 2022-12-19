136.single number 只出现一次的数字


1.快速排序解法
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i,cur;
        int len=nums.size();

        sort(nums.begin(),nums.end());//进行快速排序，得到例如1，1，3，3，2

        for(i=0;i<len;i=i+2)//每次后移两个位置
        {
            cur=nums[i];
            if(i==len-1)  //如果遍历到最后一个元素,说明该元素为single number
                return cur;
            if(cur!=nums[i+1])//如果当前元素不等于后一个元素即为single number
                return cur;
           
        }
        return -1;
    }
};
```
2.异或解法(所有数字进行异或，相同的数字符号位一样，所以异或为000，最终结果就只为single number的符号位)
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len=nums.size();
        int ans=nums[0];

       for(int i=0;i<len-1;i++)
           ans=ans^nums[i+1];//异或运算，相同的符号位结果为0，不同为1，最后留下来的数字就是single number
  
        return ans;
    }
};
```
3.暴力解法(两次循环，时间复杂度为n方，不符合线性时间条件)
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i,j,cur;
        int len=nums.size();
        for(i=0;i<len;i++)
        {
            cur=nums[i];
            for(j=0;j<len;j++)  //寻找数组后面是否存在相同数字
            {
            if(j==i)
                continue;
            if(cur==nums[j])
                break;
            }
            if(j==len)
                return cur;
        }
        return -1;
    }
};
```