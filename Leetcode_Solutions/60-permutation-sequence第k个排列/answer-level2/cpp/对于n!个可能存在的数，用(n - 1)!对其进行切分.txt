![image.png](https://pic.leetcode-cn.com/595fd4b68da18b51e62f6bbfc6d3bdd666cd53c58437b8d64b08a793d682ab9d-image.png)

和官方给出的解析思路是一样的
split 的取值是 (n - 1)! 表示第一位数字在剩下的n个数里面选中的位置是根据给定的k确定的，但是选1-9概率是一样的，n!可以通过(n- 1)!进行切分
```
class Solution
{
public:
    std::string getPermutation(int n, int k)
    {
        std::string res;
        int split = 1;
        for (int i = 1; i <= n - 1; i++)
            split = split * i;
        std::vector<char> charList;
        int realIndex = k - 1;
        for (int i = 1; i <= n; i++)
            charList.push_back('0' + i);
        for (int i = 0; i < n; i++)
        {
            int index = realIndex / split;
            res += charList[index];
            if (i == n - 1)
                continue;
            charList.erase(charList.begin() + index);
            realIndex = realIndex % split;
            split = split / (n - i - 1);
        }
        return res;
    }
};
```