前排的大部分楼主都是利用格雷编码的性质，动态规划求解。如果没学过格雷编码的同学可能很难理解。
其实这道题也可以看成是图的搜索，利用深度优先搜索和回溯可以求解。用一个n维的数组存储当前数字的每一位，分别改变每一位，递归地搜索，最终可以找到一个可行解。
```
class Solution {
public:
    vector<int> list;
    vector<int> grayCode(int n) {
        if(n < 1)
        {
            list.push_back(0);
            return list;
        }
        vector<int> res;
        vector<int> bits(n, 0);
        vector<bool> marked(pow(2, n), false);
        dfs(n, bits, marked, res);
        return res;

    }

    bool dfs(int n, vector<int>& bits, vector<bool>& marked, vector<int>& res)
    {
        int number = bitToNum(bits);
        if (marked[number])
            return false;
        res.push_back(number);
        marked[number] = true;
        if (res.size() == pow(2, n))
        {
            return true;
        }

        for (int i = 0; i < n; i++)
        {
            int tmp = bits[i];
            bits[i] = (bits[i] + 1) & 0x1; //循环分别修改每一位
            if (dfs(n, bits, marked, res))
                return true; //如果找到解了就不必再继续搜索了，直接返回
            bits[i] = tmp;//记得改回来
        }
        res.pop_back();
        marked[number] = false; //回溯恢复原来的状态
        return false;
    }

    int bitToNum(vector<int> bits)
    {
        int res = 0;
        for (int bit: bits)
        {
            res = res * 2 + bit;
        }
        return res;
    }
};
```
