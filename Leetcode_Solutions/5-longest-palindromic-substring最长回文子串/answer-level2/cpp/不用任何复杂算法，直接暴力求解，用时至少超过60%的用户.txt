### 解题思路
//滑动窗，从头到尾遍历字符串，遍历一遍后滑动窗尺寸扩大1。
//假设滑动窗尺寸为n，如果在n的条件下，字符串遍历不存在回文串，此时存在两种情况如下：
// 1、n为偶数，则不存在大于n的偶数的回文串，则使之后滑动窗的尺寸始终为奇数。
// 2、n为奇数，则不存在大于n的奇数的回文串，则使之后滑动窗的尺寸始终未偶数。
### 代码

```cpp
class Solution {
public:
    char TorF_huiwen(string str)  //函数：判断是否是回文子串
    {
        int i=0,j=str.size()-1;
        while(i<j)
        {
            if(str[i]==str[j])
            {i++;
            j--;}
            else 
            return 'F';
        }
        return 'T';
    }
    string longestPalindrome(string s) {
        if(s.empty()) //空则返回空
        return "";
        if(s.size()==1)  //一个则返回本身
        return s;
        if(s.size()==2)  //两个判断是否回文
        {
            if(s[0]==s[1])
            return s;
            else return s.substr(0,1);
        }
        int len = 2,flag1=0,flag2=0;//裁剪长度
        string str1;
        while(len<=s.size())    //当字符串长度大于2时
        {
            int beg = 0;
            while(beg<=s.size()-len)
            {
                //判断是否为回文子串
                if(TorF_huiwen(s.substr(beg,len))=='T') ///是回文子串
                {
                    str1 = s.substr(beg,len);
                    break;
                }
                else
                {
                    beg++;
                }
            }
            int temp_len = len;
            if(temp_len%2==0&&str1.size()!=temp_len)//没有偶数的回文字符串
            {
                len--;//len只能为奇数了。
                flag1=1;
            }
            if(temp_len%2!=0&&str1.size()!=temp_len)//没有奇数的回文字符串
            {
                len--;//len只能为偶数了。
                flag2=1;
            }
            if(flag1==1&&flag2==1)
            {
                if(str1.empty())
                return s.substr(0,1);
                else 
                return str1;
            }
            if(flag1==1||flag2==1)//排除奇数、偶数其中一种，使len只能为偶数或奇数
            len+=2;
            else 
            len++;
        }
        return str1;
    }

};
```