### 解题思路
![image.png](https://pic.leetcode-cn.com/7ece708f3d9bb5079870cf323ad83081ced785261218c5ae362e7a0ee8548c63-image.png)



### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = visit(s.begin(), s.end(), '(');
        int max_len2 = visit(s.rbegin(), s.rend(), ')');
        return std::max(max_len, max_len2);
    }

    template<typename ForwardIt>
    int visit(ForwardIt first, ForwardIt end, char left){
        int max_len = 0;
        int sub_len = 0;
        int left_count = 0, right_count = 0;
        for(; first!=end; first++)
        {
            char c = *first;
            if(c==left)
                left_count++;
            else
            {
                right_count++;
                if(left_count==right_count)
                {
                    sub_len += left_count<<1;
                    max_len = std::max(max_len, sub_len);
                    left_count = right_count = 0;
                }else if(left_count<right_count)
                {
                    left_count = right_count = 0;
                    sub_len = 0;
                }
            }
        }
        return max_len;
    }

};
```