### 解题思路
扫描线解法，将所有矩形按左下角坐标排序（先y,y相等则看x,从下到大)。这样就可以像俄罗斯方块一样一层一层，从左到右进行判断。
扫描线就是已落下的俄罗斯方块的上部边界，其存储形式参照了“天际线”那一题题目的输出方式，只储存水平线段左端点。

### 代码

```cpp
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        typedef pair<int,int> Node;
        sort(rectangles.begin(),rectangles.end(),
            [](const vector<int>& i1,const vector<int>& i2)->bool{
                return i1[1]<i2[1]||(!(i2[1]<i1[1])&&i1[0]<i2[0]);
            });

        set<Node> line;
        Node fst(rectangles.front()[0],rectangles.front()[1]);
        line.insert(fst);
        int maxX=fst.first;

        for(const auto& r:rectangles)
        {
            if(r[1]==fst.second)
            {
                if(r[2]>maxX)
                    maxX=r[2];
            }
            else
                break;
        }
        line.insert(Node(maxX,fst.second));

        for(const auto& c:rectangles)
        {
            Node bl(c[0],c[1]);
            auto iter=line.find(bl);
            if(iter!=line.end())
            {
                iter=line.erase(iter);
                auto iterPre=iter;
                if(iter==line.begin()||(iter!=line.begin())&&(*--iterPre).second!=c[3])
                {
                    iter=line.insert(Node(c[0],c[3])).first;
                    ++iter;
                }

                const auto& nextNode= *iter;
                if(nextNode.first<c[2])
                    return false;
                else if((nextNode.first==c[2]) && (nextNode.second==c[3]))
                    line.erase(iter);
                else if(nextNode.first>c[2])
                    line.insert(Node(c[2],c[1]));
                else;
            }
            else
                return false;

        }

        if(line.size()==2)
            return true;
        else
            return false;

    }

};
```