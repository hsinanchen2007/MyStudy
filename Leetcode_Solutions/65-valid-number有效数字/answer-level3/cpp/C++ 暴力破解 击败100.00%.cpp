### 解题思路
此处撰写解题思路
直白进行暴力破解，需要注意的就是在首先去除两侧可能出现的干扰空格，然后就简单了起来，符合数学规律的符号其实就只有那么几个而已，只要不属于对应符号就可以直接false,再就是一些细节，比如符合数学规律的符号其允许的出现次数，以及对应的出现顺序，在列出几项特殊情况进行规避就可以得到结果，虽然不是巧妙算法但是时间复杂度其实并不高。
![QQ截图20200214002906.png](https://pic.leetcode-cn.com/8949f07f0dc001c6db35178251ccfe1bbe53fdd89e0fea40dc21563bc7a56aef-QQ%E6%88%AA%E5%9B%BE20200214002906.png)
### 代码

```cpp
class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        if(n == 0)
            return false;
        int i = 0;
        int count = 0;//+-的个数
        int countpoint = 0;//.的个数
        int counte = 0;//e的个数
        bool swit = true;//.在如今情况下是否可以存在于数字中
        bool swit1 = true;//+-在如今情况下是否可以存在于数字中
        bool swit2 = false;//e在如今情况下是否可以存在于数字中
        while(s[i] == ' '){
            i++;
        }
        while(s[n-1] == ' '){
            n--;
        }
        if(i == n-1)
            if(s[i] == '.' || s[i] == 'e')
                return false;
        if(i+1 < n && (s[i] == '.' && s[i+1] == 'e'))//规避'.e'
            return false;
        if(i == n-2 && (s[i] == '-' && s[i+1] == '.'))//规避'-.'
            return false;
        if(s[i] == 'e' || i >= n || s[n-1] =='+' || s[n-1] == '-' )
            return false;
        while(i < n){
            switch(s[i]){
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    swit2 = true;
                    swit1 = false;
                    break;
                case '+':
                    if(!swit1)
                        return false;
                    count++;
                    if(count == 2)
                        return false;
                    break;
                case '-':
                    if(!swit1)
                        return false;
                    count++;
                    if(count == 2)
                        return false;
                    break;
                case 'e':
                    if(!swit2)
                        return false;
                    swit1 = true;
                    count = 0;
                    counte++;
                    if(n == i+1 || counte > 1)
                        return false;
                    swit = false;
                    break;
                case '.':
                    if(!swit)
                        return false;
                    swit1 = false;
                    countpoint++;
                    if(countpoint > 1)
                        return false;
                    break;
                default:
                    return false;
            }
            i++;
        }
        return true;
    }
};
```