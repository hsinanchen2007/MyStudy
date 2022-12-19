using System;
using System.Text.RegularExpressions;

public class Solution {
    public int MyAtoi(string str) {
        str = Regex.Match(str.Trim(), @"^[\+\-]?\d+").ToString();

        bool t_IsParse = int.TryParse(str, out int o_Num);
        if (t_IsParse) {
            return o_Num;
        }
        else {
            if (string.IsNullOrEmpty(str)) {
                return 0;
            }
            else {
                if (str[0] == '-') {
                    return -2147483648;
                }
                else {
                    return 2147483647;
                }
            }
        }
    }
}