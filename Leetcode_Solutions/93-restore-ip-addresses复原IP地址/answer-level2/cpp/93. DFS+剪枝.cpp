### 解题思路
这种给出所有组合的题目一般都是DFS+剪枝去解决，难点在于剪枝条件
剪枝条件：
1. ip地址长度不能超过12个字符，不能小于4个字符
2. ip地址分成4段
3. ip地址每段最多3个字符，最少1个字符
4. 如果某一段为3个字符，那么数值一定小于256
5. 如果某个位置为0，那么这时，0不能与后面的字符合并作为某个段。只能与前面的字符合并或者单独作为某个段

### 代码

```cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> tmp;
        if(s.size() > 12 || s.size() < 4) return res;
        getCombination(res, tmp, s, 0);
        return res;
    }

    void getCombination(vector<string> &res, vector<string> &tmp, string &s, int idx){
        if(tmp.size() == 4 && idx == s.size()){
            string str = tmp[0] + '.' + tmp[1] + '.' + tmp[2] + '.' + tmp[3];;
            res.push_back(str);
            return;
        }else{
            int remain_str = s.size() - idx;
            int remain_addr_part = 4 - tmp.size();
            if(remain_addr_part > remain_str || remain_addr_part * 3 < remain_str) return;
            //cout << "idx: " << idx << " remain_str: " << remain_str << " remain_addr_part: " << remain_addr_part << endl; 
            for(int i = 0; i < 3; ++i){
                string new_str;
                if(s[idx] == '0'){
                    new_str += s[idx];
                    if(i > 0){
                        break;
                    }
                }else{
                    new_str = s.substr(idx, i+1);
                    //cout << "new_str: " << new_str << endl;
                    if(i == 2){
                        int val = getThreeCharVal(new_str);
                        //cout << val << endl;
                        if(val > 255) break;
                    }
                }
                tmp.push_back(new_str);
                getCombination(res, tmp, s, idx+i+1);
                tmp.pop_back();
            }
        }
    }

    int getThreeCharVal(string str){
        int res = 0;
        res += (str[0] - '0') * 100;
        res += (str[1] - '0') * 10;
        res += (str[2] - '0');
        return res;
    }
};
```

### 结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 83.49% 的用户 
内存消耗 : 6.7 MB , 在所有 C++ 提交中击败了 100.00% 的用户