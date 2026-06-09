### 解题思路
时间和空间效率如下：
![image.png](https://pic.leetcode-cn.com/3b6c36d33fd65022778d089429403f392f6f5378b661cbab80c3d6746da20f40-image.png)
## 思路：
假设输入为$a_1, a_2, ... ,a_n$，其中$a_i 属于（2, ... 9）$.
### 一般情况：

设$a_1, a_2, ... ,a_{n-1}$的解为$S_1, S_2, ... ,S_m$,其中$S_i为字符串$
设$a_n 对应的字母为x,y,z$,那么
设$a_1, a_2, ... ,a_{n}$的解为
$S_1 + x, S_2 + x, ... ,S_m + x$,
$S_1 + y, S_2 + y, ... ,S_m + y$,
$S_1 + z, S_2 + z, ... ,S_m + z$.
### 递归基为：
$$
当n == 1时，解为x,y,z
$$

### 代码

```cpp
class Solution {
public:
    map<char ,string> m;
    vector<string> helper(string digits){
        string tmp;
        if(digits == "")return {};
        string cur = m[digits.back()];
        digits.pop_back();

        vector<string> ret = helper(digits);
        vector<string> result;
        for(int i = 0; i < cur.size(); i++){
            if(ret.size() == 0){
                tmp.clear();
                tmp.push_back(cur[i]);
                result.push_back(tmp);
            }
            else{
                for(int j = 0; j < ret.size(); j++){
                
                    tmp = ret[j];
                    tmp.push_back(cur[i]);
                    result.push_back(tmp);
                }               
            }


        }
        return result;
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "")return {};
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        return helper(digits);
    }
};
```