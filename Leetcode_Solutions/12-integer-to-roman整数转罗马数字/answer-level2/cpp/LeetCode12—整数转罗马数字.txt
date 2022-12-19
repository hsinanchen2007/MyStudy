### 解题思路
执行用时 :8 ms,在所有 C++ 提交中击败了86.71%的用户
内存消耗 :6 MB, 在所有 C++ 提交中击败了100.00%的用户
按位分别转化，代码如下：
### 代码

```cpp
class Solution {
public:
    string intToRoman(int num) {
        string roman;   /*roman为转化的罗马数字*/
    int cnt=0,tmp=0;    /*cnt为标志位，1-4分别代表个、十、百、千位，tmp为每一位的值*/
    while(num){
        tmp=num%10;     /*取位*/
        ++cnt;          /*标志位，代表进位*/
        switch (cnt) {  /*switch() 语句判断当前位数，进行罗马数字转化*/
        case 1:
            if(tmp!=0){
                if(tmp>=1&&tmp<4)
                    roman=string(tmp,'I');
                if(tmp==4)
                    roman="IV";
                if(tmp>=5&&tmp<9)
                    roman="V"+string(tmp-5,'I');
                if(tmp==9)
                    roman="IX";
            }
            break;
        case 2:
            if(tmp!=0){
                if(tmp>=1&&tmp<4)
                    roman=string(tmp,'X')+roman;
                if(tmp==4)
                    roman="XL"+roman;
                if(tmp>=5&&tmp<9)
                    roman="L"+string(tmp-5,'X')+roman;
                if(tmp==9)
                    roman="XC"+roman;
            }
            break;
        case 3:
            if(tmp!=0){
                if(tmp>=1&&tmp<4)
                    roman=string(tmp,'C')+roman;
                if(tmp==4)
                    roman="CD"+roman;
                if(tmp>=5&&tmp<9)
                    roman="D"+string(tmp-5,'C')+roman;
                if(tmp==9)
                    roman="CM"+roman;
            }
            break;
        case 4:
            if(tmp!=0){
                roman=string(tmp,'M')+roman;
            }
            break;
        default:
            break;
        }
        num/=10;
    }
    return roman;
    }
};
```