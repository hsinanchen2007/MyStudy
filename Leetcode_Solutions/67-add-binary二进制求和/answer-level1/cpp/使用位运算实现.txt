### 解题思路
1. 使用&运算从最高位算起
2. 对于进位，直接把每次的计算结果右移一位即可: 2>>1=1(有进位) 0/1>>1=0(无进位)
3. 最后处理和的时候看`ans[0]`是0还是1，如果是0，说明没进位，把它删去。
效率还不错
```
执行用时 :4 ms, 在所有 C++ 提交中击败了87.07%的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了64.96%的用户
```
### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int lena=a.size();
        int lenb=b.size();
        int len=max(lena, lenb)+1;
        int carry=0;
        string ans(len, '0');
        while(--len>=0){
            // cout<<a[lena]-'0'<<" "<<b[lenb-1]<<endl;
            long vala=--lena>=0?a[lena]-'0':0;
            long valb=--lenb>=0?b[lenb]-'0':0;
            // cout<<sizeof(a[lena])<<endl;
            ans[len]=((vala+valb+carry)&1)+'0';
            carry=(vala+valb+carry)>>1;
        }
        if (ans[0] == '0') ans.erase(0, 1); 
        return ans;
    }
};
```