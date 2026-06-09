### 解题思路
1. 转换为数字，然后+1，再转换回来，这里测试出来两种异常：
    1. (int)temp%10 在对int越界的情况下会计算错误，需要改为int(temp%10);
    2. 即使使用long long 来计算，也会有越界情况
所以此种方法被放弃
2. 则直接进行转换：
    1. 从末位开始计算，如果为9，则该位记0，继续运算前一位；
    2. 直到不为9的位累加后返回；
    3. 如果进行到最后一位都为9，则在数组中0位置插入一个1；

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //将数组转换为数字，加一后再转为数组，避免考虑多种情况出现case考虑出错
        // 挺坑的，存在越界问题，所以这个问题不能这么做；
        /*
        vector<int> result;
        long long  temp = 0;
        for(int i=0; i<digits.size(); i++){
            temp=10*temp + digits[i];
        }
        temp += 1;
        //cout << temp << endl;
        while(temp != 0) {
            //cout<<temp%10 << endl;
            result.insert(result.begin(), 1, int(temp%10));
            temp = temp/10;
        }
        return result;
        */
        //直接转换的做法吧
        vector<int> result;
        for(int i=digits.size()-1; i>=0; i--){
            if(9 != digits[i]) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1, 1);
        return digits;
    }
};
```