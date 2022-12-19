本题按照要求模拟即可

这里将a,b,c分别标记为0，1，2，从而方便代码编写

1. 使用$last$记录上一个使用的字符，初始$last$设置为-1，初始result字符串为空。
2. 每次将不是$last$的字符作为备选，选取数量较多的字符$\alpha$，如果$\alpha$的剩余个数为0，则返回result，然后与$last$字符的剩余数目做比较，如果$\alpha$的剩余数目大于$last$的剩余数目，则添加两个$\alpha$到末尾，否则添加一个$\alpha$到末尾。
3. 更新每个字符的剩余个数，更新last，回到第2步。

```cpp
class Solution {
public:
    char getChar[3] = {'a', 'b', 'c'};
    string longestDiverseString(int a, int b, int c) {
        vector<int> chars = {a, b, c};
        int last = -1;
        string res;
        while(1){
            vector<pair<int, int>> temp;
            for(int i=0; i<3; i++){
                if(i!=last)
                    temp.push_back({chars[i], i});
            }
            sort(temp.begin(), temp.end()); // 图省事。。。
            auto& cur = temp.back();
            if(cur.first==0) break;
            int take = min(cur.first, 2);
            if(last!=-1 && chars[last]>cur.first)
                take = 1;
            res += string(take, getChar[cur.second]);
            chars[cur.second] -= take;
            last = cur.second;
        }
        return res;
    }
};
```
