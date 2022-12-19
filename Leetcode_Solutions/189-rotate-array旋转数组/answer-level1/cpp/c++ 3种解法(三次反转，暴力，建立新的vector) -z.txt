
```
1.三次反转 (A'B')' = BA,‘ 为转置,对应就要进行三次反转

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int len=nums.size();
                                                            //reverse翻转的是[begin,end)区间
       reverse(nums.begin(), nums.end() - k%len);           //翻转A区间 
       reverse(nums.end()- k%len,nums.end());               //翻转B区间 
       reverse(nums.begin(),nums.end());                    //整体翻转
    }
};```

2.简单方法，复制一个新的数组对原数组进行赋值(使用了额外的空间，不符要求)
`
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> nums2(nums);
        int len=nums.size();

        for(int i=0;i<len;i++)
        {
            nums[(i+k)%len]=nums2[i];
        }
       
    }
};`


3.暴力方法，进行k次旋转(超出时间限制)


`class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        for(int i=1;i<k+1;i++)//旋转k次
        {
        int tmp;
        tmp=nums[len-1];
        for(int j=len-1;j>=1;j--)//每次向后移动一位，从倒数第二位逆向开始
        {
            nums[j]=nums[j-1];
        }
        nums[0]=tmp;
          
        }
       
    }
};
`


```