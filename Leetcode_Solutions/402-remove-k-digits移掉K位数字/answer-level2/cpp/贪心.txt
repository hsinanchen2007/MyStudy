### 解题思路
贪心：在位数确定的情况下，前面的数值越小，整个数越小，那么在遍历的时候把数值小的数尽量往前移

### 代码

```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        int p=0;
        for(char c : num){
            while(res.size()>0&&c<res.back()&&p<k){//将小的数字往前移
                res.pop_back();
                p++;
            }
            res.push_back(c);
        }
        while(p++<k) res.pop_back();//从后往前减小位数（因为后面的数字大于等于前面的数字）
        while(res.size()>0&&res[0]=='0') res.erase(0,1);//去除前导0
        return res==""?"0":res;//为空的话输出0
    }
};
```