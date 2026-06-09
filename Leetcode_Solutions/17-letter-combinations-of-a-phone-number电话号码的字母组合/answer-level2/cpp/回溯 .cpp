### 解题思路
//dfs递归前做选择,dfs递归后撤销选择 每调用dfs一次就深入一层
//做选择是保证从当前节点往下走到叶子节点，是纵向的
//撤销选择是保证回溯走回去时还原同一层的兄弟节点选择列表，是横向的

### 代码

```cpp
class Solution {
private:
        unordered_map<char, string> lettermap = {{'2', "abc"}, {'3', "def"}, 
                                            {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
                                            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

public:
    void dfs(int index, string & digits, string & str, vector<string>& res) { //要传引用
        //已经走到了最后一位+1，即当前如果定位到了最大索引的下一个，就是去取不到的情况，函数就可以返回了
        if (index == digits.size()) {
            //cout << "str: " << str << endl;
            res.push_back(str); //体会这一步很关键
            return;
        }

        int letter = digits[index]-'0';
        if (letter > 1 && letter <= 9){
            string digtStr = lettermap[digits[index]];
            for (int i = 0; i < digtStr.length(); i++) { //for循环是控制同一层兄弟节点的
                str.push_back(digtStr[i]); //做选择
                //cout << "str.push_back " << str << endl;
                dfs(index + 1, digits, str, res); //递归dfs，通过Index+1的递归往下一层走，将这一层的选择通过str带到下一层中，
                str.pop_back(); //撤销选择,选择列表str要还原
                //cout << "str.pop_back " << str << endl;
            }
        }
    }


    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0) return res;

        string str;
        dfs(0, digits, str, res);

        return res;
    }
};
```