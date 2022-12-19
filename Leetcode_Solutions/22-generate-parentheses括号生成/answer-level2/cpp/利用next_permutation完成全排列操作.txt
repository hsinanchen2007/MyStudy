### 解题思路
利用next_permutation完成全排列操作，对每一个字符进行判断是否符合条件，只有左括号数目大于等于右括号数目的时候满足条件

### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string ori(n, '(');
        ori = ori.append(n, ')');
        res.push_back(ori);
        while (next_permutation(ori.begin(), ori.end())) {
            int sum = 0;
            for(auto scan = ori.begin(); scan != ori.end(); ++scan) {
                if(*scan == '(') sum++;
                else sum--;
                if(sum < 0) break;
            }
            if(sum == 0) res.push_back(ori);
        }
        return res;
    }
};
```