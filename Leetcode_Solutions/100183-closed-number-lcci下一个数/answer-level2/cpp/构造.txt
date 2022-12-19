（以下01串左边为高位）
先来构造答案中比num略大的数a：
    从低位到高位找到第一个片段满足01...10...0，即第一个满足低位有1的0，把0变1，然后把后面那些1全部移到低位。例如：110011110011，我们把其变为110100011111
然后构造答案中比num略小的数b：
    还是从低位到高位找到第一个片段满足10...01..1,即第一个满足低位有0的1，把1变0，然后把后面的1全部移到高位。例如：110011110011，我们把其变为110011101110
上述两种情况中找不到的话答案都为-1，构造方法存在对偶性，本质都是暴力，正确性很好证明。
```cpp
class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        int a=-1,b=-1,cnt,v;
        vector<bool> Mark(31,0);
        for (int i=0;i<=30;++i)
            if ((num>>i)&1)
                Mark[i]=true;
        v=num;
        cnt=0;
        for (int i=0;i<=30;++i)
            if (!Mark[i])
            {
                if (!cnt) continue;
                v+=(1<<i);
                for (int j=0;j<i;++j) if (Mark[j]) v-=(1<<j);
                for (int j=0;j<cnt-1;++j) v+=(1<<j);
                a=v;
                break;
            }
            else ++cnt;
        v=num;
        cnt=0;
        for (int i=0;i<=30;++i)
            if (Mark[i])
            {
                ++cnt;
                if (cnt==i+1) continue;
                v-=(1<<i);
                for (int j=0;j<i;++j) if (Mark[j]) v-=(1<<j);
                for (int j=i-1;j>=i-cnt;--j) v+=(1<<j);
                b=v;
                break;
            }
        vector<int> Ans;
        Ans.push_back(a);
        Ans.push_back(b);
        return Ans;
    }
};
```