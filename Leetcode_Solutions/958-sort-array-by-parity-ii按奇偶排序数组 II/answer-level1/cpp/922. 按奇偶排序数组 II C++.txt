### 解题思路
只需处理好奇数 或 偶数 其中一组就行 另一组也就确定了

### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {

        int odd = 1; //奇数索引

        for (int i = 0; i < A.size(); i += 2) //i为偶数索引
        {
            if (A.at(i) % 2 != 0) //偶数索引 值为奇数
            {
                //找到奇数索引上第一个偶数
                while (A.at(odd) % 2 != 0)
                {
                    odd += 2;
                }

                swap(A.at(odd), A.at(i)); //交换 奇数索引上的偶数 与 偶数索引上的奇数
            }
        }

        return A;
    }
};
```