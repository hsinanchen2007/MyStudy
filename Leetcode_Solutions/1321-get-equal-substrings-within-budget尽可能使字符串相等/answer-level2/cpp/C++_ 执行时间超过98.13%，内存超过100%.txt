该题实际上与第3题无重复字符的最长子串解题思路是一样的：利用快慢指针，采用滑窗的方式。
1. 计算costs数组
2. 分别使用一个变量记录当前窗口内的总代价(costTillNow)和当前最大长度(maxLength)。
2. 刚开始快慢指针指向起始位置。快指针不断向前移动，将当前代价加到costTillNow上
3. 如果costTillNow没有超过maxCost，则更新maxLength。否则从慢指针开始，逐个删除慢指针指向的cost，直到costTillNow <= maxCost为止
4. 当快指针到达costs数组末尾时，程序结束，返回记录的最大长度maxLength

代码如下所示：
```
    int equalSubstring(string s, string t, int maxCost) 
    {
        const auto length = s.length();
        
        std::vector<int> costs(length, 0);
        
        // Compute all costs
        std::transform(s.cbegin(),
                       s.cend(),
                       t.cbegin(),
                       costs.begin(),
                       [](const auto char1, const auto char2) noexcept
                       {
                           return std::abs(char1 - char2);
                       });
                     
        auto sumTillNow = 0;
        auto maxLength = 0;
        
        for (auto i = 0, j = 0; j < length; ++j)
        {
            sumTillNow += costs[j];
            
            // Current cost can be sumed up
            if (sumTillNow <= maxCost)
            {
                const auto count = j - i + 1;

                // Update the maximum length
                if (count > maxLength)
                {
                    maxLength = count;
                }
            }
            else // Current cost cannot be sumed up directly
            {
                // Remove old costs
                while (i <= j && sumTillNow > maxCost)
                {
                    sumTillNow -= costs[i++];
                }
            }
        }
        
        return maxLength;
    }
```
上面的代码执行时间超过98.13% C++用户，内存超过100% C++用户。
