### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int reverseBits(int num) {
        if(num==0)
        return 1;
        int per=0;
        int count=0;
        int k=0;
        bool flag=true;
        int max=0;
        int n=num;
        int wei=0;
        while(n>0)
        {
            n/=2;
            wei++;
        }

        while(k<wei+1)
        {
            if(num&(1<<k))
            {
                count++;
            }
            else
            {
                if(flag)
                {per=k;
                flag=false;
                count++;}
                else
                {
                    if(count>max)
                    max=count;
                    flag=true;
                    k=per;
                    count=0;
                }

            }
            k++;
        }
        if(count>max)
        max=count;
        return max;


    }
};
```