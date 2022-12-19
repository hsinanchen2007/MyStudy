### 解题思路
对于样例中n=4：
                      left     right    初始位置
L     D     R          +6       +0      (n-4)%n
E   O E   I I          +4       +2      (n-3)%n
E C   I H   N          +2       +4      (n-2)%n
T     S     G          +0       +6      (n-1)%n
对应代码部分即第二层循环中，每次向待输出字符串中添加对应位置的字符。
注意：
1.pos下标越界的判断。
2.划分长度为1时，直接返回原字符串即可。
第一次写题解，希望对大家有所帮助、启发！
### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string res="";
        int nn=numRows; 
        int pos=0;
        int left=nn*2-2;
        int right=0;
        while(nn>0)
        {
            int pos=(numRows-nn)%numRows;
            while(pos<s.length())
            {
                if(pos<s.length()&&left!=0)
                {
                    res+=s[pos];
                    pos+=left;
                }
                if(pos<s.length()&&right!=0)
                {
                    res+=s[pos];
                    pos+=right;
                }
            }
            nn--;
            left-=2;
            right+=2;
        }
    return res;
    }
};
```