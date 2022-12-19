### 解题思路
此处撰写解题思路
1. 开辟一个整形数组存储各位数字
2. 将相乘结果逐位存储在一个整形数组中
3. 计算完成后，开始对各位进行进位运算
4. 将结果输入一个字符串，输出结果



### 代码

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        string ret;
        int len1 = num1.size();
        int len2 = num2.size();

        //cout << "num1 : " << num1 << " , " << len1 << endl;
        //cout << "num2 : " << num2 << " , " << len2 << endl;

        if(len1 == 0 || len2 == 0)
        {
            ret.push_back('0');
            return ret;
        }
        
        if (len1 == 1) {
            //cout << "len1 !" <<endl;
            if(num1[0] == '0') {
                ret.push_back('0');
                return ret;
            } else if(num1[0] == '1') {
                //for(int u = 0; u < len2; u++) {
                //    ret.push_back(num2[u]);
                //}
                return num2;
            }
        } 
        
        if (len2 == 1) {
            if(num2[0] == '0') {
                ret.push_back('0');
                return ret;
            } else if(num2[0] == '1') {
                //for(int u = 0; u < len2; u++) {
                //    ret.push_back(num1[u]);
                //}
                return num1;
            }
        }

        int needadd = 0;
        int result[500] = {0};
        int pos = 0;
        int temp = 0;
        int a = 0;
        int b = 0;
        int i = 0;
        int j = 0;
        int k = 0;
        int maxpos = 0;


        for(i = len1 -1, pos = 0; i >= 0; i-- , pos++) {
            a = num1[i] - '0';

            //cout << "pos : " << pos << endl;

            for(j = len2 - 1 , k = 0; j >= 0; j-- , k++){
                b = num2[j] - '0';
                temp = a*b;
                //cout << pos + k << " : " << temp << endl;
                result[pos+k] += temp;
                //cout << result[pos + k] << endl;
            }
            //cout << endl;
        }

        needadd = 0;
        for(i = 0; i < pos + len2; i++) {
            temp = result[i] + needadd;
            needadd = temp / 10;
            temp = temp % 10;
            result[i] = temp;
        }

        while(needadd != 0) {
            temp = needadd;
            needadd = temp / 10;
            temp = temp % 10;
            result[i] = temp;
            i++;
        }

        while(result[i] == 0) {
            i--;
        }

        for (j = i; j >= 0; j--) {
            ret.push_back(char (result[j] + '0'));
        }

        return ret;
    }
};
```