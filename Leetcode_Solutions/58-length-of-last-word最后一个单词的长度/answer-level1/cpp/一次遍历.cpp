从头到尾遍历，过程中计算每个单词的长度，preSum保存上一个单词长度，sum保存下一个可能存在的单词长度

```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int sum = 0;
        int preSum = 0;
        for(auto ptr = s.begin(); ptr != s.end(); ptr++)
        {
            if(*ptr != ' ')
                sum++;
            else
            {
                if(sum != 0)
                    preSum = sum;
                sum = 0;
            }
        }
        return (sum == 0? preSum : sum);
    }
};
```
