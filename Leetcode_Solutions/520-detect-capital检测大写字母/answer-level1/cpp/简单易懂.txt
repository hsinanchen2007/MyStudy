### 解题思路
题目说正常使用大小写的情况有三种：
    1）全是大写
    2）全是小写
    3）除了第一个字母是大写之外其他全是小写

由于第三种情况，我们首先是需要判断单词最后一个字母是大写还是小写：
    i)  如果是大写，那我们只需要判断剩下的所有字母是不是都是大写即可
    ii）如果是小写，那我们只需要判断**除了第一个字母以外**剩下的所有字母是不是都是小写即可

### 代码

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        
        char ch=word[word.size()-1];
        
        int temp=0;
        if('A'<=ch && ch<='Z')
        {
            temp=1;
        }
        else if(ch>='a' && ch<='z')
        {
            temp=2;
        }
        
        for(int i=0;i<word.size()-1;i++)
        {
            if(temp==1)
            {
                if('a'<=word[i] && word[i]<='z')
                {
                    return false;
                }
            }
            else if(temp==2)
            {
                if('A'<=word[i] && word[i]<='Z' && i!=0)
                {
                    return false;
                }
            }
        }
        
        return true;

    }
};
```