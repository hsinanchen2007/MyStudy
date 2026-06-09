1、相似的string在一个set内， 这样L会慢慢减少，减少的L进行下一轮。
2、用list因为其删除/增加的效率高。
3、 L.erase(j++)必须这样写，不然会出错。因为修改list会影响iterator。
![image.png](https://pic.leetcode-cn.com/c8a20af9a69a43aa8a011e036bcea177996cdbac21c7585c05cf451b9e87a67b-image.png)

```
class Solution {
private:
    bool _isValid(const string &x, const string &y) {
        int len = x.size();
        char diff = 0;

        for (int i = 0; i < len; ++i) {
            if (x[i] != y[i])
                diff++;
            if (diff > 2)
                return false;
        }
        return true;
    }

    int _oneSet(list<string> &L, const int &step) {
        int size = L.size();
        list<string> tmp;
        tmp.push_back(L.front());
        L.pop_front();

        for (auto i = tmp.begin(); i != tmp.end(); ++i) {
            for (auto j = L.begin(); j != L.end();) {
                if (_isValid(*i, *j)) {
                    tmp.push_back(*j);
                    L.erase(j++);
                } else {
                    j++;
                }
            }
        }

        if (L.empty()) {
            return step;
        } else {
            return _oneSet(L, step + 1);
        }
    } 
public:
    int numSimilarGroups(vector<string>& A) {
        list<string> L(A.begin(), A.end());
        return _oneSet(L, 1);
    }
};
```
