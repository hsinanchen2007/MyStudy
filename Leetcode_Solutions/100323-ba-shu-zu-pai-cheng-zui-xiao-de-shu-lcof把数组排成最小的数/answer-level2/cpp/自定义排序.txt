### 解题思路
 
![leetcode 最小数.png](https://pic.leetcode-cn.com/df69d1b96414539e813dcd35d70aca21ea2563a892f0a8640a06dc0b877fabb2-leetcode%20%E6%9C%80%E5%B0%8F%E6%95%B0.png)
cop的https://blog.csdn.net/qq739887227/article/details/82895844 感谢！
### 代码

```cpp
class Solution {
public:
    string minNumber(vector<int>& nums) {
        
        // auto p = [](int a,int b){  //排序规则是按字符串排列
        //     string s1=to_string(a);
        //     string s2=to_string(b);
        //     return s1+s2<s2+s1;
        // };
        // sort(nums.begin(),nums.end(),p); //定义一个新的排序规则
        // string r;
        // for(auto i:nums){
        //     r+=to_string(i);
        // }
        // return r;


        auto cmp = [](int a,int b){
            long long len_a = 10;
            long long len_b = 10;
            while(a/len_a) len_a*=10;
            while(b/len_b) len_b*=10;
            long long r1=a*len_b+b;
            long long r2=b*len_a+a;
            return r1<r2;
        };
        sort(nums.begin(),nums.end(),cmp); //cmp中是<,所以这里是sheng序排列了，符合题意

        string r;  
        for (auto n : nums)  // 把排好序的数组转换为字符串,不是迭代器类型的！！！！
        //for(auto n=nums.begin();n!=nums.end();n++) 
        { // r = (n==nums.begin()) ? to_string(*n) : r + to_string(*n); 
           r+=to_string(n);
        }
        return r;
        
    }
};
```