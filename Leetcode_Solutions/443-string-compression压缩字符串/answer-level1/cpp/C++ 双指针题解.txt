
```
class Solution {
public:
    
    // i表示写入数组的index   j 表示探测数组的 index
    
    int compress(vector<char>& chars) {
        if(chars.size() == 0)
            return 0;
        int i=0, j=0;
        char comp = chars[j];
        int cnt = 0;
        while(j < chars.size())
        { 
            if( chars[j] == comp )
            {
                j++;
                cnt++;
                if(j < chars.size())
                    continue;
            }
            chars[i] = comp;
            i++;
            if(j < chars.size())
                comp = chars[j];
            if(cnt == 1);
            else if(cnt > 9)
            {
                if(cnt > 9 && cnt < 100)
                {
                    chars[i++] = cnt /10 % 10 + '0';
                    chars[i++] = cnt % 10 + '0';
                }
                else if(cnt > 99 && cnt < 1000)
                {
                    chars[i++] = cnt /100 % 10 + '0';
                    chars[i++] = cnt /10 % 10 + '0';
                    chars[i++] = cnt % 10 + '0';
                }
                else
                {
                    chars[i++] = cnt /1000 % 10 + '0';
                    chars[i++] = cnt /100 % 10 + '0';
                    chars[i++] = cnt /10 % 10 + '0';
                    chars[i++] = cnt % 10 + '0';
                }
            }
            else
            {
                chars[i++] = cnt + '0';
            }
            cnt = 0;
        }
        return i;
        
    }
};
```
