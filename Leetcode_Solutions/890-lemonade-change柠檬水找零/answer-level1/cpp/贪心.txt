### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5=0,c10=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5)c5++;
            else if(bills[i]==10){
                if(c5<=0){
                    return false;
                }
                else{
                    c5--;
                    c10++;
                }
            }
            else{
                if(c5<=0){
                    return false;
                }
                else if(c10<=0&&c5<=3){
                    return false;
                }
                else if(c10>0){
                    c10--;
                    c5--;
                }
                else{
                    c5-=3;
                }
            }
        }
        return true;
    }
};
```