### 解题思路
先判断每个有效字母的个数（l和o需除2）
取最小的字母个数即为balloon的最大数量

### 代码

```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text)
    {
        int a_count=0; 
        int b_count=0;
        int l_count=0;
        int n_count=0; 
        int o_count=0; 
        for(int i=0;i<text.size();i++)
        {
            switch(text[i])
            {
                case 'a':
                    ++a_count;
                    break;
                case 'b':
                    ++b_count;
                    break;
                case 'l':
                    ++l_count;
                    break;
                case 'n':
                    ++n_count;
                    break;
                case 'o':
                    ++o_count;
                    break;
            }
        }
        l_count/=2;
        o_count/=2;
        int res=(a_count<b_count?a_count:b_count);
        res=res<l_count?res:l_count;
        res=res<n_count?res:n_count;
        res=res<o_count?res:o_count;
        return res;
    }
};
```