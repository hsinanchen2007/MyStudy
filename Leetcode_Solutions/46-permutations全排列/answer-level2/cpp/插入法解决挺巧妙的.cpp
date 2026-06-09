### 解题思路
这道题用回溯是第一眼就感觉应该用的方法算是通解，看了下题解区，发现这种插入法，自己写了下，算是特解。
每次插入一个元素在不同的位置，当所有元素插入完，所形成的排列就出来了。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>{nums[0]});
        for(int i=1;i<nums.size();i++){ //对应元素
            int n = res[0].size();// 固定m,n两个大小，防止陷入死循环
            int m = res.size();
            for(int j=0;j<m;j++){  //对应结果集里的数组
                for(int x=0;x<n+1;x++){
                    if(x==n){
                        res[j].push_back(nums[i]);
                    }
                    else{
                        vector<int> temp = res[j];
                        temp.insert(temp.begin()+x, nums[i]);
                        res.push_back(temp);
                    }
                }
            }
        }
        return res;
    }
    // void printres(vector<vector<int>> res){
    //     for(vector<int> i:res){
    //         for(int j=0;j<i.size();j++){
    //             cout<<i[j];
    //         }
    //         cout<<',';
    //     }
    //     cout<<endl;
    // }
};
```