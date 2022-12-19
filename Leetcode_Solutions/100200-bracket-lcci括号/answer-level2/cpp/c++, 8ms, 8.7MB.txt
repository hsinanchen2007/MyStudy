### 解题思路
tmp 存放不完全的括号序列，当前字符串的左括号数量，右括号数量
ans 存放合法的括号序列



### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<tuple<string, int, int>> tmp = {make_tuple("",0,0)}; // 待完成括号序列
        vector<string> ans={};
        while(!tmp.empty()){ // 只要还有未成熟的序列
            tuple<string, int, int> t = tmp.back();
            tmp.pop_back();

            string str = get<0>(t);
            int left = get<1>(t);
            int right = get<2>(t);

            // try to append ')'
            if(left <= n && right < left){
                int tmp_right = right;
                tmp_right ++;
                string tmp_string = str + ")";

                if(tmp_right == n){ // 成熟
                    ans.push_back(tmp_string);
                }
                else{ // not ok
                    tmp.push_back(make_tuple(tmp_string, left, tmp_right));
                }
            }

            // try to append '('
            if(left != n){
                left++;
                tmp.push_back(make_tuple(str+"(",left,right));
            }




        }
        return ans;

    }
};
```