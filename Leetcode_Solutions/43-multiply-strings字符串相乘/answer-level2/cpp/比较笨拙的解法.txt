### 解题思路
列竖式计算，未经过优化

### 代码

```cpp
class Solution {
public:
    string addsum(string & sTotal, string & sTemp) {
        string re;
        int i=sTotal.size()-1;
        int j=sTemp.size()-1;
        int carry = 0;
        while (i>=0 || j>=0) {
            int val1 = i<0 ? 0 : sTotal[i]-'0';
            int val2 = j<0 ? 0 : sTemp[j]-'0';
            int sumTemp = (val1+val2+carry)%10;
            carry = (val1+val2+carry)/10;
            re.push_back('0'+sumTemp);
            i--;
            j--;
        }
        if (carry != 0) re.push_back('0'+carry);
        reverse(re.begin(), re.end());
        return re;
    }
    string multiply(string num1, string num2) {
        string sumTotal;
        int sizeTotal = 0;
        if (num1[0]=='0' || num2[0]=='0') return "0";
        for (int i=num1.size()-1; i>=0; i--) {
            int carry = 0;
            int val1 = num1[i]-'0';
            string tempsum;
            for (int j=num2.size()-1; j>=0; j--) {
                int val2 = num2[j]-'0';
                tempsum.push_back('0'+(val1*val2+carry) % 10);
                carry =  (val1*val2+carry)/10;
            }
            if (carry != 0) tempsum.push_back('0'+carry);
            reverse(tempsum.begin(), tempsum.end());
            for (int i=0; i<sizeTotal; i++) {
                tempsum.push_back('0');
            }
            sizeTotal++;
            sumTotal = addsum(sumTotal, tempsum);
        }
        return sumTotal;
    }
};
```