### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numberOfSteps (int num) {
        if(num==0)
            return 0;
        vector<int> res;
        while(num!=0)
        {
            res.push_back(num);
            if(num%2==1)
            {
                num=num-1;
            }
            else
            {
                num=num/2;
            }
        }
        return res.size();
    }
};
```