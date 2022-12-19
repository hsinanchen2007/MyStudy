将已经打开的灯的位置插入到堆中
当堆顶元素等于已经打开的灯的数量则所有灯都是蓝色的
```
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        set<int, greater<int>> heap;
        int count = 0;
        int answer = 0;
        for (int pos : light) {
            ++count;
            heap.insert(pos);
            if (count == *(heap.begin())) {
                ++answer;
            }
        }
        return answer;
    }
};
```