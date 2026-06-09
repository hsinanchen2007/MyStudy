做这一题属实细节方面考虑不周到，靠着样例不断完善最后才通过。
- 思路：利用java的split函数对字符串进行处理，分割成一个一个的部分，其中 "." 以及 ":" 字符为特殊字符，需要特殊处理。
1. **空字符串必定不是** IPv4 和 IPv6 地址，返回 Neither；
2. 地址长度可以作为区别 IPv4 和 IPv6 的标准。
    （1）对于 IPv4 而言，每个位置仅有 1 位的情况下，长度为 4 * 1 + 3 = 7，全满状态下，长度为 4 * 3 + 3 = 15；
    （2）对于 IPv6 而言，每个位置仅有 1 位的情况下，长度为 8 * 1 + 7 = 15，全满状态下，长度为 8 * 4 + 7 = 39；
    （3）因此，长度在 7 和 15 之间且包含 "." 的属于判断 IPv4 的范围内；长度在 15 和 39 之间且包含 ":" 的属于判断 IPv6 的范围内。
3. 要判断一个地址是否为 IPv4 条件（此时 "." 已被split）如下：① **没有除0-9之外的字符**；② 每个部分**长度范围 1 - 4**；③ 每个部分在 **长度为 1** 的情况下的**首位不可为 0**；④ 每个部分的**数字不可大于255**；⑤ split函数应当拆出**4个部分**；
4. 要判断一个地址是否为 IPv6 条件（此时 ":" 已被split）如下：① 仅有**数字 0-9，字母 a - f，字母 A - F**；② 每个部分**长度范围 1 - 4**；③ split函数应当拆出**8个部分**。


菜鸡代码如下：
```
class Solution {
    public String validIPAddress(String IP) {
        if(IP.length() == 0) return "Neither";
        if(IP.length() < 7 && IP.length() > 39) return "Neither";
        else if(IP.length() >= 7 && IP.length() < 16 && IP.contains(".") == true) {
            if(IP.charAt(IP.length() - 1) == '.') return "Neither";
            String[] str = IP.split("\\.");
            if(str.length < 4 || str.length > 4) return "Neither";
            else {
                for(int i = 0;i < str.length;i++) {
                    if(str[i].length() == 0) return "Neither";
                    for(int j = 0;j < str[i].length();j++) {
                        if(!((str[i].charAt(j) >= '0' && str[i].charAt(j) <= '9'))) return "Neither";
                        if(str[i].charAt(j) == '0' && j == 0 && str[i].length() > 1) return "Neither";
                    }
                    int check = Integer.parseInt(str[i]);
                    if(check > 255) return "Neither";
                }
                return "IPv4";
            }
        }
        else {
            if(IP.charAt(IP.length() - 1) == ':') return "Neither";
            String[] six = IP.split("\\:");
            if(six.length < 8 || six.length > 8) return "Neither";
            for(int i = 0;i < six.length;i++) {
                if(six[i].length() > 4 || six[i].length() == 0) return "Neither";
                for(int j = 0;j < six[i].length();j++) {
                    if(!((six[i].charAt(j) >= '0' && six[i].charAt(j) <= '9') || (six[i].charAt(j) >= 'a' && six[i].charAt(j) <= 'f') || (six[i].charAt(j) >= 'A' && six[i].charAt(j) <= 'F'))) return "Neither";
                }
            }
            return "IPv6";
        }
    }
}
```
