第一反应是翻转字符串来做，思路是先将数字转化成一个string字符串，再判断该字符串是否合法。
```
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string s="";
        while(x) {
            s+=x%10;
            x/=10;
        }
        int size=s.size();
        for(int i=0;i<size/2;i++) //终止条件是字符串长度的一半，避免重复比较
        if(s[i]!=s[size-i-1])
        return false;
        return true;
    }
};
```
最后时间复杂度也比较可观，只用了4ms
![image.png](https://pic.leetcode-cn.com/0266a7904fcf61a4f4c48ef43d4a694ddda1fc184661631ea798476ab87a558b-image.png)

后来看官方题解，发现思路很好，理论上比翻转字符串的时间复杂度要好，而且空间上也不需要额外定义一个字符串，于是按照官方的思路打下了代码，结果耗时并不理想。
```
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x<10) return true;
        if(x%10==0) return false;
        int compare=0;
        while(x) {
            compare=compare*10+x%10;
            x/=10;
            cout<<compare<<" "<<x<<endl;
            if(compare==x||(compare==x/10)) return true;
            if(compare>x) return false;
        }
        return false;
    }
};
```
竟然用了60ms+，这可比翻转字符串长多了，经过一番冥思苦想，觉得大概是乘法有些耗费时间，于是把compare*10改成了位运算：
```
compare=(compare<<1)+(compare<<3)+x%10;
```
又运行了一遍，果然快了一些，到20ms+了。

仔细对比题解，又发现了一个问题。题解中的判断语句是写在while只外的，而我的程序每次循环都会执行两次冗余的if判断，自然耗时更多，所以，借鉴题解，最终把程序改成了这样：
```
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x<10) return true;
        if(x%10==0) return false;
        int compare=0;
        while(compare<x) {
            compare=(compare<<1)+(compare<<3)+x%10;
            x/=10;
        }
        return compare==x||compare/10==x;
    }
};
```
用时8ms，快多了（然而还是没字符串快，不知道什么原因）。
虽然感觉自己对用时有些钻牛角尖了，但是有个小收获，就是尽量不要在循环内写太多的if语句，当循环次数变多时可能会严重拖慢程序的速度。