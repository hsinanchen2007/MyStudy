1. 滑动窗口；
2. 滑动窗口的大小为所有1的个数windows，在滑动窗口内含有最多的1的个数one；
3. 结果answer = windows - max(one);
```
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        int ans = n;
        int one = 0;
        int count = 0;
        
        for(auto d : data){
            if(d == 1){
                count++;
            }
        }
        
        if(count <= 1){
            return 0;
        }
        
        for(int i = 0;i < n; ++i){
            if(data[i] == 1){
                one++;
            }
            if(i >= count-1){
                ans = min(ans,count-one);
                one = one - (data[i-count+1] == 1 ?1:0);
            }
        }
        
        return ans;
    }
};
```