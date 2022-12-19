```
class Solution {
public:
    //思路：建一个hashmap，现将A和B相加的和，还有出现次数放到hashmap中，然后两层循环C和D
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> hash;
        int res=0;
        for(auto a:A)
            for(auto b:B)
            {
                hash[a+b]++;//这是特殊的构造方式，没有出现过默认初始值是0；
            }

        for(auto c:C)
            for(auto d:D)
            {
                res+=hash[-c-d];
            }
        return res;
        
    }
};
```
