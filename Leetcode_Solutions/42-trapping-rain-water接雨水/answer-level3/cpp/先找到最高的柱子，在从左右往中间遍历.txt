和官方答案双指针的思路差不多，不过这里多遍历一次，找到最高的柱子，这样就不需要双指针。
这个更容易想到，当然，双指针速度应该更快。
```
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        auto p_max=max_element(height.begin(),height.end());
        int cnt=0;
        int t=0;//标志当前最大高度
        for(auto p=height.begin();p<p_max;++p){
            if(*p>t) t=*p;
            else cnt+=t-*p;
        }
        t=0;//标志当前最大高度
        for(auto p=height.end()-1;p>p_max;--p){
            if(*p>t) t=*p;
            else cnt+=t-*p;
        }
        return cnt;
    }
};
```
