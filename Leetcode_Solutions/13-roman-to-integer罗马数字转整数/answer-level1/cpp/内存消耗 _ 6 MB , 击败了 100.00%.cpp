### 解题思路
维护两个产量数组，在坐标上相互对应。
利用string的方法find找到对应下标
两个标记，pre是上一个罗马数字的值，cur是现在的值
如果cur下标对应数字大于pre，则减去两倍的cur

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int pre=0;
        int cur=0;
        int index=0;
        int sum=0;
        string ch={"IVXLCDM"};
        int value[7]={1,5,10,50,100,500,1000};
        for(auto c:s){
            index=ch.find(c);
            cur=value[index];
            if(pre<cur){
                sum-=pre*2;
            }
            sum+=cur;
            pre=cur;
        }
        return sum;
    }
};
```