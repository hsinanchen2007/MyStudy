利用 bs 表示当前串后面剩余项的数目，可用其判断当前是否为之前字符串的剩余项。
当是之前剩余的字串时，需要满足前两位为 10。
否则判断该新串是否满足规则。
当第一位为0时即可判断下一个，前两位为10时不满足返回false，当bs > 3也就是说后面字串数目大于3时也不满足规则。
```
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int bs = 0;
        for(int i = 0; i < data.size(); ++i)
        {
            unsigned int dd = data[i];
            if(bs == 0)
            {
                if(dd < 128)continue;
                if((dd >> 6) == 2)return false;
                while(bs <= 3 && ((dd >> (6 - bs)) & 1))++bs;
                if(bs > 3)return false;
            }
            else
            {
                --bs;
                if((dd >> 6) != 2)return false;
            }
            // printf("%d\n",bs);
        }
        return bs==0;
    }
};
```
