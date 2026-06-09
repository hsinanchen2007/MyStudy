没啥好说的，这个也没什么特别的地方，只是介绍一下还有这么个东西可以用。
```
void rotate(vector<int>& nums, int k) {
        if(nums.size()<2 || (k %= nums.size())==0) return;
        ::rotate(nums.begin(),nums.begin()+distance(nums.begin(),nums.end())-k,nums.end());
    }
```
