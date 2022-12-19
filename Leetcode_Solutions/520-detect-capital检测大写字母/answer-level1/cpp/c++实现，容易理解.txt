### 解题思路
正确的用法只用三种，所以这里我的思路是：定义一个变量统计大写字母的个数，初始为0，每增加一个大写字母就+1，先判断第一个字符是不是大写的，如果第一个是大写的，那么看剩余的字符是不是大写，统计次数，如果全是或者只有第一个是那就是正确的，即num==(word.size())||num==1  return true。然后如果第一个是小写的，那就看是不是全小写，只有当num==0的时候才是正确的。
![image.png](https://pic.leetcode-cn.com/f9248f6b6d1c3c53ce231ba2868e6bacae4437edb3714444164f09863155b90c-image.png)


### 代码

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        int num=0;
        char c1=word[0];

        if(c1>='A'&&c1<='Z')
        {    num=num+1;
             for(int i=1;i<word.size();i++)
             {
                 if(word[i]>='A'&& word[i]<='Z')
                 {
                     num++;
                 }
             }
             if(num==(word.size())||num==1)
             {
                 return true;
             }
             else
             {
                 return false;
             }
        }
        else
        {
             for(int i=1;i<word.size();i++)
             {
                 if(word[i]>='A'&& word[i]<='Z')
                 {
                     num++;
                 }
             }
            if(num==0)
            {return true;}
            else
            {return false;}
        }
        

    }
};
```