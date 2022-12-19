### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {

        vector<vector<int>> sequence;
        queue<int> q;
        int sum = 0;
        vector<int> temp_sequence;
        for (int i=1; i<target/2+2; i++)
        {
            sum += i;
            q.push(i);
            
            while (sum > target)
            {
                sum -= q.front();
                q.pop();
            }   

            if (sum == target)
            {
                while (!q.empty())
                {
                    temp_sequence.push_back(q.front());
                    q.pop();
                }

                sequence.push_back(temp_sequence);
                for (int j=0; j<temp_sequence.size(); j++)
                    q.push(temp_sequence[j]);
                temp_sequence.clear();
            }     
        }

        return sequence;
    }
};
```