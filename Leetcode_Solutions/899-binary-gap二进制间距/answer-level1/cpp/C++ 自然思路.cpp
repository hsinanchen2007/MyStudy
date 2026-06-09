![image.png](https://pic.leetcode-cn.com/0c5cfcf2328f0551b556e55c806c77af403d5309eeeaa55d15c77009c81a5ca6-image.png)
解题思路：判断当前位是否为1，若为1，且1的个数大于等于2，则计算0的个数(+1),保存最大并返回即可
```
    int binaryGap(int N) {
        int res = 0, count = -1, onenum = 0;
        while(N>0)
        {
            count++;
            if(N % 2 == 1)
            {
                onenum++;
                if(onenum>1 && count>res)
                    res = count;
                count = 0;
            }        
            N = N / 2;
        }
        return res;
    }
```

