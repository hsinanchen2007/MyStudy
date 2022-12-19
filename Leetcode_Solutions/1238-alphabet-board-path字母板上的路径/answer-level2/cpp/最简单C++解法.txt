这道题着实很坑，一开始思路是想着每次找到一个字母就更新这个字母，然后再将下一个字母与当前字母比较，结果发现这样情况会特别多，根本判断不过来

后面发现其实可以每个字母只与'a'这个字母去比较，来判断当前字母相对于上一个
字母的偏移量来判定应该怎么走，这样就方便很多
这个题应该还有一个坑是'z'这个字母，如果目标字母中含有'z'，我们应该先横向走，再纵向走，其余
情况都可以先纵向走，再横向走
怎么判断要怎么走呢？用当前字母比如('l'-'a')%5 即可判断它在board中的横坐标，('l'-'a')/5可判断纵坐标
然后将当前的横纵坐标与之前一个字母的横纵坐标比较，即可得偏移量，初始时字母为a(0,0),之后不断更新其的横纵坐标
![批注 2020-04-02 143005.png](https://pic.leetcode-cn.com/8b5f6372920e31d940c4131bf0696acea3e43849f15ba79d7c341ed3b46ec594-%E6%89%B9%E6%B3%A8%202020-04-02%20143005.png)


```cpp
class Solution {
public:
    string alphabetBoardPath(string target) {
        string res;
        int posX = 0,posY = 0;
        for(int i =0;i<target.size();++i){
            int x = (target[i] - 'a')%5;
            int y = (target[i] - 'a')/5;
            int tmpX = x,tmpY = y;  //保存当前target[i]在board中的x,y坐标
            x-=posX;
            y-=posY;
            if(target[i]=='z')
            {
                while(x<0)
                {
                    res+='L';
                    ++x;
                }
                while(y>0)
                {
                    res+='D';
                    --y;
                }
                res+='!';  
            }
            else
            {
                while(y>0)
                {
                    res+='D';
                    --y;
                }
                while(y<0)
                {
                    res+='U';
                    ++y;
                }
                while(x>0)
                {
                    res+='R';
                    --x;
                }
                while(x<0)
                {
                    res+='L';
                    ++x;
                }
                res+='!';  //找完后记得加'!'
            }
            posX = tmpX;
            posY = tmpY;
        }
        return res;
    }
};
```