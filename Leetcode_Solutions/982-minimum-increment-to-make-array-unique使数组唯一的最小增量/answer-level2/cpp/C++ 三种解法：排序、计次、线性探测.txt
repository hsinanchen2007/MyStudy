
### 代码

```cpp
class Solution {
public:
    //排序解法
    int sortMove(vector<int>& A)
    {
        int lastPlus = 0;
        int ans = 0;
        sort(A.begin(), A.end());
        for(int i = 1; i < A.size(); i++)
        {
            lastPlus += 1 - (A[i] - A[i-1]);
            if(lastPlus < 0) lastPlus = 0;
            ans += lastPlus;
        }
        return ans;
    }

    //次数记录解法
    int countsMove(vector<int>& A)
    {
        vector<int> counts(80000, 0);
        int ans = 0;
        int nums = 0;
        for(int a : A) counts[a]++;
        for(int i = 0; i < counts.size(); i++)
        {
            if(counts[i] > 1)
            {
                nums += counts[i] - 1;
                ans -= (counts[i] - 1) * i;
            }
            else if(counts[i] == 0 && nums > 0)
            {
                ans += i;
                nums--;
            }
        }
        return ans;
    }
    //线性探测解法
    int linearProbing(vector<int>& A)
    {
        vector<int> table(80000, -1);
        int ans = 0;
        for(int a: A)
        {
            int pos = findPos(a, table);
            ans += pos - a;
        }
        return ans;
    }

    int findPos(int a, vector<int>& table)
    {
        if(table[a] == -1)
        {
            table[a] = a;
            return a;
        }

        int pos = findPos(table[a]+1, table);
        table[a] = pos;
        return pos;
    }

    int minIncrementForUnique(vector<int>& A) {
        //排序解法
        // return sortMove(A);

        //次数记录解法
        // return countsMove(A);

        //线性探测解法
        return linearProbing(A);
    }
};
```