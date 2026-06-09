### 解题思路
此处撰写解题思路
同向双指针解法，一个指针向前探索，直到该连续字符串的最后一个位置；
另一个指针，记录当前连续字符串的起始位置

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        int len = S.size();
        if (len == 0) {
            return S;
        }

        string res;
        int start = 0;
        int end = 0;
        int i = 0;

        while (i < len) {
            //cout << ";loop " << endl;
            string sstmp = S.substr(i, 1);  // 记录起始位置 
            start = i;
            while (start < len) {
                if (S[start] != S[start + 1]) {
                    break;
                }
                start++;
            }
            
            int cnt = start - i + 1;  // 获得相同字符串的个数
            i = start + 1;   // 更新下一个连续字符串的起始位置 

            // 将 int 和 string 进行转化
            stringstream tmpss;
            tmpss << cnt;
            string tmp0;
            tmpss >> tmp0;
            res += (sstmp + tmp0);  //  注意res 是累加  += 
            //cout << "tmp0 = " << tmp0 << "  i = " << i << endl;  

        }
        
        return res.size() < S.size() ? res : S;
    }
};
```