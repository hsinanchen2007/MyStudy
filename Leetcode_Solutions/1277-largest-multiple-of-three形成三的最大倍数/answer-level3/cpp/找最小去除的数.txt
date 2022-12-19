### 解题思路
这个题目要明确：
1、数的位数之和取模3等于0，则这个数能被3整除
2、任何非负整数取模3等于0，1，2
3、取模3等于1的两数之和取模3等于2，取模3等于2的两数之和取模3等于1
4、满足条件的取法是，num%3=1时，去掉最小一个取模3等于1的数，若不存在，去掉最小    两个取模3等于2的数；mun%3=2时，去掉最小一个取模3等于2的数，若不存在，去掉最    小两个取模3等于1的数
5、所以要满足条件，需要舍掉0、1、或2个数

### 代码

```cpp
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> temp = digits;
        sort(temp.begin(), temp.end(), greater<int>());
        vector<int> mo1;
        vector<int> mo2;
        int sum = 0;
        for(auto i : temp){
            sum += i;
            if( (i % 3) == 1 ){
                mo1.push_back(i);
            }
            else if( (i % 3) == 2 ){
                mo2.push_back(i);
            }
        }
        if(sum == 0){
            return "0";
        }

        int a = -1;
        int b = -1;
        int m = sum % 3;
        switch(m){
            case 1:
                if(mo1.size())
                    a = mo1[mo1.size() - 1];
                else{
                    a = mo2[mo2.size() - 1];
                    b = mo2[mo2.size() - 2];
                }
                break;
            case 2:
                if(mo2.size())
                    a = mo2[mo2.size() - 1];
                else{
                    a = mo1[mo1.size() - 1];
                    b = mo1[mo1.size() - 2];
                }
                break;
            default:
                break;
        }
        string ans;
        for(auto i : temp){
            if( i == a ){
                a = -1;
                continue;
            }
            else if( i == b ){
                b = -1;
                continue;
            }
            ans += to_string(i);
        }
        return ans;
    }
};
```