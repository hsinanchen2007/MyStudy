只用考虑i<=j<=k
如果i==j==k A(3,3)/A(3,3)=1
如果有两个相等 A(3,3)/A(2,2)=3
如果都不相等 A(3,3)=6
速度不忍直视
![TIM截图20191220153136.png](https://pic.leetcode-cn.com/abfde29c9c7603806805e12d4693df49143d05307d8906dc5ca44c9c3badb634-TIM%E6%88%AA%E5%9B%BE20191220153136.png)


```
int countTriplets(const vector<int>& A)
{
    const int size = A.size();
    int result = 0;
    for (int i = 0; i < size; ++i)
        for(int j=i;j<size;++j)
            for (int k = j; k < size; ++k)
            {
                if ((A[i] & A[j] & A[k]) == 0)
                {
                    if (i == j)
                        if (j == k)
                            result = result + 1;
                        else
                            result = result + 3;
                    else
                        if (j == k)
                            result = result + 3;
                        else
                            result = result + 6;
                }
            }
    return result;
}
```

