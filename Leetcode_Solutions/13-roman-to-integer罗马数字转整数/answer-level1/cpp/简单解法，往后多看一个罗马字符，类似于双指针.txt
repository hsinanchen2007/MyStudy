本题有两种情况：
    第一种情况是前面的罗马数字一直大于等于后面的罗马数字，这是最简单的情况，一直往后加就行。
    第二种情况是会出现前面的数字小于后面罗马数字的情况，这样的话，需要后面的罗马数字前去前面的罗马数字再与总和相加。
    针对这二种情况。我们只需要在计算求和时，通过保留本次罗马字符的方法，在下一次对总和进行修改时，将罗马字符与保留的上一次罗马字符进行比较，如果本次罗马字符大于保留的罗马字符，直接在总和上加上该罗马字符数值，如果小于保留的罗马字符，则需要用当前罗马字符减去保留的罗马字符再加到综合上去。因为之前在统计的时候，已经加了一遍现在保存的罗马数字，所以要减去两遍的当前保存的数字。

```
class Solution {
public:
    int romanToInt(string s) {
        if (s.length() == 0)
            return 0;
        int ans = 0, cnum = 0, pnum = getchar(s[0]);
        ans = pnum;
        for (int i = 1; i < s.length(); ++i){
            cnum = getchar(s[i]);
            if (cnum > pnum)
                ans = ans + cnum - pnum - pnum;
            else
                ans = ans + cnum;
            pnum = cnum;
        }
        return ans;
    }
private:
    int getchar(char Roman){
        switch(Roman){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};
```
