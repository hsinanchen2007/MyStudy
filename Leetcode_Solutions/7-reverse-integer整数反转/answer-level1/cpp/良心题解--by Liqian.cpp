链接：[https://leetcode-cn.com/problems/reverse-integer/solution/liang-xin-ti-jie-by-liqian-by-li-gan-2/]()
## 这个是0ms代码，击败100%用户！！！
![傲游截图20191105125954.png](https://pic.leetcode-cn.com/a88392aa807d43ff05fd0a2fa6fdf008a1aff3b1d39ae310f19d64644f14fe01-%E5%82%B2%E6%B8%B8%E6%88%AA%E5%9B%BE20191105125954.png)
![傲游截图20191105125911.png](https://pic.leetcode-cn.com/2b472f81570ec9b67563f72b8c1a193ce210c245a14ed079266f9390aeef5b57-%E5%82%B2%E6%B8%B8%E6%88%AA%E5%9B%BE20191105125911.png)
```cpp
class Solution {
public:
    int reverse(int x) 
    {
        if(x==INT_MIN) return 0 ;
        int f=1 ;
        if(x<0) f=-1 ;
        x=abs(x) ;
        //基本处理+特判
        string str=to_string(x) ;
        //reverse
        for(int i=0,j=str.size()-1;i<j;i++,j--)
                swap(str[i],str[j]) ;
        long long ans=0 ;
        //累加
        for(auto s:str)
            ans=ans*10+s-'0' ;
        //收尾
        if(ans>INT_MAX) return 0 ;
        else return (int)ans*f ;
        //else不加会慢
    }
};
```
心得：
需要熟练的掌握STL的各种函数
主要使用string，熟练掌握+特判=AC
最不爽的是用不了STL的reverse函数

------------------------------

*Goodbye！！*