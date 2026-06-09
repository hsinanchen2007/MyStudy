num1依次乘以num2的每个数字
如果num1较长，那么每次所做的乘法就会花费较多的时间
如果将num1与每个个位数乘法的结果都用矩阵保存起来，就会节约时间（本文用tempResult[]保存）
```
class Solution {
    inline string MultiplyBySingleDigits(string num, const int& length, const int& singleDigits){
        /// 字符串乘单个数字
        int carry = 0; //进位
        for(int i=length-1; i>=0; --i){
            num[i] = (num[i] - '0') * singleDigits + carry;  //算出乘法结果保存在num[i]
            carry = num[i] / 10;                  //算出下次进位
            num[i] = num[i] % 10 + '0';           //得出当前num[i]
        }
        if(carry) num.insert(num.begin(),carry+'0'); //插入最后的进位

        return num;
    }
    inline void plusString(string& ans, string& temp, const int ShiftLeft){
        /// ans += 左移ShiftLeft后的temp(注：ans高位表示数字低位)
        ans.resize(max(ans.length(),ShiftLeft+temp.length()) + 1, '0');
        int indexAns = ShiftLeft;
        int indexTemp = temp.length() - 1;
        int carry = 0;
        for(; indexTemp>=0 ; --indexTemp){
            carry += ans[indexAns] + temp[indexTemp] - 2*'0';
            ans[indexAns++] = carry % 10 + '0';
            carry /= 10;
        }
        if(carry) ans[indexAns++] = carry + '0';
        ans.resize(indexAns);
    }
public:
    string multiply(string num1, string num2) {
        string ans = "0";          //结果串（字符串高位保存数字低位）
        int length1 = num1.size();
        int length2 = num2.size();

        //长的为num1，短的为num2
        if(length1 <= length2){
            swap(length1, length2);
            swap(num1, num2);
        }

        //保存中间结果的数据结构
        bool isCal[10] = {true, true};     //tempResult是否存有中间结果
        vector<string> tempResult(10);     //num1与每个个位数的乘积

        for(int i=2; i<10; ++i) isCal[i] = false;
        tempResult[0] = "0"; tempResult[1] = num1;

        ///关键：将num2每个个位数与num1相乘，相乘结果为字符串
        ///      再将该字符串与结果串相加
        for(int i2=length2-1; i2>=0; --i2){
            int singleDigits = num2[i2] - '0';
            //如果乘数为0
            if(singleDigits == 0) continue;
            //如果tempResult未存有中间值
            if(!isCal[singleDigits]){
                //字符串与数字的乘法
                tempResult[singleDigits] = MultiplyBySingleDigits(num1,length1,singleDigits);
                isCal[singleDigits] = true;
            }
            //字符串的相加（中间结果串要左移）
            plusString(ans, tempResult[singleDigits], length2-i2-1);
        }

        //翻转ans并输出
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```
