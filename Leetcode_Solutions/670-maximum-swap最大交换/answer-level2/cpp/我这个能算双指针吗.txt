### 解题思路
![image.png](https://pic.leetcode-cn.com/0ce9186f01f3e95b79fb7e2fbba725cdcf904aa6b7eec84444e74143e8be46ef-image.png)

### 代码

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        int m=0,j=0;
        string s=to_string(num);
        for(int i=1;i<s.size();++i)
        {
            if(j==0&&s[i]>s[i-1])
            {
                m=s[i];
                j=i;
            }
            if(j!=0&&s[i]>=m)
            {
                j=i;
                m=s[i];
            }
        }
        if(j!=0)
        {
            for(int i=0;i<j;i++)
            {
                if(s[i]<s[j])
                {
                    swap(s[i],s[j]);
                    break;
                }
            }
        }
        num=stoi(s,0,10);
        return num;
        
    }
};
```