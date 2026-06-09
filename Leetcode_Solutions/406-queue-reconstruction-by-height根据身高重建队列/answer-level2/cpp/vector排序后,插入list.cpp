### 解题思路
执行用时 :24 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :14 MB, 在所有 C++ 提交中击败了29.20%的用户

按照升高升序排序,按照前面人数降序排序,按照规则,每次把数组最后一个插入到链表,完成.
规则就是新的item前面需要有几个大于他的人


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        if (people.empty()) return people;
        sort(people.begin(), people.end(),
             [](const vector<int> &o1, const vector<int> &o2) {
                 return o1[0] == o2[0] ? o1[1] > o2[1] : o1[0] < o2[0];
             }
        );
        list<vector<int>> output;
        auto list_begin = begin(output);
        for (auto p = end(people) - 1; p != begin(people)-1; --p) {
            auto temp = list_begin;
            for (int i = 0; i <= (*p)[1]; ++i) ++temp;
            output.insert(temp, *p);
        }
        for (auto &p:people){
            p=output.front();
            output.pop_front();
        }
        return people;
    }
};
```