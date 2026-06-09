### 思路
1. 观察规律，给的数都是大写字母，A对应1，因此写个getNum()函数处理单个字母变成数字的问题
2. 一连串的字母呢，发现AA就是26* 1+1=27，ZY就是26 *  26+25=701，每一位都是本身数字乘上26的幂次方
3. 发现规律，代码如下

### 代码
```
    int getNum(char c)
    {
        return 1+c-'A';
    }

    int titleToNumber(string s) {
        int ret=0;
        int len=s.size();
        for(int i=len-1;i>=0;--i)
        {
            ret+=getNum(s[i])*pow(26,len-1-i);
        }
        return ret;
    }
```
### 运行结果
![image.png](https://pic.leetcode-cn.com/11c6fd9796e627a6f685861b369a1c5359e52196dee7e0b41990c3dca1c46e49-image.png)
