
参考了评论里的去重+运用了排列树【直接用count==0的情况会超时】
![image.png](https://pic.leetcode-cn.com/003d883b0ac6dda56e2952ede6b4bc6167738665f13194073e82784d8c4e21e1-image.png)

```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        sort(nums.begin(),nums.end());
        get(output,0,nums,nums.size());
        return output;
    }
    
    void get(vector<vector<int>> &output, int t,vector<int> num, int n){
        if(t == n){
            output.push_back(num);
            return;
        }else{
         for(int i=t;i<n;i++){
            if(i!=t and num[t] == num[i]) continue;
            swap(num[t],num[i]);
            get(output,t+1,num,n);          
        }   
        }
    }
    
    void swap(int &a,int &b){
        int tmp = a ;
        a = b;
        b = tmp;
    }
    
};


```
