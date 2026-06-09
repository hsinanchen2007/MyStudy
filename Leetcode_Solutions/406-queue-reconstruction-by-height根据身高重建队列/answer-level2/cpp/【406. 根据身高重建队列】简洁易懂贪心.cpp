### 思路一：遍历
1. 将people按照身高由低到高排序
2. 按身高从低到高依次确定每个人最终位置，如果当前people的位置前有c个大于等于h的人，则从结果集开始遍历，如果当前位置为空或当前位置人身高大于等于h，则递减c，如果c小于0且当前位置为空，则找到people最终位置，停止查找。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {                
        if (people.empty()) return people;
        int size = people.size();
        vector<vector<int>> res(size);
        sort(people.begin(), people.end());
        for (int i = 0; i < size; ++i) {
            int c = people[i][1];            
            for (int j = 0; j < size; ++j) {
                if (res[j].empty() || res[j][0] >= people[i][0])  {
                    --c;
                }
                if (c < 0 && res[j].empty()) {
                   res[j] = people[i];
                   break;
                }
            }            
        }
        return res;
    }
};
```

### 思路二：排序+插入（最优解）
1. 挑选最高的一组人并且对他们排序成为一个子数组（S），因为没有人比他们高，所以他们的index就和他们的k值相同。
2. 对于第二组最高的人，将他们按照k值插入到子数组S中，依次类推

比如：
input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
subarray after step 1: [**[7,0], [7,1]**]
subarray after step 2: [[7,0], **[6,1]**, [7,1]]

### 代码
```c++
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {                
        if (people.empty()) return people;        
        vector<vector<int>> res;
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
             return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        for (auto a : people) {
            res.insert(res.begin() + a[1], a);
        }
        return res;
    }
};
```
