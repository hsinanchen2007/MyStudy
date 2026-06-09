### 解题思路
哈希。
注意提示：```0<=arr[i]<=10000```;

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> mid(10001);
        vector<int> res;
        for (int i = 0; i < arr.size(); i++)
            mid[arr[i]]++;//哈希构造
        int count = 0;
        for (int i = 0; i < mid.size(); i++)
        {
            if (count == k)break;//外循环跳出
            for (int j = 0; j < mid[i]; j++)//处理重复的情况 eg:   arr:[0,0,0,1,1,2,3,4],k=5;  res=[0,0,0,1,1].
            {
                res.push_back(i);
                count++;
                if (count == k)break;//内循环跳出
            }      
        }
        return res;
    }
};
```