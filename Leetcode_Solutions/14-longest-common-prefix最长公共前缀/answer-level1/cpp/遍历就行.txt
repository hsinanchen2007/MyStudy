### 遍历
此处存储了size，避免总是求一遍size()，遇到字符串不够长或者失配直接返回
![bbb.png](https://pic.leetcode-cn.com/0c2c1029c8381fb643b51856414238e313cd5d1cc56b38020a2cd41e196f4a71-bbb.png)

### 代码

```cpp

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size=strs.size();
        if(size==0)return "";
        if(size==1)return strs[0];
        char a;int count=0;
        int fsize[size];
        for(int i=0;i<size;i++)
        fsize[i]=strs[i].size();
        while(1)
       {    if(count>=fsize[0])return strs[0];
            a=strs[0][count];
            for(int i=1;i<size;i++)
            {
               if(fsize[i]<=count)return strs[0].substr(0,count);
                if(strs[i][count]!=a)return strs[0].substr(0,count);
            }
            count++;
       }


    }
};
```