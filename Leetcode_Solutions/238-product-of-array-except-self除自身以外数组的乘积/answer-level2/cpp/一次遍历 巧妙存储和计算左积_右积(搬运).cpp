本来开始想的是遍历一次求所有位置的左积，再遍历一次求所有位置的右积，再遍历一次求左积*右积
大概是O(3n)，代码如下:
96ms 23.23%
```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> v1(n,1),v2(n,1);
        
        for(int i=1;i<n;i++){//求左积
            v1[i]=v1[i-1]*nums[i-1];
        }
        
        for(int i=n-2;i>=0;i--){//求右积
            v2[i]=v2[i+1]*nums[i+1];
        }
        
        for(int i=0;i<n;i++){//左积*右积
            v1[i]*=v2[i];
        }
        
        return v1;
    }
};
```
然后看了大家的题解，发现一个o(n)的，[原作者在这里](https://leetcode-cn.com/problems/product-of-array-except-self/comments/59944)

思路大概是用双指针标记每个位置的左积(left)和右积(right)，这样在一次遍历中就可以计算出结果。
eg:```[1,2,3,4,5]```
2的左积在i=1时就算出，并且会更新此时的左积值。而其右积则在i=3时算出。
56ms 90.99%
```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        int left=1,right=1;     //left：从左边累乘，right：从右边累乘
        vector<int> res(n,1);
        
        for(int i=0;i<n;++i)    //最终每个元素其左右乘积进行相乘得出结果
        {
            res[i]*=left;       //乘以其左边的乘积
            left*=nums[i];
            
            res[n-1-i]*=right;  //乘以其右边的乘积
            right*=nums[n-1-i];
        }
        
        return res;
        
    }
};
```