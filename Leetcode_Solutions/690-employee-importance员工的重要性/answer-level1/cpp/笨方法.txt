弄个栈，或者队列或者随便什么东西都行，把id放进去，然后在employee里搜索id一样的，res加上他的importance，然后将他的subordinates里的也就是他的手下全部放到栈里面，再去找，直到无手下为止。

```
class Solution {
public:
    int getImportance(vector<Employee*> e, int id) {
        int res = 0;
        stack<int> tmp;
        tmp.push(id);
        while (!tmp.empty()) {
            id = tmp.top();
            tmp.pop();
            for (auto i : e) {
                if (i->id == id) {
                    res += i->importance;
                    for (int j : i->subordinates) tmp.push(j);
                    break;
                }
            }
        }
        return res;
    }
};
```
