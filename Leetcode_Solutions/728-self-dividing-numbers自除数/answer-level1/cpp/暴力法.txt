
### 代码

```cpp
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> v;
        
        for(int i=left;i<=right;i++)
        {
            int num=i;
            while(num>0)
            {
                if(num%10==0 || i%(num%10)!=0)
                {
                    break;
                }
                num/=10;
            }
            if(num==0)
            {
                v.push_back(i);
            }
        }
        
        return v;

    }
};
```