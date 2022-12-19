```
//执行用时 : 16 ms, 在所有 C++ 提交中击败了 64.93 % 的用户
//内存消耗 : 9.3 MB, 在所有 C++ 提交中击败了 79.22 % 的用户
class Solution
{
public:
    vector<int> pancakeSort(vector<int> &A)
    {
        vector<int> k;
        for (int i = A.size(); i >= 2; i--)
        {
            vector<int> temp(2);
            temp = operate(A, i);
            k.push_back(temp[0]);
            k.push_back(temp[1]);
            if (judge(A))
                break;
        }
        return k;
    }
    vector<int> operate(vector<int> &A, int k)
    {
        int max = A[0];
        int n = 0;
        vector<int> result;
        for (int i = 1; i < k; i++)
        {
            if (max < A[i])
            {
                int temp = max;
                max = A[i];
                A[i] = max;
                n = i;
            }
        }
        result.push_back(n + 1);
        result.push_back(k);
        reverse(A, n + 1);
        reverse(A, k);
        return result;
    }
    void reverse(vector<int> &A, int k)
    {
        for (int i = 0; i < k / 2; i++)
        {
            int temp = A[i];
            A[i] = A[k - i - 1];
            A[k - i - 1] = temp;
        }
    }
    bool judge(vector<int> &A)
    {
        int flag = 1;
        for (int i = 0; i < A.size() - 1; i++)
        {
            if (A[i] < A[i + 1])
                continue;
            else
            {
                flag = 0;
                break;
            }
        }
        return flag;
    }
};
```