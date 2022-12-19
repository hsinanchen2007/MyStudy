class Solution {
public:
    int myAtoi(string str) {
        int length = str.length();
        string result;
        int sum = 0;
        int m = 0;
        int f = 1;
        int b = 0; //标志位，用于判断前面第一个非0位
        for (int i = 0; i < length; i++) {
            if( str[i] == ' ' ) { //找到第一个非空格字符
                continue;
            }
            else {
                if ( str[i] == '-' ) { //负数时的情况，完成后退出循环，防止再次找数
                    result += str[i];
                    for (int j = i + 1; j<length; j++) {
                        if( str[j] >= '0' && str[j] <= '9') {
                            if (str[j] > '0' ) { //找到第一个非0位，b置1，否则不加入到result中
                                b = 1;
                            }
                            if (b) {
                                result += str[j];
                            }
                        }
                        else { //如果不是整数，那么退出
                            break;
                        }
                    }
                    break;
                }
                else if ( str[i] == '+' || (str[i] >= '0' && str[i] <= '9')) { //正数的情况，完成后退出循环，防止再次找数
                    if ( str[i] == '+' ) {
                        i++;
                    }
                    for (int j = i; j<length; j++) {
                        if( str[j] >= '0' && str[j] <= '9') {
                            if (str[j] > '0' ) { //找到第一个非0位，b置1，否则不加入到result中
                                b = 1;
                            }
                            if (b) {
                                result += str[j];
                            }
                        }
                        else {
                            break;
                        }
                    }
                    break;
                }
                else { //第一个非空格数既不是负号和正号也不是数字，退出
                    break;
                }
            }
        }
        m = result.length(); //取结果的位数
        if ( result[0] == '-' ) {
            f = -1;
            if ( m >= 12 || (m == 11 && result >= "-2147483648")) { //负溢出
                return -2147483648;
            }
        }
        else {
            if ( m >= 11 || (m == 10 && result >= "2147483647")) { //正溢出
                return 2147483647;
            }
        }
        for (int i = 0; i < m; i++) {
            if ( result[i] == '-' ) {
                continue;
            }
            int j = 1;
            for (int p = 1; p< m - i; p++) {
                j *= 10;
            }
            sum = sum + (result[i] - '0') * j;
        }
        return sum * f;
    }
};