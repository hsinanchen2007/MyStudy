可将数组A看作成一个[len1]*[len2]的普通数组，len1表示字符串的个数，len2表示各字符串的长度。
循环每一个元素，即每一个字符串中的每个字符，对某一列j里有A[i1][j]>A[i2][j],且i1<i2时，说明这一列不符合非降序规则，
这时可以计数+1。

以此类推，代码如下：

```cpp
int minDeletionSize(vector<string>& A) {
        int n=0;
        int len1=A.size();
        int len2=A[0].length();


        for(int j=0;j<len2;j++)
        {
            for(int i=0;i<len1-1;i++)
            {
                if(A[i][j] > A[i+1][j])
                {
                    n++;
                    break;
                }
            }
        }
        return n;
    }
```