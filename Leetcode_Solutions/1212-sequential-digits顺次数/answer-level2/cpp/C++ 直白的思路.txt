### 解题思路
每次确定数字位数、最高位的值，然后得出对应的顺次数。

### 代码

```cpp
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int temp;
        int k;
        int len=1;//保存位数
        temp = low;//保存顺次数
        k = temp; // 保存最高位数字
        while(k>=10){
            k = k/10;
            len++;
            }
        while(temp<=high){ //结束条件为顺次数超出最大值
            if(k>9-len+1) {len++;k=1;} // 最高位数字应该小于9-len+1，否则就要进位
            temp = k;//确定最高位的值之后，根据长度和规则，求出后面几位的值
            for(int i=1;i<len;i++) temp = temp*10 + k + i;
            if((temp>=low)&&(temp<=high)) res.push_back(temp);//判断是否满足要求
            k++;
        }
        return res;
    }
};
```