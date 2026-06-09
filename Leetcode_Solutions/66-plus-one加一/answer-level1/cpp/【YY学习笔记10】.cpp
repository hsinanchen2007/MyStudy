### 解题思路
直接模拟十进制加法的运算法则，但有一点需要额外注意：当最高位有进位时，应在容器最高位插入一个元素1，代表进位。
### 知识点
vector容器的insert(iterator it,const T& x):向量中迭代器指向元素前增加一个元素x。
### 感悟
冲冲冲！！
### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //直接模拟十进制加法运算法则
        digits[digits.size()-1]++;
        for(int i=digits.size()-1;i>0;--i){
            if(digits[i]>9){
                digits[i-1]++;
                digits[i]%=10;
            }
        }
        //对最高位进行处理
        vector<int>::iterator it;
        it=digits.begin();
        if(digits[0]>9){
            digits[0]%=10;
            digits.insert(it,1);
        }
        return digits;
    }
};
```