### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        def get_mod_data(m):
            data_m=[]
            while(m):
                data_m.append(m%2)
                m=int(m/2)
            return data_m
        def get_frist_d_value(m_n):
            m_n=m_n+1;
            return len(get_mod_data(m_n))
        def get_gap_m_n(m,n,len_m_n):
            if (m<2**len_m_n and n>2**len_m_n) or(m<2**(len_m_n+1) and n>(2**(len_m_n+1)) ) :
                return True
            else:
                return False
        def get_diff(data_m,data_n,len_m_n,len_):
            for i in range(len_m_n,len_):
                if data_n[i] != data_m[i]:
                    return True
            return False
        def get_ans(m,n):
            ans=0
            data_m=get_mod_data(m)
            data_n=get_mod_data(n)
            data_mn=[]
            len_=min(len(data_m),len(data_n))
            m_n=n-m
            len_m_n=get_frist_d_value(m_n)
            print(len_m_n,len_)
            for i in range(len_):
                #print(data_m[i],data_n[i])
                if i+1 >len_m_n:
                    ans=ans+(data_m[i] & data_n[i])*2**i
                elif i+1==len_m_n:
                    print(get_gap_m_n(m,n,len_m_n))
                    if (not (get_gap_m_n(m,n,len_m_n) or get_diff(data_m,data_n,len_m_n,len_))):
                         ans=ans+(data_m[i] & data_n[i])*2**i
            return ans
        #print(get_gap_m_n(6,7,2))
        return get_ans(m,n)



```