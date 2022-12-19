/*大顶堆保存当前剩余元素中的最大值*/
```
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < arr.size(); ++i) {
            q.push(make_pair(arr[i], i));
        }

        for (int i = 0; i < arr.size(); ++i) {
            pair<int, int> curMaxNode = q.top();
            if (curMaxNode.second > i) {
                arr[i] = curMaxNode.first;
            } else if (curMaxNode.second <= i) {
                while (q.top().second <= i && !q.empty()) {
                    q.pop();//把已经处于i及左边的元素都弹出去
                }
                arr[i] = q.top().first;
            }
        }

        arr[arr.size() - 1] = -1;//最后一个特殊处理

        return arr;
    }
};
```
