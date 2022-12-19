### 解题思路
1.R与L的相对位置保持一致
2.R只能右移L只能左移

### 代码

```cpp
class Solution {
public:
    bool canTransform(string start, string end) {
        int m=start.length();
        if(m!=end.length())return false;
        start+='o';end+='o';
        m++;
        int i,j;
        for( i=0,j=0;i<m,j<m;)
        {
            while(i<m&&start[i]=='X')i++;
            while(j<m&&end[j]=='X')j++;
          
            if(start[i]!=end[j])return false;
            else
            {
                if(start[i]=='R'&&i>j)return false;
                if(start[i]=='L'&&i<j)return false;
                i++;j++;
            }     
        }
        return true;
    }
};
```