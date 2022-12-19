### 解题思路
此处撰写解题思路
先分享第一种最傻的方法，就是把n先变成二进制序列，废话不多，上代码。应该大多数人都用过。
### 代码
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int base=2;
        int cnt=0;
        vector<int> data;
        long long y=n;
        do{
            data.push_back(y%2);
            y=y/2;
        }while(y!=0);
        for(int i=0;i<data.size();i++)
        {
            if(data[i])
                cnt++;
        }
        return cnt;
    }
};
第二种就是位运算，由于这题是无符号的数，假如有符号那最高位就是符号位这么搞就不对了。
```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
       int cnt=0;
        while(n!=0)
        {
            cnt+=n&1;
            n=n>>1;
        }
        return cnt;
    }
};
```