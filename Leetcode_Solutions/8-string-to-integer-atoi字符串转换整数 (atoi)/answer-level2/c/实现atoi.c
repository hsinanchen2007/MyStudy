### 解题思路
，关键是溢出判断还有*10+tmp

### 代码

```c
int myAtoi(char * str){
    // 移除开头的空格
    while(*str == ' ')
        ++str;

    // 记录正负性，便于之后溢出返回值进行判断
    int flag = 1;
    if (*str == '-') {
        flag = -1;
        str++;
    }
    else if (*str == '+')
        str++;
    int ret = 0;

    // 因为只能使用 32 位 int，因此将 ret 乘 10 后再与 INT_MAX 比较可能会溢出
    // 因此使用 ret 与 INT_MAX/10 比较
    int div = INT_MAX / 10;
    while (*str >= '0' && *str <= '9') {
        int tmp = *str - '0';
        // 若 ret 比 div 小，则 ret * 10 + dig 也一定小于 INT_MAX，不会溢出
        // 若 ret 与 div 相等，只有 dig 比 8 小时不会溢出
        // 此处本来需要正负分开讨论，INT_MAX 个位是 7，INT_MIN 个位是 8
        // -INT_MIN 在 int 中会溢出，当 dig == 8 时直接当作溢出处理
        if (ret < div || (ret == div && tmp < 8)) {
            ret = ret * 10 + tmp;
            str++;
        }    //为8时，则当作溢出处理，return min

        // 溢出，根据正负性返回值
        else
            return (flag == 1? INT_MAX: INT_MIN);
    }
    return flag * ret;
}

``` JAVA：
public class Solution {
    public int myAtoi(String str) {
        char[] chars = str.toCharArray();
        int n = chars.length;
        int idx = 0;
        while (idx < n && chars[idx] == ' ') {
            // 去掉前导空格
            idx++;
        }
        if (idx == n) {
            //去掉前导空格以后到了末尾了
            return 0;
        }
        boolean negative = false;
        if (chars[idx] == '-') {
            //遇到负号
            negative = true;
            idx++;
        } else if (chars[idx] == '+') {
            // 遇到正号
            idx++;
        } else if (!Character.isDigit(chars[idx])) {
            // 其他符号
            return 0;
        }
        int ans = 0;
        while (idx < n && Character.isDigit(chars[idx])) {
            int digit = chars[idx] - '0';
            if (ans > (Integer.MAX_VALUE - digit) / 10) {
                // 本来应该是 ans * 10 + digit > Integer.MAX_VALUE
                // 但是 *10 和 + digit 都有可能越界，所有都移动到右边去就可以了。
                return negative? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
            ans = ans * 10 + digit;
            idx++;
        }
        return negative? -ans : ans;
    }
}