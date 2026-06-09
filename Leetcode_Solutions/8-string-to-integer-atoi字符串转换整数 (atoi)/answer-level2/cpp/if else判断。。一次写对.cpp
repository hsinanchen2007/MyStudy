### 解题思路
分两种情况判断，判断为+/-/数字的时候做一次循环，后面就是改成数字，切记存储sum时不能用int，不然会越界（萌新想法），最后判断是否超出int范围即可

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        vector<char> h;
        int k = 0,z=0;
        for(int i = 0;i<str.size();i++)
        {
            if(str[i] == ' ') continue;
            if(str[i] == '-' || str[i] == '+')
            {
                if(str[i] == '-') k = 1;
                if(str[i] == '+') k = 2;
                h.push_back(str[i]);
                int j = i+1;
                if(j<str.size())
                {
                    for(int m = j;m<str.size();m++)
                    {
                        if(str[m] >='0' && str[m] <='9')
                        {
                            h.push_back(str[m]);
                        }
                        else break;
                    }
                    break;
                }

            }
            else if(str[i] >='0' && str[i] <='9')
            {
                k =0;
                for(int j =i;j<str.size();j++)
                {
                    if(str[j] >='0' && str[j] <='9')
                    {
                        h.push_back(str[j]);
                    }
                    else break;
                }
                break;
            }
            else return 0;
        }
        if(k>0) z = 1;
        else z =0;
        double sum = 0;
        for(int i = z;i<h.size();i++)
        {
            int x = h[i]-'0';
            sum = sum*10+x;
        }
        if(k ==1) sum = sum*(-1);
        if(sum>0 && sum>2147483647)
            sum=2147483647;
        if(sum<0 && sum<-2147483648)            
            sum=-2147483648;
        return sum;
    }
};
```