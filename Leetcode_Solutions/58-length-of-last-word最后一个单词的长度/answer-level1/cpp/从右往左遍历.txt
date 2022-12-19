### 解题思路
从右往左先排除空格，然后数字符串长度即可

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        //cout << " ok " << endl;
        int r = findWordRightIdx(s);
        //cout << " " << endl;
        int res = 0;
        while(r >= 0 && s[r] != ' '){
            res++; --r;
        }
        return res;
    }

    int findWordRightIdx(string &s){
        int r = s.size() - 1;
        while(r >= 0 && s[r] == ' '){
            --r;
        }
        return r;
    }
};
```

### 结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 74.43% 的用户 
内存消耗 : 6.5 MB , 在所有 C++ 提交中击败了 100.00% 的用户