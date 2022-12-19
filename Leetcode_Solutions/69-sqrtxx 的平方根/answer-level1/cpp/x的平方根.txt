```
class Solution {
public:
    int mySqrt(int x) {
        int ret;
        //暴力解法要注意的地方就是 i 的定义一定要为long long 不能为int，把a 和 b 定义为longlong是不够的~
        //注意 0的开平方根是0 哦不要忘记，所以 i的值要从0 开始~
        for(long long i=0;i<INT_MAX;i++)
        {
            long long a=i*i;
            long long b=(i+1)*(i+1);
            if(a<=x && x<b)
            {
                ret=i;
                break;
            }
        }
        return ret;

    }
};
```
2020.1.8  饱读诗书小码农~
今天的第四道题~主要是为了补前两天没有完成的题目的数量的问题~
人就是不能懒呀~
这道题用的是暴力解法~
因为今天写太多的题目了~
明显再去实现二分查找法吧~
记录的是知识点有：
1. 数学知识：0的平方根是0哦
2. 为了防止溢出，int 可以变成longlong 类型


休息一下吧~晚安

