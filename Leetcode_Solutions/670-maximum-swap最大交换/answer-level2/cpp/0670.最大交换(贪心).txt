### 解题思路
用$las[i]$表示数字$i$从右到左(从个位开始)第一次出现的位置.
然后从最高位开始遍历,若当前位的右方有比当前位数字大的数字,取最大一个交换即可.

### 代码

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        vector<int> tmp;
        int las[10];
        memset(las,-1,sizeof(las));
        while(num)
        {
            tmp.push_back(num%10);
            num/=10;
        }
        for(int i=tmp.size()-1;i>=0;i--)
        {
            las[tmp[i]]=i;
        }
        bool flag=1;
        for(int i=tmp.size()-1;i>=0&&flag;i--)
        {
            for(int j=9;i>=0;j--)
            {
                if(las[j]==-1)
                    continue;
                if(j<=tmp[i])
                    break;
                if(las[j]<i)
                {
                    swap(tmp[i],tmp[las[j]]);
                    flag=0;
                    break;
                }
            }
        }
        int ans=0,p=1;
        for(int i=0;i<tmp.size();i++)
        {
            ans+=p*tmp[i];
            p*=10;
        }
        return ans;
    }
};
```