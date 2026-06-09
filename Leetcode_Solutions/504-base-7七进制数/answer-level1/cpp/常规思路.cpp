### 解题思路
总觉得正负数还可以更优化的，各位大佬请多指教。

### 代码

```cpp
class Solution {
public:
    string convertToBase7(int num) {
        string str="";
        if(num>0){
            int sum=num,t=1,total=0;
            while(sum){
                t = sum % 7;
                sum /= 7;
                str += to_string(t + total*10);
            }
            reverse(str.begin(),str.end());
        }
        if(num<0){
            int sum=-num,t=1,total=0;
            while(sum){
                t = sum % 7;
                sum /= 7;
                str += to_string(t + total*10);
            }
            str.push_back('-');
            reverse(str.begin(),str.end());
        }
        if(num==0) str="0";
        return str;
    }
};
```