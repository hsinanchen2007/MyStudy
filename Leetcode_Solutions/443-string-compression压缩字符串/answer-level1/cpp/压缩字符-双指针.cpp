
遍历字符串，记录新出现字符的次数，1和大于1的区别（注意大于9的情况），最后一个字符特殊处理。用len记录修改后字符串的长度，原则改一个字符len加1.


    int compress(vector<char>& chars) {
        if (chars.size() <= 1)
            return chars.size();
        int j = 0;
        chars[j] = chars[0];
        int len = 1;
        char temp = chars[0];
        int n = 1;
        for(int i = 1; i < chars.size(); i++)
        {
            if(chars[i] == temp)
                n++;
            else if(chars[i] != temp && n > 1)
            {
                j++;
                if(n<10)
                {
                    chars[j++] = n + '0';
                    len++;
                }
                    
                else
                {
                    chars[j++] = n/10 + '0';
                    len++;
                    chars[j++] = n%10 + '0';
                    len++;
                }
                n = 1;
                temp = chars[i];
                chars[j] = temp;
                len++;
            }
            else if(chars[i] != temp && n == 1)
            {
                temp  = chars[i];
                chars[++j] = temp;
                len++;
            }
            if(i == chars.size() -1 && n > 1) 
            {
                j++;
                if(n<10)
                {
                    chars[j++] = n + '0';
                    len++;
                }
                else
                {
                    chars[j++] = n/10 + '0';
                    len++;
                    chars[j++] = n%10 + '0';
                    len++;
                }
            }
        }
        return len;
    }