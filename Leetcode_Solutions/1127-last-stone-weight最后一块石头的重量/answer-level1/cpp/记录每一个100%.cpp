### 解题思路
![1.png](https://pic.leetcode-cn.com/f809673dc8708fec8f9eeeb9ba5ee51d4aada4452c683e2f1d84c572b156c991-1.png)

感觉思路还是挺简单，每次都把最大的两个拿出来判断，只是最后的结果有时候运行很快，有时候很慢，

### 代码

```cpp
class Solution 
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        while (stones.size()>=2)//里面至少有两个的时候才能正常循环  
        {
            make_heap(stones.begin(), stones.end(), less<int>());

            // get x
            pop_heap(stones.begin(), stones.end(), less<int>());
            int x = *(stones.end()-1);
            stones.pop_back();

            // get y
            pop_heap(stones.begin(), stones.end(), less<int>());
            int y = *(stones.end()-1);
            stones.pop_back();

            if(x != y)
            {
                int back = abs(y-x);
                stones.push_back(back);
                push_heap(stones.begin(), stones.end(), less<int>());
            }            
        }
        if(stones.size())//只有一个的时候，就直接输出他的重量
            return stones[0];     
        return 0;
        
    }
};
```