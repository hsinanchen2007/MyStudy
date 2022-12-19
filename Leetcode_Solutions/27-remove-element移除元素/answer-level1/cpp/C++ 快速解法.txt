### 解题思路
原地删除的代码都有一个技巧 就是双指针 一个指向要写入的位置 另一个指向当前位置
在这个骨架上充填逻辑代码即可

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //新建快慢指针
        vector<int>::iterator slow,faster;
        slow = faster = nums.begin();

        //元素大小
        int len = 0;

        while(faster !=nums.end())
        {
            //判断是不是相等
            if(*faster == val)
                faster++;
            else
            {
                *slow = *faster;
                slow++;
                faster++;
                len++;
            }
        }

        nums.resize(len);
        return len;
    }
};
```