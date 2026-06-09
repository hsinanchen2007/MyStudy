### 解题思路

每一层根据allowed可以推出下一层的字符串，然后可以继续向后推，自然而然想到使用递归的方式。递归函数的输入就是字符串。由于每一层可以得到多个下一层字符串，那么将所有的字符串都列举出来，然后依次进行递归，直到达到金字塔的顶层即可，说白了就是排列组合。
当前层每两个字符可以得到下一层的对应位置字符，使用一个hash表进行查找，
如果没有找到，则表示当前字符串构建失败，使用下一个字符串尝试构建。
![1.jpg](https://pic.leetcode-cn.com/132438b8f0784f43584e567a69097b5b9ac1627cb1e176efe1ae137a6ae079bc-1.jpg)


### 代码

```cpp
class Solution {
public:
    unordered_map<string, string> A;
    bool dfs(vector<string>& layer, string str, int k);
    bool sub(string bottom);
    bool pyramidTransition(string bottom, vector<string>& allowed);
};

bool Solution::dfs(vector<string>& layer, string str, int k)
{
    if(k == layer.size())return sub(str);                   //得到这一层中一个可能的字符串，判断其是否可以构建下一层
    bool out = false;
    for(int i = 0; i < layer[k].size(); ++i)
    {
        out = out || dfs(layer, str + layer[k][i], k + 1);
    }
    return out;
}

bool Solution::sub(string bottom)
{
    if(bottom.size() == 1)return true;                              //到达顶层,直接返回
    vector<string>layer;                                            //创建下一层，每一个位置可能有多个选择，用字符串表示
    for(int i = 1; i < bottom.size(); ++i)
    {
        if(A.find(bottom.substr(i - 1, 2)) == A.end())return false; //如果当前层的某两个字符串无法得到下一层的对应字符，则构建失败
        layer.push_back(A[bottom.substr(i - 1, 2)]);
    }
    return dfs(layer, "", 0);                                       //递归解决，类似排列组合，将下一层所有可能都拿出来判断是否可以构建
}

bool Solution::pyramidTransition(string bottom, vector<string>& allowed)
{
    for(int i = 0; i < allowed.size(); ++i)
    {
        A[allowed[i].substr(0,2)] += allowed[i][2];                 //构建哈希表, 键表示两个字符组成的字符串,
                                                                    //值表示这两个字符可以得到下一层的字符集合，也是字符串
    }
    return sub(bottom);
}
```