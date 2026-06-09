### 解题思路
看注释即可，简单易懂

### 代码

```cpp
class Solution
{
public:
    vector<int> pancakeSort(vector<int> &A)
    {
        vector<int> V;
        int temp = 0;//每一次循环最大的元素一定在正确位置，所以使用temp来缩短遍历长度
        for (int j = 0; j < A.size(); j++)
        {
            int max = -1, index = 0;
            for (int i = 0; i < A.size() - temp; i++)//寻找剩余元素中的最大值，返回其下标
            {
                if (max < A[i])
                {
                    max = A[i];
                    index = i;
                }
            }
            if (index == 0)//如果最大值恰好在第一个元素位置，那么直接进行翻转A.size() - temp长度将其转到剩余元素的最大位置
            {
                V.push_back(A.size() - temp);
                reverseK(A, A.size() - temp);
            }
            else
            {
                V.push_back(index + 1);//先将其翻转到第一个元素位置
                reverseK(A, index + 1);
                V.push_back(A.size() - temp);//再将第一个元素位置翻转到剩余元素最大值位置
                reverseK(A, A.size() - temp);
            }
            temp++;
        }
        return V;
    }

private:
    void reverseK(vector<int> &V, int k) //翻转vector的前k个元素
    {
        if (k > V.size())
        {
            return;
        }
        reverse(V.begin(), V.begin() + k);
    }
};
```
给自己的博客打波广告~欢迎赏光[https://mrsuncodes.github.io/](https://mrsuncodes.github.io/)