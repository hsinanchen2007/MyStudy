参考官方题解的C++代码
以及
关于竞赛大佬常用的 static auto x = []()用法解析
https://www.cnblogs.com/Kanna/p/12460494.html
```cpp
//看题解的时候发现好多大佬都有用这个，使用了以后运行速度快了特别多
static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int s= accumulate(A.begin(),A.end(),0);
        if(s % 3!=0)
            return false;
        int target = s / 3;
        int n=A.size(),i = 0,cur = 0;
        while(i<n){
            cur += A[i];
            if (cur == target) {
                break;
            }
            ++i;
        }
        if(cur!=target)
            return false;
        int j=i+1;
        while(j+1<n){
            cur += A[j];
            if (cur == target * 2) {
                return true;
            }
            ++j;
        }
        return false;
    }
};
```