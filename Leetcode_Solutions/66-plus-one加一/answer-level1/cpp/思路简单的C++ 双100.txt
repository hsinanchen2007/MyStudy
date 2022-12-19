题目开始没看懂，看懂了发现有点简单.....
```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size(digits.size());
        // 如果最后一位不是9，直接加1输出就完事了。
        // 其实加不加这个条件都差不多。
        if (digits[size-1]!=9){
            digits[size-1]=digits[size-1]+1;
            return digits;
        }
        else {
            vector<int> result(size,0);
            int flag(1); //进位，初始置1
            for (int i(0);i<size;i++){
                result[size-i-1]=(digits[size-i-1]+flag)%10; // 余数
                flag=(digits[size-i-1]+flag)/10; // 进位更新
            }
            if (flag>0){
                result.insert(result.begin(),flag); //如果最后进位还大于0，就插入flag在容器头
            }
            return result;
        }
    }
};
```
