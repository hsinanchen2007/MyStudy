### 解题思路
设变换后的字符串为str,
将str的numRows行字符串分成三部分：
     第一行为第一部分，等差数列可以求出str第一行的字符在s中对应的位置，填入s中，并用数组spoint记录
str第一行字符在s中的位置。
    第二行到第numRows-1行，第一行的第i个字符对应了第k行 的两个字符（根据边界条件可能为一个），也可能
第k行的字符没有和第一行的字符对应（如果出现一定在第k行的末尾，边界条件判断）。
    最后一行，与第一行类似

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
        {
            return s;
        }
        int n=s.length();
        int spoint[n+1];  //从1开始
        spoint[0]=0;
        string str(s);    //从0开始
        for(int i=1,j=1;j<=n;i++,j+=(2*numRows-2)) //第一行排好
        {
            spoint[i]=j;
            spoint[0]++;
            str[i-1]=s[j-1];
        }
        int strl=spoint[0];
        int temp=0;
        for(int k=2;k<numRows;k++)
        {
            for(int i=1;i<=spoint[0];i++)
            {
                if(i>1)
                {
                    str[strl]=s[spoint[i]-k];
                    strl++;
                }
                if(spoint[i]+k-2<n)
                {
                    str[strl]=s[spoint[i]+k-2];
                    strl++;
                }
            }
            temp=spoint[spoint[0]]+2*numRows-2-k;
            if(temp<n)
            {
                str[strl]=s[temp];
                strl++;
            }


        }
        
        for(int i=numRows-1;i<n;i+=(2*numRows-2))
        {
            str[strl]=s[i];
            strl++;
        }
        return str;

        
    }
};
```