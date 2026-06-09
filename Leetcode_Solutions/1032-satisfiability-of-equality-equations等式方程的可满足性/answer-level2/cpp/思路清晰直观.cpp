### 解题思路
相等的和不相等的分开处理，相等时用BFS查找相等的赋值成一样的值，不相等的用来判决。

### 代码

```cpp
class Solution {
private:
    const int MAX_ENGLISH_MEMBERS = 26;
public:
    bool equationsPossible(vector<string>& equations) {
        int length = equations.size();
        if (length == 0) {
            return true;
        }
        vector<string> notEquations;
        vector<bool> status(MAX_ENGLISH_MEMBERS, false);
        vector<int> keys(MAX_ENGLISH_MEMBERS, 0);
        queue<int> nodeBag;
        int val = 1;
        for (int i = 0; i < length; i++) {
            string temp = equations[i];
            if (temp[1] == '=') {
                int position1 = temp[0] - 'a';
                int position2 = temp[3] - 'a';
                if (status[position1] == false) {
                    nodeBag.push(position1);
                }
                if (status[position2] == false) {
                    nodeBag.push(position2);
                }
                // BFS查找将相等的字母赋值成一样的值。
                while (!nodeBag.empty()) {
                    int index = nodeBag.front();
                    nodeBag.pop();
                    status[index] = true;
                    keys[index] = val;
                    for (int j = 0; j < length; j++) {
                        if (equations[j][1] == '!') {
                            continue;
                        }
                        int positionidx1 = equations[j][0] - 'a';
                        int positionidx2 = equations[j][3] - 'a';
                        if (positionidx1 == index && positionidx2 != index && status[positionidx2] == false) {
                            nodeBag.push(positionidx2);
                        }
                        if (positionidx2 == index && positionidx1 != index && status[positionidx1] == false) {
                            nodeBag.push(positionidx1);
                        }
                    }
                }

            } else {
                // 拦截"a!=a"这种情况
                if (temp[0] == temp[3]) {
                    return false;
                }
                // 不相等的情况缓存下来作为判断的标准
                notEquations.push_back(temp);
            }
            val++;
        }
        // 遍历不相等的情况进行检查
        for (int j = 0; j < notEquations.size(); j++) {
            string tempNot = notEquations[j];
            int left = tempNot[0] - 'a';
            int right = tempNot[3] - 'a';
            if (status[left] && status[right]) {
                // 相等则直接返回false
                if (keys[left] == keys[right]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```