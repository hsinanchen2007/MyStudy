该题有一个显示提示，大致意思就是把nums[2i+1]的数字重复nums[2i]次，因此在求解时，通过遍历该数组的奇数位（对应2i），把对应的偶数位数字（对应2i+1）填充进新数组即可。
```
    vector<int> decompressRLElist(vector<int>& nums) {
        int len=nums.size()/2;
        vector<int> v;
        for(int i=0;i<len;++i){
            while(nums[i*2]--){
                v.push_back(nums[i*2+1]);
            }
        }
        return v;
    }
```
