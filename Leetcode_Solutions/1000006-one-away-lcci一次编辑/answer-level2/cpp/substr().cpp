1. 直接判断两字符串是否相等
2. 当两个字符串长度相等时，分别去掉各串中的一个元素看是否相等
3. 当a串比b串长度长1,就一次去掉a串中的一个元素看是否相等
4. 当b串比a串长度长1,就一次去掉b串中的一个元素看是否相等
5. 其他情况就不符合直接返回false

```
    string a=first.substr(0,i);
    string b=first.substr(i+1,first.size()-i-1);
    string c=a+b;
```
以上代码作用就是去掉first中的一个字符

```
class Solution {
public:
    bool oneEditAway(string first, string second) {
        if(first==second) 
        {
            return true;
        }
        if(first.size()==second.size())
        {
            for(int i=0;i<first.size();i++)
            {
                string a=first.substr(0,i);
                string b=first.substr(i+1,first.size()-i-1);
                string c=second.substr(0,i);
                string d=second.substr(i+1,second.size()-i-1);
                if(a+b==c+d)
                {
                    return true;
                }
            }
        }
        else if(first.size()==second.size()+1)
        {
            for(int i=0;i<first.size();i++)
            {
                string a=first.substr(0,i);
                string b=first.substr(i+1,first.size()-i-1);
                if(a+b==second)
                {
                    return true;
                }
            }
        }
        else if(first.size()==second.size()-1)
        {
            for(int i=0;i<second.size();i++)
            {
                string a=second.substr(0,i);
                string b=second.substr(i+1,second.size()-i-1);
                if(a+b==first)
                {
                    return true;
                }
            }
        }
        else
        {
            return false;
        }
        return false;
    }
};
```
