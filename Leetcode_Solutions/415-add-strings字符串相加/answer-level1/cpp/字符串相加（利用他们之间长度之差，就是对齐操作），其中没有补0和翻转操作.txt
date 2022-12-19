### 解题思路（0 ms	9.1 MB	Cpp）
找出最大的字符串数字(使得num1为最长的字符串)，计算它们之间的距离，遍历最小的字符串(num2)，根据他们之间的位移d将结果保存在最大字符串中(num1)，最后如果进位数不为0，则进行结果字符串(num1)+1操作，如果不知道+1操作，可以在leetcode中搜索‘字符串加1’

### 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() < num2.size()){
            string t = num1;
            num1 = num2;
            num2 = t;
        }
        int d = num1.size() - num2.size();
        int plusNumber = 0;
        for(int i = num2.size() - 1; i >= 0; i--){
            int t = num1[i + d] + num2[i] - 96 + plusNumber;
            num1[i + d] = t % 10 + 48;
            plusNumber = t / 10;
        }
        if(plusNumber){
            int i = 0;
            while(d - 1 - i >= 0){
                if(num1[d - 1 - i] != '9'){
                    num1[d - 1 - i]++;
                    return num1;
                }
                num1[d - 1 - i] = '0';
                i++;
            }
            return "1" + num1;
            
        }
        return num1;
    }
};
```