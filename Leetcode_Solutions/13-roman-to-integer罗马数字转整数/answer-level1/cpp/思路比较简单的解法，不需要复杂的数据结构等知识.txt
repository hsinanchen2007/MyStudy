### 解题思路
对于这道题其实不需要想的过于复杂，观察每个例子的特性，其实可以总结出一定规律  
对于每一位字符，都是有+-两种情况，而确定+-则是通过与它的下一位的比较情况：
* 当这一位字符代表的数比下一位小时，则减去当前这一位；
* 否则为加。

最后对字符串最后一位单独处理即可
（第一次写题解，可能不太详细，见谅）
### 代码
```cpp
class Solution {
public:
    int roman(char c)
    {
        switch(c)
        {
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
            default:return 0;
        }
    }
    int romanToInt(string s) {
        int temp1=0,temp2=0,temp=0;
        for(int i=0;i<s.size()-1;i++)
        {
            temp1=roman(s[i]);
            temp2=roman(s[i+1]);
            if(temp1<temp2) temp-=temp1;
            else temp+=temp1;
        }
        temp+=roman(s[s.size()-1]);
        return temp;
    }
};
```

执行用时 :4 ms, 在所有 C++ 提交中击败了98.86%的用户（也出现过0ms的情况）
内存消耗 :6.2 MB, 在所有 C++ 提交中击败了100.00%的用户 
另外问一下，为什么同样的代码，有的时候提交可以出现0ms的情况？？