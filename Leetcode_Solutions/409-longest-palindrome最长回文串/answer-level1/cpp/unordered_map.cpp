### 解题思路
最开始想到用一个vector数组去存放52字母出现的次数，但不知道为什么总是出现下面的错误，
AddressSanitizer: heap-buffer-overflow on address 0x611000002ce4 at pc 0x000000405b5e


后来看了一个解题，用unordered_map来保存。节省了空间。


auto的用法。


执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> harsh;
        for(auto x: s) harsh[x]++;
        int res = 0; 
        int isodd = 0;
        for(auto item: harsh)
        {
            if(item.second%2==0)
            {
                res += item.second;   //个数为偶数，加上个数。
            }
            else{
                isodd = 1;    //存在1个数可以放中间，
                res += item.second-1;  //个数为奇数，减一。
            }
        }
        return res+isodd;
    }
};
```