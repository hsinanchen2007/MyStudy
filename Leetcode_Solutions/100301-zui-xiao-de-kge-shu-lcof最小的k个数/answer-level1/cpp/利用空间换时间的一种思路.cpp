### 解题思路
这里采用空间换时间的思想，也就是采用桶排序来对数组进行快速排序。
1、首先确认vector中最大的元素是多少，然后分配一个能够容纳所有元素的空间。
2、根据vector元素的值，在数组中记录下对应元素的计数
3、从头到位进行遍历，取出前K个元素即可（元素计数必须大于0，才表示这个元素是存在的）
详细代码如下：

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) 
    {
        int max = 0;
        for(int i = 0; i < arr.size(); ++i)
        {
            if(max < arr[i])
            {
                max = arr[i];
            }
        }

        int *tmp = new int[max + 1];
        for(int i = 0; i < (max + 1); ++i)
        {
            tmp[i] = 0;
        }

        for(int i = 0; i < arr.size(); ++i)
        {
            tmp[arr[i]] += 1;
        }

        vector<int> vct_tmp;
        for(int i = 0, j = 0; i < (max + 1) && j < k; ++i)
        {
            if(tmp[i] != 0)
            {
                int count = 0;
                if(j + tmp[i] >= k)
                {
                    count = k - j;
                }
                else
                {
                    count = tmp[i];
                }

                j += tmp[i];

                for(int index = 0; index < count; ++index)
                {
                    vct_tmp.push_back(i);
                }
            }
        }

        return vct_tmp;
    }
};
```