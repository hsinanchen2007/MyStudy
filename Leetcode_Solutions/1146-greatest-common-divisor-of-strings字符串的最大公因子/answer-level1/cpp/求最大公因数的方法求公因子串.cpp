### 解题思路
2个步骤：
    1. 证明有公因子串 ==》长串的依次每个字符，在短串中都能循环对应
        如 ABABAB
           ABAB   （短的串到尾以后回到头==》循环对应）
    2. 两个有公因子串的字符串： n*str和，m*str （str为公因子串，长度为x）
        那么， 2个字符串的长度的公约数 == n和m的公约数*str
        而公因子串在任何一个字符串的前 (n,m)*str.size（）个
        简单的说 连个字符串的size（）的公约数就是公因子串的长度L。
        取任何一个字符串的前L个字符就是了（题目“除尽”的含义就是这样的）
### 代码

```cpp

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
       string::iterator pLess = str1.begin();
       string::iterator pMore = str2.begin();
        int sizeMore = str2.size(), sizeLess = str1.size();
        if (sizeLess ==0 || sizeMore == 0)
            return "";

       if (str1.size() > str2.size()){
           pLess = str2.begin();
           pMore = str1.begin();
           sizeLess = str2.size();
           sizeMore = str1.size();
       }

        int j = 0;
       for (int i=0; i<sizeMore; i++, j++){
            j %= sizeLess;
           if (pMore[i] != pLess[j]){
               return "";
           }
       }
        // 确认有 公因子串
        int A = str1.size(), B = str2.size(), yu;

        do{
            yu = A % B;
            A = B;
            B = yu;
        }while (B != 0);

      
       return str1.substr(0, A);
    }

  
};
```