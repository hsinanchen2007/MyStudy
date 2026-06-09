核心思路非常简单：

- 先排身高更高的，这是要防止后排入人员影响先排入人员位置
- 每次排入新人员`[h,k]`时，已处于队列的人身高都`>=h`，所以新排入位置就是`people[k]`

有了这两个思路代码实现就非常简单了

1. 先将`people`按照**身高降序排序**，又由于每次插入的位置是`k`，所以**相同身高需要按`k`升序排序**，否则插入位置会越界
2. 由于后续需要频繁使用`insert()`操作，建议使用`list`作为中间容器
3. 循环地从头读取`people`，根据`people[i][1]`也就是`k`,插入`list`，注意`list`的迭代器不支持随机访问，需要使用`advance()`找到应插入位置
4. 将完成所有插入操作的`list`重建为`vector`返回

见代码

```C++
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 排序
        sort(people.begin(), people.end(),
                [](const vector<int>& lhs, const vector<int>& rhs)
                 {return lhs[0] == rhs[0] ? lhs[1] <= rhs[1] : lhs[0] > rhs[0];});
        int len = people.size();
        list<vector<int>> tmp;
        // 循环插入
        for(int i = 0; i < len; ++i){
            auto pos = tmp.begin();
            advance(pos, people[i][1]);
            tmp.insert(pos, people[i]);
        }
        // 重建vector返回
        return vector<vector<int>>(tmp.begin(), tmp.end());
    }
};
```

直接使用`vector`而不是`list`的话，我这边测试是80ms，使用`list`仅需要28ms。