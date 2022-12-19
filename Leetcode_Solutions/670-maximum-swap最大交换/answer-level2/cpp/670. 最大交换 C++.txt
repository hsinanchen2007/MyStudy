### 解题思路
1、使用了multimap

### 代码

```cpp
class Solution {
public:

    int maximumSwap(int num) {

        vector<int> v;
        while (num)
        {
            v.push_back(num % 10);
            num /= 10;
        }

        reverse(v.begin(), v.end());
        multimap<int, int> map;

        for(int i = 0; i < v.size(); ++i)
        {
            map.insert(make_pair(v.at(i), i));
        }

        //交换
        for (int i = 0; i < v.size(); ++i)
        {
            //从大到小
            for (auto iter = map.rbegin(); iter != map.rend(); ++iter)
            {
                //位数更低更且值更大 才交换
                if (iter->second > i && iter->first > v.at(i))
                {
                    swap(v.at(i), v.at(iter->second));
                    goto OUT;
                }
            }
        }
    OUT:
        for (int i = 0; i < v.size(); ++i)
        {
            num += v.at(i) * pow(10, v.size() - 1 - i);
        }

        return num;
    }
};
```