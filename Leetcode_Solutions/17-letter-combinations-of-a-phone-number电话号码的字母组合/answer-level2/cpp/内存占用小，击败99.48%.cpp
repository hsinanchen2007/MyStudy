### 解题思路
- 树的深度优先递归，遍历输出所有的路径
- 采用 string 的引用，push pop 实现内存的节约

### 代码

```cpp
class Solution {
public:
    //树的递归，类似遍历输出所有的路径
    char digitChars[8][4] = {{'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'},
                             {'m','n','o'}, {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}};
    int charNum[8] = {3,3,3,3,3,4,3,4};

    vector<string> letterCombinations(string digits) {
        vector<string> results;
        if(digits.empty())
            return results;
        string strArr = "";
        dfs(digits, 0, strArr, results);
        return results;     
    }

    void dfs(const string& digits, int index, string& tmpArray, vector<string>& results)
    {
        if(index>=digits.size()){
            results.push_back(tmpArray);
            return;
        }
        int num = digits[index] - '0';
        if(num>=2 && num<=9){
            int k = charNum[num-2];
            for(int i=0; i<k; ++i)
            {
                tmpArray.push_back(digitChars[num-2][i]);
                dfs(digits, index+1, tmpArray, results);
                tmpArray.pop_back();
            }
        }
        return;
    }
};
```