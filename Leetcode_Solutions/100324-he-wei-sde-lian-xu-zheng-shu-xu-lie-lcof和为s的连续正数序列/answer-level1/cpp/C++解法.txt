### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {

        vector<vector<int>> sequence;
        
        for (int i=1; i<target/2+2; i++)
        {
            int temp_target = target;
            int j = i;
            vector<int> temp_sequence;

            while (temp_target>0)
            {
                temp_sequence.push_back(j);
                temp_target -= j;
                j++;
            }
            int sum = 0;
            for (int i=0; i<temp_sequence.size(); i++)
                sum += temp_sequence[i];
            if (sum == target)
                sequence.push_back(temp_sequence);        
        }

        return sequence;
    }
};
```