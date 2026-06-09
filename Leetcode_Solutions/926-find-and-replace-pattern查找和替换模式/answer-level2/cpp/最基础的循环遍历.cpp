### 解题思路
每个words的元素，单独与pattern建立映射；
建立时每个字母都要检查是否满足一一映射，满足则添加到结果，不满足则跳过当前单词。

### 代码

```cpp
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<vector<char>> p;//记录words与pattern之间的映射
        auto bw = words.begin(), ew = words.end();//扫描words
        auto bw_ = bw->begin(), ew_ = bw->end();//扫描words每个元素
        auto bp = pattern.begin(), ep = pattern.end();//扫描pattern
        vector<string> rst;

        while(bw != ew)
        {
            bw_ = bw->begin(), ew_ = bw->end();
            bp = pattern.begin(), ep = pattern.end();
            p = {};
            if(ew_ - bw_ == ep - bp)
            {
                //建立映射
                while(bp != ep)
                {
                    auto b3 = p.begin(), e3 = p.end();
                    for(; b3 != e3; ++b3)
                    {
                        //检查当前字母的映射是否已存在
                        if((*b3)[0] == *bw_ || (*b3)[1] == *bp) break;
                    }
                    if(b3 == e3) p.push_back({*bw_,*bp});
                    //检查是否满足一一映射，不满足则跳过
                    else if((*b3)[1] != *bp && (*b3)[0] == *bw_ 
                            || (*b3)[0] != *bw_ && (*b3)[1] == *bp) break;
                    ++bw_;
                    ++bp;
                }
                //若满足一一映射，添加到结果
                if(bp == ep) rst.push_back(*bw);
            }
            ++bw;
        }
        return rst;
    }
};
```