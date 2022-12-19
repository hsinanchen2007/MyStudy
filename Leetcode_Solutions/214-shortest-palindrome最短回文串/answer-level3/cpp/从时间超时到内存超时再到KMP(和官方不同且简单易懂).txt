
- 超内存版本

```
//超出内存限制
// class Solution {
// public:
//     string shortestPalindrome(string s) {
//         string t(s);
//         int length=s.size();
//         reverse(t.begin(),t.end());
//         for (int i = 0; i < length; i++) {
//             if (s.substr(0, length - i) == t.substr(i))
//                 return t.substr(0, i) + s;
//         }
//         return "";
//     }
// };
```

- 超时间版本
```

//超出时间限制
// class Solution {
// public:
//     bool isPalindrome(string &s,int right){
//         int left=0;
//         while(left<right){
//             if(s[left++]!=s[right--])return false;
//         }
//         return true;
//     }
//     string shortestPalindrome(string s) {
//         //找到以第一个字母开头的最长回文串
//         int index=0;
//         string res="";
//         for(int i=s.size()-1;i>=0;i--){
//             if(s[i]==s[0] && isPalindrome(s,i)){
//                 index=i;
//                 break;
//             }
//             res+=s[i];
//         }
//         res+=s;
//         return res;
//     }
// };
```
- KMP
先安利一个我认为讲的最好的`kmp`算法的链接[kmp](https://www.zhihu.com/question/21923021/answer/281346746)，一定要多看几遍，多看几遍，多看几遍。

#### 自己的kmp：

自己也看了官方的`kmp`，够精简，然而看不太懂（更准确地说是想不到），不过自己写的这个就是套模板（模板删三行代码就ok）。
`kmp`利用next数组，`next`里边存放的是字符串的前缀集合与后缀集合的交集中最长元素的长度，而本题不就是求出以字符串开头的最长回文，然后后续字母反转加上原字符串不就好了么？

可是我们如何得知字符串从哪里开始就不是回文了呢。受上述两个未通过的版本启发，我们可以将字符串反转然后与源字符串比较：
- 将原字符s串作为模式串，反转之后的串t作为待匹配串，
- 由于两个串长度是一样的，所以无论如何当t串走完之后，s要么也走完，要么走不完，
- 走不完的话，剩下的串就是我们要反转的。
这样我们的`kmp`算法就到此结束了。
- 以`"aacecaaa"`为例：
```
t：	a	a	a	c	e	c	a	a	
s：		a	a	c	e	c	a	a	a

```
就像这样，s后边还有一个字符未匹配上，所以应该截取的长度为1

- 再如`"abababca"`

```
a	c	b	a	b	a	b	a			
			a	b	a	b	a	b	c	a

```
走到最后还有三个没有匹配，所以要返回的长度是3


```
- KMP
//KMP
class Solution {
public:
    void get_next(string &t, vector<int>& next){
        int i=0,j=-1;
        next[i]=j;
        while(i<t.size()){
            if(j==-1 || t[i]==t[j]){
                i++;
                j++;
                next[i]=j;
            }else{
                j=next[j];
            }
        }
    }
    int KMP(string& s, string& t, vector<int>& next,int length)
    {
        int i = 0;
        int j = 0;
        while(i<length && j<length)
        {
            if(j==-1||s[i]==t[j]){
                i++;
                j++;
            }
            else
                j = next[j];
        }
        return i-j;//返回需要截取字符串的长度
     }
    string shortestPalindrome(string s) {
        int length=s.size();
        string ss(s);
        reverse(ss.begin(),ss.end());
        vector<int>next(length+1);
        get_next(s,next);
        return ss.substr(0,KMP(ss,s,next,length))+s;//反转的字符串截取前n个接上s
    }
};
```
个人网站，欢迎大家戳进去看看啊：[李一平](https://liyiping.cn/)