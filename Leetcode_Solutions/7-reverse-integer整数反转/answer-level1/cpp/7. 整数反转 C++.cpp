    
```cpp
class Solution {
public:
    int reverse(int x) {

        int div = 1;
        while (x / div >= 10 || x / div <= -10) //支持负数    //注意：这里用abs会报错 当x = -2147483648
        {
            div *= 10;
        }

        int reversed = 0;

        while (x)
        {
            //预先检查相加是否会导致溢出
            if (reversed > INT_MAX - (long long)x % 10 * div)  //注意：x % 10 * div可能会超过int范围
            {
                return 0;
            }

            else if (reversed  < INT_MIN - (long long)x % 10 * div)  //注意：x % 10 * div可能会超过int范围
            {
                return 0;
            }

            reversed += (x % 10 * div);

            div /= 10;
            x /= 10;
        }

        return reversed;
    }


    int reverse(int x) {

        int reversed = 0;

        int int_max_single_digits = INT_MAX % 10;
        int int_max_except_single_digits = INT_MAX / 10;

        int int_min_single_digits = INT_MIN % 10;
        int int_min_except_single_digits = INT_MIN / 10;

        while (x)
        {
            int pop = x % 10;
            x /= 10;

            if (reversed > int_max_except_single_digits || (reversed == int_max_except_single_digits && pop > int_max_single_digits))
            {
                return 0;
            }

            if (reversed < int_min_except_single_digits || (reversed == int_min_except_single_digits && pop < int_min_single_digits))
            {
                return 0;
            }

            reversed = reversed * 10 + pop;
        }

        return reversed;
    }
};