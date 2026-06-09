### 思路
C++ reference可以查到这个库函数next_permutation的用法
- 网址：<https://zh.cppreference.com/w/cpp/algorithm/next_permutation>
- 用库函数自带的全排列解决问题，高效完美
### 代码
```
    vector<vector<int>>ret;
        sort(nums.begin(),nums.end());
        do{
            ret.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return ret;
```
