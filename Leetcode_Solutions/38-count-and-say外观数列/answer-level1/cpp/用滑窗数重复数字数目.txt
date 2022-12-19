### 解题思路
这个就是硬着遍历，用滑窗去数重复数字的数目，然后转为string

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string pre = "1", cur = "1";
        if(n <= 0) return "";
        if(n == 1) return pre;
        while(n > 0){
            //cout << pre << endl;
            pre = cur;
            cur = func(pre);
            --n;
        }
        return pre;
    }

    string func(string &pre){
        int win_r = 0, len = pre.size(), num = 0;
        char target = pre[0]; string cur = "";
        while(win_r < len){
            if(pre[win_r] == target){
                ++win_r;
                ++num;
            }else{
                cur += to_string(num);
                cur += target;
                target = pre[win_r];
                num = 0;
            }
        }
        if(num > 0){
            cur += to_string(num);
            cur += target;
        }
        return cur;
    }
};
```

###结果
执行用时 : 12 ms , 在所有 C++ 提交中击败了 24.29% 的用户 
内存消耗 : 6.3 MB , 在所有 C++ 提交中击败了 100.00% 的用户