```cpp
class Solution {
public:
    typedef long long LL;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int index = 0, sz = arr.size();
        long long sum = accumulate(arr.begin(), arr.end(), 0);
        LL ans1 = getMaxSum(arr, 1);
        if(k == 1) return ans1;
        LL ans2 = getMaxSum(arr, 2);
        if(k==2) return ans2;
        LL ans3 = getMaxSum(arr, 3);
        if(k==3) return ans3;
        if(ans3 > ans2){
            ans3 += sum * (k-3);
        }
        return ans3 %(static_cast<LL>(1e9+7));  
    }

    // 连续k次的最大连续数组和
    LL getMaxSum(vector<int>& arr, int k){
        LL pre = 0,ans = 0;
        int index = 0, sz = arr.size();
        while(k>0){
            LL tmp = max(pre + static_cast<LL>(arr[index]), static_cast<LL>(arr[index]));
            ans = max(ans, tmp);
            pre = tmp;
            if(index == sz-1)
                k--;
            index = (index+1)%sz; 
        }
        return ans;
    }
};
```