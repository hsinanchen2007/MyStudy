### 解题思路
利用小顶堆保存所有元素 然后依次弹出k个元素即可
不清楚官方的解答为啥那么麻烦
### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>> MinStack;
        vector<int> vec;

        for(auto c :arr)
            MinStack.push(c);

        for(auto i = 0; i< k;i++)
        {
            vec.push_back(MinStack.top());
            MinStack.pop();
        }

        return vec;
    }
};
```