这道题因为只需要判断是否可以构成有效的括号，并不需要列举出合法的解。
可以直接遍历一遍字符串，记录出现的括号和*的情况。
```
class Solution {
public:
    bool checkValidString(string s) {
        vector<int>left,star;//left和star分别记录出现的"("和"*"出现的index。
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') left.push_back(i);
            else if(s[i]=='*') star.push_back(i);
            else{
                //当出现")"的时候,先判断left中是否有元素，有就直接pop，否则的话看看star里面是否有元素
                //如果都没有，那么就说明")"比"("和"*"都多，是非法解，返回false
                if(left.size()>0) left.pop_back();
                else if(star.size()>0) star.pop_back();
                else return false;
            }
        }
        //最后来判断"("是否合法，如果left的数量大于star，一定不合法，return false
        if(left.size()>star.size()) return false;
        //不然的话，就需要满足，对于任何一个左括号，它的右边必须至少有一个星号
        //所以从后往前看，如果有一个左括号的右边没有星号，也就是star.back()<left.back() 就不合法
        for(int i=left.size()-1;i>=0;i--){
            if(star.back()<left.back()) return false;
            star.pop_back();
            left.pop_back();
        }
        return true;
    }
};
```
![截屏2020-03-2717.05.35.png](https://pic.leetcode-cn.com/e7f5665af58ac43a3de8cd37ed5e1853c5638d42e74eace87d22a9412c01b3ab-%E6%88%AA%E5%B1%8F2020-03-2717.05.35.png)

