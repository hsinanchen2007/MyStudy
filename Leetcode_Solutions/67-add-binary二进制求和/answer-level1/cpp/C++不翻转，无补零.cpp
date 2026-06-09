### 解题思路
为了保证addBinary的第一参数字符串长于第二参数字符串，采用了`return addBinary(b,a);`交换参数位置，使第一参数字符串长度始终更大。

设定两个变量i，j。分别表示a，b两个字符串的下标。i，j均从字符串尾向前遍历，直到更短的字符串遍历完成。而后遍历更长的字符串的剩余部分，直到长字符串也遍历完成。
    
遍历中的操作为位与位的加。需要注意两点：
- 字符串中的每一位都是char类型，是字符。'1'+'1'的结果是按照对应的ASCII码值来计算的，已知'1'对应十进制数为49，则'1'+'1'的结果为98，转换成字符则为'b'。于是在计算位相加结果时，用`a[i] - '0' +b[j]`这种形式（'1'-'0' == 1）。且判断位与位相加是否产生进位时，应写成这种形式：`a[i] >= '2'`。
- 进位标志carry。无进位时，记得把carry置零。
    
遍历结束后，判断最高位是否有进位，若有，需在字符串最前方添加字符'1'。

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        //默认a.size() > b.size()
        if(a.size() < b.size()){
            return addBinary(b,a);
        }
        int i = a.size() - 1;//是string a的下标
        int j = b.size() - 1;//是string b的下标
        int carry = 0;
        for( ; j >= 0; i--, j--){
            a[i] = a[i] - '0' +b[j] + carry;//把结果放在a中            
            if(a[i] >= '2'){
                a[i] -= 2;       
                carry = 1;
            }
            else{
                carry = 0;
            }
        }
        if(carry == 0) return a;
        while(i+1 != 0){
            a[i] += carry;
            if(a[i] >= '2'){
                a[i] -=2;
                carry = 1;
            }
            else{
                carry = 0;
            }
            i--;
        }
        if(carry == 1){
            a = '1' + a;
        }
        return a;
    }
};
```