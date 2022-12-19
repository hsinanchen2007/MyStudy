### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/2c8aaa764ec4b963bcd44ddfeb3327ebbe0c98b9f730305d9e1dd9aeeb953fee-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> answer;
        
            int count=n/2;
            while(count)
            {
                answer.push_back(count);
                answer.push_back(-count);
                count--;
            }
            
            if(n%2==1)  answer.push_back(0);
            return answer;

    }
};
```