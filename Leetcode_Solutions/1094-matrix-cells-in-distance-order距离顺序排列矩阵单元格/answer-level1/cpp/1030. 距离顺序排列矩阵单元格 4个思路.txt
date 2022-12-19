法1：重定义compare方法调用sort，时间感人
法2：lamda表达式，法1的变种，相较于compare，可以使用context的参数（r0, c0），更加方便
法3：multimap distance作key，坐标作value遍历输出
法4：曼哈顿距离相同者在同一个正方形/等高线上，用for循环结束战斗

//后3个方法来自与其他道友的题解

```cpp
class Solution {
public:
    static bool compare(vector<int> vec1, vector<int> vec2)
    {
        return vec1[2] < vec2[2];
    }
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> resVec;
        for(int r = 0; r < R; ++r)
        {
            for(int c = 0; c < C; ++c)
            {
                resVec.push_back(vector<int>{r,c,abs(r-r0)+abs(c-c0)});
            }
        }
        sort(resVec.begin(), resVec.end(), compare);
        for(vector<vector<int>>::iterator ite = resVec.begin(); ite != resVec.end(); ite++)
        {
            (*ite).pop_back();
        }
        return resVec;
    }
};



```


