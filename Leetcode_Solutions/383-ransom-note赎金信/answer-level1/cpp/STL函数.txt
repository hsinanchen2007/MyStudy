### 解题思路
纯用库函数，为了熟悉string成员函数，运行时间较长

### 代码

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for(string::const_iterator iter = ransomNote.begin();iter!=ransomNote.end();++iter)
        {
            if(magazine.empty()) 
                return false;
            else
            {  auto index  = magazine.find(*iter);
               if(index==string::npos)
                    return false;
               else
                    magazine.erase(index,1);
            }
            
        }
        return true;
    }
};
```