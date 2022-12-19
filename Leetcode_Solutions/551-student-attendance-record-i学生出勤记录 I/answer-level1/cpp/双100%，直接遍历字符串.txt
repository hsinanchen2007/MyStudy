### 解题思路
思路很简单，代码如下

### 代码

```cpp
class Solution {
public:
    bool checkRecord(string s) {
        int count=0;            //记录连续L的个数
        int A=0;                //记录A的个数
        for(auto c : s){
            bool flag=false;
            switch(c){
                case 'L':
                    count++;
                    if(count>=3) flag=true;
                    break;
                case 'A':A++;
                default: count=0;
            }
            if(flag) break;
        }
        return !(count>=3||A>1);
    }
};
```