### 解题思路
- 设置slow与fast双指针
- slow：指向当前char
- fast: 用于统计slow字符1个数
### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        int len = S.length();
        int slow = 0;
        int fast = 0;
        int tmp=0;
        string res;
        while(fast!=len+1){
            if(fast==slow) res.push_back(S[slow]);
            if(S[fast]==S[slow]){
                tmp++;
                fast++;
            }else{
                res += to_string(tmp);
                slow=fast;
                tmp=0;
            }
        }
        
        return res.length()<=len?res:S;
    }
};
```
### 结果
```
执行用时 :12 ms, 在所有 C++ 提交中击败了86.18%的用户
内存消耗 :9 MB, 在所有 C++ 提交中击败了100.00%的用户
```