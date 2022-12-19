内存消耗大，但速度快，将二进制字符转化为int 整数来操作

![捕获.PNG](https://pic.leetcode-cn.com/9564e5fbf0f44d139a6f6c42d1a93de65ca513dba0096524e63df7182712c2fc-%E6%8D%95%E8%8E%B7.PNG)

```
class Solution {
public:
    string addBinary(string a, string b) {
    int min=0;
    int j=a.size()-1;
    int k=b.size()-1;
    string s="";
    if(a.size()>=b.size()) //min+1保证进位情况下不溢出
        min=a.size()+1;
    else
        min=b.size()+1;
    vector<int> A(min,0);
    vector<int> B(min,0);
    vector<int> C(min,0);
    for(int i=min-1;i>=1;i--)
    {
        if(j>=0)                    //将string分解成单个数字存入vector
            A[i]=a[j]-'0';
        if(k>=0)
            B[i]=b[k]-'0';
        if(i==min-1)//第一位不存在进位
        {
            C[i]=(A[i]+B[i])%2;   //a+b 在当前位上对2求余
            C[i-1]=(A[i]+B[i])/2;//若进位保存在下一位
        }
        else             //后序位可能存在进位应将进位加入
        {
            int t=C[i];//t表示当前位的进位
            C[i]=(A[i]+B[i]+t)%2;
            C[i-1]=(A[i]+B[i]+t)/2;
        }
        j--;
        k--;
    }
    if(C[0]==1)
    {
        for(int i=0;i<min;i++)
            s=s+to_string(C[i]);
    }
    else
        for(int i=1;i<min;i++)
            s=s+to_string(C[i]);
    return s;
    }
};
```