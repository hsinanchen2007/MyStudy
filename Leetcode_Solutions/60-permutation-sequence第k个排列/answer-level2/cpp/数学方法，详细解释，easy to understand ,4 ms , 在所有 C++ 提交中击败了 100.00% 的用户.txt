---
title: 169第k个排列
layout: post
categories: 回溯
excerpt: 
Tags: leetcode
---

给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。

**示例 1:**

```
输入: n = 3, k = 3
输出: "213"
输入: n = 4, k = 9
输出: "2314"
```

```c++
//方法1，列出全排列，转换为字符串，会超时
class Solution {
public:
    string getPermutation(int n, int k) {
        string result(n,0);
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        vector<vector<int>> tmp;
        vector<int> sub;
        helper(nums,tmp,sub);
        k--;
        for(int i=0;i<n;i++){
            result[i]=tmp[k][i]+'0';
        }
        return result;
    }
private:
    void helper(vector<int>& nums, vector<vector<int>>& tmp, vector<int>& sub){
        if(sub.size()==nums.size()){
            tmp.push_back(sub);
        }else{
            for(int i=0;i<nums.size();i++){
                if(find(sub.begin(),sub.end(),nums[i])==sub.end()){
                    sub.push_back(nums[i]);
                    helper(nums,tmp,sub);
                    sub.pop_back();
                }
            }
        }
    }
};

//方法2，利用数学方法
//https://www.youtube.com/watch?v=xdvPD1IiyUM
//https://www.youtube.com/watch?v=fe_DMBoe18o
class Solution {
public:
    string getPermutation(int n, int k) {
        string res(n,0);
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        vector<int> fract(n,1);
        for(int i=1;i<n;i++){
            fract[i]=fract[i-1]*i;
        }
        k--;
        for(int i=0;i<n;i++){
            int index = k/fract[n-1-i];
            res[i]=nums[index]+'0';
            k = k%fract[n-1-i];
            nums.erase(nums.begin()+index);
        }
        return res;
    }
};
//以例子分析：n=4,k=14
//nums=[1,2,3,4]
//把全排列划分为4组
////f[0]=1,f[i]=f[i-1]*i,1<=i<=n-1
//所有的排列按顺序为：
//index=0, 1+[2,3,4]，6个
//index=1, 2+[1,3,4],6个
//index=2, 3+[1,2,4],6个
//index=3, 4+[1,2,3],6个
//k=14,所以答案的最高位应该在index=2的那一部分，即最高位为3
//(k-1)/6=13/6=2,我们可以通过这个公式计算每一位
//result[0] = nums[k/f(n-1-i)]=nums[13/6]=nums[2]=3
//计算完之后，更新k，也就是13%6=1，k=k%f(n-1-i)=13%6=1
//我们应该从数组中删除已经添加进去的数字
//nums[1,2,4]
//index=0,1+[2,4],2个
//index=1,2+[1,4]，2个
//index=2,4+[1,2],2个
//result[1] = nums[k/f(n-1-i)]=nums[1/2]=nums[0]=1
//更新k，也就是1%2=1，k=k%f(n-1-i)=1%2=1
//nums[2,4]
//index=0,2+[4],1个
//index=1,4+[2]，1个
//result[2] = nums[k/f(n-1-i)]=nums[1/1]=nums[1]=4
//更新k，也就是1%1=0，k=k%f(n-1-i)=1%1=0
//nums[2]
//index=0,2,1个
//result[3] = nums[k/f(n-1-i)]=nums[0/1]=nums[0]=2
//result=[3,1,4,2]

```

