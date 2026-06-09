lenth = len(s);
从len(s)开始遍历，如果s[i:i+lenth] == s[i:i+lenth][::-1]相等则为最长回文子串如果不等则lenth -= 1 ,直到找到位置。