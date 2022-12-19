### 解题思路

首先想到的是用一个数组来保存每个位置上的数字，再折半比较，本以为会快一点，结果慢的要死，
接着想到还是用整数反转的方法。翻转过来再比较果然快了很多。


### 代码

```cpp
class Solution {
public:
    // 执行用时 :84 ms, 在所有 C++ 提交中击败了5.73% 的用户
    // 内存消耗 :9.7 MB, 在所有 C++ 提交中击败了11.85%的用户
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return true;
        vector<int> temp;//用一个数组来保存这个数
        while(x){
            temp.push_back(x%10);
            x/=10;
        }
        for(int i = 0;i<temp.size()/2;++i){
            if(temp[i]!=temp[temp.size()-1-i]) return false;
        }
        return true;
    }

    // 执行用时 :16 ms, 在所有 C++ 提交中击败了70.21% 的用户
    // 内存消耗 :5.7 MB, 在所有 C++ 提交中击败了100.00%的用户
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return true;
        if(x%10==0) return false;//末尾有0绝对不可能是回文。
        int res = 0;
        int y = x;
        while(x){//反转数
            if(res>INT_MAX/10||(res==INT_MAX/10&&x>INT_MAX%10)) return false;
            res = res*10 + x%10;
            x/=10;
        }
        return res==y;
    }
};
```