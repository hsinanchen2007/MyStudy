### 解题思路
将最多的字符两两一块分配好, 然后将剩下的两种字符往块之间的坑中填放, 每一次填放的字符是可以根据坑的数量以及原有字符的数量计算出来的.
![IMG_20200405_231901__01.jpg](https://pic.leetcode-cn.com/7ba093bd4eb324d14399dd34173d831280e86a7647e748dfb0a2caa7ec0bff7d-IMG_20200405_231901__01.jpg)

### 代码

```cpp
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> data;
        data.push_back(make_pair(a, 'a'));
        data.push_back(make_pair(b, 'b'));
        data.push_back(make_pair(c, 'c'));
        sort(data.begin(), data.end(), [](const pair<int, char> & a, const pair<int, char> & b)->bool{
            return a.first > b.first;
        });
        string ans;
        int hole = (data[0].first + 1) / 2;
        int s1 = data[1].first;
        int s2 = s1 + data[2].first;
    
        for(int i = 0; i <= hole; ++i)
        {
            if(data[0].first > 1)
            {
                ans += string(2, data[0].second);
                data[0].first -= 2;
            } 
            else if(data[0].first == 1)
            {
                ans += data[0].second;
                data[0].first -= 1;
            }
            if(data[1].first == 0 && data[2].first == 0)
                break;
            int j = i;
            while(j < s2)
            {
                if(j < s1 && data[1].first > 0)
                {
                    ans += data[1].second;
                    data[1].first--;
                } 
                else if(j >= s1 && data[2].first > 0)
                {
                    ans += data[2].second;
                    data[2].first--;
                }
                j += hole;
            }
        }
        return ans;     
    }
};
```

![TIM截图20200405232238.png](https://pic.leetcode-cn.com/a10da4859c90da21350459e78c683ee48e414f458748af1de01c2e5100f351b1-TIM%E6%88%AA%E5%9B%BE20200405232238.png)
