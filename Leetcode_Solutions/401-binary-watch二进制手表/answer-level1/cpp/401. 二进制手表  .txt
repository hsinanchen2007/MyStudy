### 解题思路
此处撰写解题思路

### 代码
1.0
![401_1.jpg](https://pic.leetcode-cn.com/d92f980aaa0b057943ab650f95a09208842080600d780e06f685a75d20b9cd47-401_1.jpg)
```cpp
class Solution {
    int inline cntOne(int n)
    {
        int cnt = 0;
        while(n > 0)
        {
            cnt += n%2;
            n /= 2;
        }
        return cnt;
    }

public:
    vector<string> readBinaryWatch(int num) {
        vector<string> resStrVec;
        for(int i = 0; i < 12; ++i)
        {
            for(int j = 0; j < 60; ++j)
            {
                if(num == cntOne(i) + cntOne(j))
                {
                    string hours = to_string(i);
                    string minutes = to_string(j);
                    if(minutes.size() < 2)
                    {
                        minutes = "0"+minutes;
                    }
                    resStrVec.push_back(hours+":"+minutes);
                }
            }
        }
        return resStrVec;
    }
};

```
2.0
![401_2.jpg](https://pic.leetcode-cn.com/82bc928220bf48285fb62c044ace3fbdac7ec62590e2482364c339881e36d15a-401_2.jpg)

```cpp
//2.0
//改进cntOne方法
//双重for循环的剪枝
class Solution {
    int inline cntOne(int n)
    {
        int cnt = 0;
        while(n > 0)
        {
            cnt ++;
            n &= (n-1);
        }
        return cnt;
    }
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> resStrVec;
        for(int i = 0; i < 12; ++i)
        {
            if(cntOne(i) == num)
            {
                resStrVec.push_back(to_string(i)+":00");
            }
            else
            {
                for(int j = 0; j < 60; ++j)
                {
                    if(num == cntOne(i) + cntOne(j))
                    {
                        resStrVec.push_back(to_string(i)+":"+((j>=10)?to_string(j):("0"+to_string(j))));
                    }
                }
            }
        }
        return resStrVec;
    }
};









```