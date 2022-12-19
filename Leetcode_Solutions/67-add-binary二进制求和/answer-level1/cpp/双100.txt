### 解题思路
先对两字符串相同长度的部分按条件进行运算，用save存起来。
当短的字符串运算完的时候，在对长的字符串剩余的部分与进位cf运算。
全部运算完毕后，反转save，就是结果。
代码写得很繁琐，`ai == -1 && bi == -1`这个情况是两字符串同长，直接当特殊情况拎出来了。
肯定能精简的，思路就是上面这样

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string result, save;
        int cf = 0;
        int ai = a.length() - 1;
        int bi = b.length() - 1;
        while(ai >= 0 && bi >= 0)
        {
            if(a[ai] == '1' && b[bi] == '1')
            {
                if(cf) save.append("1");
                if(!cf) save.append("0");
                cf = 1;
            }
            else if(a[ai] == '0' && b[bi] == '0')
            {
                if(cf) save.append("1");
                if(!cf) save.append("0");
                cf = 0;
            }
            else
            {
                if(cf)
                {
                    save.append("0");
                    cf = 1;
                } 
                if(!cf)
                {
                    save.append("1");
                    cf = 0;
                } 
            }
            ai--;
            bi--;
        }


        if(ai == -1 && bi == -1)
        {
            if(cf)
            {
                save.append("1");
            }
        }

        if(ai == -1 && bi != -1)
        {
            while(cf && bi >= 0)
            {
                if(b[bi] == '1') 
                {
                    save.append("0");
                    cf = 1;
                }
                if(b[bi] == '0')
                {
                    save.append("1");
                    cf = 0;
                }
                bi--;
            }
            
            if(bi >= 0) 
            {
                for(int i = bi; i >= 0; i--) save.append(1, b[i]);
            }
            if(cf)
            {
                save.append("1");
            }
        }
        if(ai != -1 && bi == -1)
        {
            while(cf && ai >= 0)
            {
                if(a[ai] == '1') 
                {
                    save.append("0");
                    cf = 1;
                }
                if(a[ai] == '0')
                {
                    save.append("1");
                    cf = 0;
                }
                ai--;
            }
            
            if(ai >= 0) 
            {
                for(int i = ai; i >= 0; i--) save.append(1, a[i]);
            }
            if(cf)
            {
                save.append("1");
            }
        }

        reverse(save.begin(),save.end());

        return save;
    }
};
```