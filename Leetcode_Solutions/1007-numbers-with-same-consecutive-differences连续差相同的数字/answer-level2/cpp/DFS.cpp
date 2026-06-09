### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N == 1)
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        k = K;
        for(int i = 0 ; i <= 9 ; ++i)
        {
            DFS(N, 1, i);
        }
        return ans;
    }
    void DFS(int n, int cnt, int num)
    {
        if(cnt == n)
        {
            ans.push_back(num);
            return ;
        }
        if(cnt == 1 && num == 0)
            return ;
        if(k == 0)
        {
            int temp = num % 10;
            DFS(n, cnt + 1, num * 10 + temp);
            return ;
        }
        int num1 = num % 10 + k;
        int num2 = num % 10 - k;
        if(num1 <= 9)
            DFS(n, cnt + 1, num * 10 + num1);
        if(num2 >= 0)
            DFS(n, cnt + 1, num * 10 + num2);
    }
private:
    vector<int> ans;
    int k;
};
```