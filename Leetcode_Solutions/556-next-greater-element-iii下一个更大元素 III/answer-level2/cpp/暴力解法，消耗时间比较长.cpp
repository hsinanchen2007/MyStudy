### 解题思路
此处撰写解题思路
1.先将输入的正整数n的每一位数存到数组里
2.对数组里的数据按照从大到小排序，这样做的目的是为了得到所有数据的全排列
3.全排列，选出最小的比n的数据
### 代码

```cpp
class Solution {
public:
    int nextGreaterElement(int n) {
            if (n == 2147483647)
            return -1;
            std::vector<int> temp;
            int orginData = n;
            while (0 != orginData)
            {
                temp.push_back(orginData % 10);
                orginData = orginData / 10;
            }
            sort(temp.begin(), temp.end());
            int data = -1;
            do 
            {
                uint32_t num = 0;
                for (int i = 0; i < temp.size(); i++)
                {
                    if (i == temp.size() - 1)
                    {
                        num = num + temp[i];
                    }
                    else
                    {
                        num = (num + temp[i]) * 10;
                    }
                }
            if (num > n)
            {
                if (num < data || data == -1)
                {
                    data = num;
                }
            }
            }while(next_permutation(temp.begin(), temp.end()));
      
            return data;
    }
};
```