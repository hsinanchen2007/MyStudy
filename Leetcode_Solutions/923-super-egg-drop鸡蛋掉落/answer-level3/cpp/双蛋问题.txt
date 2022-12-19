### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int superEggDrop(int eggs, int floor)
    {
        int steps = 1;
        while(1) {
            // std::cout << "calc:" << eggs << "|" << steps << std::endl;
            if (getMaxFloor(eggs, steps) >= floor)
                return steps;
            steps++;
        }
    }
private:
    int getMaxFloor(int eggs, int steps)
    {
        if ( eggs == 1 ) {
            // std::cout << "egg:" << eggs << ",steps:" << steps << ",floor:" << steps <<std::endl;
            return steps;
        } else if ( steps == 1 ) {
            // std::cout << "egg:" << eggs << ",steps:" << steps << ",floor:" << 1 <<std::endl;
            return 1;
        }
        else {
            int ret = getMaxFloor(eggs -1, steps - 1) + 1 + getMaxFloor(eggs, steps - 1);
            // std::cout << "egg:" << eggs << ",steps:" << steps << ",floor:" << ret <<std::endl;
            return ret;
        }
    }
};
```