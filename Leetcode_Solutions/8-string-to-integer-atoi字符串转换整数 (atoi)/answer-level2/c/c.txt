### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX_INT32 2147483647
#define MIN_INT32 -2147483648

bool isNum(char ch)
{
    if (ch >= '0' && ch <= '9') {
        return true;
    }
    return false;
}
int myAtoi(char * str) {
	int sum = 0;
	int len;
	int i;
	int flag = 1;
	int firstValidFlag = 0;

	if (str == NULL) {
		return 0;
	}
    len = strlen(str);

    for (i = 0; i < len; i++) {
        if (firstValidFlag == 0) {
            if (str[i] == '+' || str[i] == '-' || isNum(str[i]) == true) {
                if (str[i] == '-') {
                    flag = -1;
                }
                else if (str[i] == '+') {
                    flag = 1;
                }
                else {
                    sum += str[i] - '0';
                }
                firstValidFlag = 1;
            }
            else {
                if (str[i] != ' ') {
                    return 0;   // 第一个字符不是正负号或数字
                }
            }
        } else {
            if (isNum(str[i]) == false) {
                break;
            }
            // 主要思路是先将所有的有效字符组合成正数，最后根据符号位转成负数，所以这里一定需注意int可表示的最大正负为2147483647，
            // 需判断是>=8即达到最大上限了
            if ((sum > 214748364) || (sum == 214748364 && str[i] >= '8')) {
                if (flag == -1) {
                    return MIN_INT32;
                } else {
                    return MAX_INT32;
                }
            } else {
                sum = sum * 10 + (str[i] - '0');
            }
        }
    }

	return flag * sum;
}
```