挺好玩的一种方法，快排后辗转相减？
```
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum{};
        int flag{1};
        for(int i:nums){
            sum += i*flag;
            flag = -flag;
        }
        return sum;
    }
```
