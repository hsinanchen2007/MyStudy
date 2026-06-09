用数组存储对应位相乘的结果，在遍历两个数组相乘的时候只把结果累加到对应位即可，先不考虑进位的问题。所有对应位相乘完后遍历结果数组完成进位处理即可。



class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){     //相乘结果为0的特殊情况
            return "0";
        }
        int len1 = num1.length() - 1, len2 = num2.length() - 1, end = 220;
        int ret[221] = {0};
        for(int i=len1; i>=0; i--){         //先不考虑进位，所有相乘结果累加存储在对应位
            int offset = 0;
            for(int j=len2; j>=0; j--){
                ret[end - offset] += (num1[i] - '0')*(num2[j] - '0');
                offset++;
            }
            end--;
        }
        for(int i=220; i>=0; i--){          //遍历数组处理所有的进位
            if(ret[i] >= 10){
                ret[i-1] += ret[i]/10;
                ret[i] = ret[i]%10;
            }
        }
        int start = 0;
        for(int i=0; i<221; i++){           //找到数字开头
            if(ret[i] != 0){
                start = i;
                break;
            }
        }
        char res[221];
        int len = 0;
        for(; start<221; len++){            //将数组赋给字符串
            res[len] = ret[start++] + '0';
        }
        res[len]='\0';
        return string(res);
    }
};