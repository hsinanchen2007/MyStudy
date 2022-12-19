### 解题思路
第一步：判断缺席是否超过一次，超过了直接返回false。
第二步：缺席次数过关，且出勤记录小于等于二的话，因为迟到次数不可能大于二，它必然能得到奖赏，返回true。
第三步：依次查找，发现三个连续得L，返回false。
第四步：返回true。

### 代码

```cpp
class Solution {
public:
    bool checkRecord(string s) {
        
        if(count(s.begin(),s.end(),'A')>1)
        {
            return false;
        }
        
        if(s.size()<=2)
        {
            return true;
        }
        
        for(int i=0;i<s.size()-2;i++)
        {
            if(s[i]=='L' && s[i+1]=='L' && s[i+2]=='L')
            {
                return false;
            }
        }
        
        return true;

    }
};
```