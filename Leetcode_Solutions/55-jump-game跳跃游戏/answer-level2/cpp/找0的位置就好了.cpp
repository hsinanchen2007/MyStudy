### 解题思路
执行用时：8ms， 内存消耗：7.6MB
如果序列中没有0的话，就算每次只跳一格也一定可以跳到最后，所以重要的是0的位置，找到零的位置之后，看是否可以找到可以跳过零这一格的数字，找不到就说明跳不过这一格，也就跳不过最后，找的到就继续执行前面的代码就可以啦

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)   return true;
        vector<int>::iterator it;
        it = nums.begin();
Repeat:        while(it != nums.end() - 1)
        {
            if (*it != 0)
            {
                ++it;
                continue;
            }
            vector<int>::iterator it1 = it;
            while (it1-- != nums.begin())
            {
                if (*it1 > it - it1)
                {
                    ++it;
                    goto Repeat;
                }
            }
            return false;
        }
        return true;
    }
};
```