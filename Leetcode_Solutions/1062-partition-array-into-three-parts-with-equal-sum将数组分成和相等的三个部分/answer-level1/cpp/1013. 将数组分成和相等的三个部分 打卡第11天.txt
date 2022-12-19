```c++
static const auto _ = []() //这段函数的主要作用就是提高输入输出的速度
{
    ios::sync_with_stdio(false); 
    //主要作用是提高c++ cin cout 的速度，原本的效率较低，涉及到要将输入输出存入缓存区。
    cin.tie(nullptr);
    // 这里的主要作用是将cin和cout解除绑定，因为std :: cin默认是与std :: cout绑定的，所以每次操作的时候（也就是调用”<<”或者”>>”）都要刷新（调用flush），这样增加了IO的负担，通过tie(nullptr)来解除std :: cin和std :: cout之间的绑定，来降低IO的负担使效率提升
    return nullptr;
}();
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
        int sum = 0, cnt = 0, cur = 0;
        for(auto i : A) sum += i;
        if(sum % 3 != 0) return false;
        for(auto i : A){
            cur += i;
            if(cur * 3 == sum) cnt++, cur = 0;
        }
        if(sum == 0 && cnt >= 3) return true; //特殊情况，sum = 0，并且能分成cur = 0的部分大于3个
        if(cnt != 3) return false;
        return true;
    }
};
```