### 解题思路
punch in the card

Again, I will give you code. 

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int table[130]={0};
        for(int i=0;i<(int)s.size();i++)
        {
            table[(int)s[i]]++;
        }
        int out=0;
        bool flag=false;
        for(int i=0;i<130;i++)
        {
            if(!flag)
            {
                if(table[i]>0)
                {
                    out+=table[i];
                    if(table[i]%2)
                        flag=true;
                }
            }
            else
            {
                out+=((table[i]>>1)<<1);
            }
        }
        return out;
    }


        
private:
};

```