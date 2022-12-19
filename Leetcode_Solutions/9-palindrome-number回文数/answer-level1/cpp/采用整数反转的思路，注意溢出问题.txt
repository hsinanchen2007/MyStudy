### 解题思路一
和整数反转是一个思路，最重要的是要判断是否溢出的问题
同时可以对特例进行判断加快整个判断的过程

### 代码

```cpp
#define MAX_INT 2147483647

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x>0 && !x%10) return false;
        int x_ = x;
        int res=0;
        while(x){
            if(res==MAX_INT/10 && x%10>MAX_INT%10) return false;
            if(res>MAX_INT/10) return false;
            res = res*10 + x%10;
            x=x/10;
        }
        cout << res << endl;
        if(x_==res) return true;
        else return false;
    }
};
```

### 解题思路二
关注回文本身的特点，回文最重要的就是对称，所以如果要解决溢出问题其实还可以只使用输入数的一半，从数字第一位开始到一半的位置得到的数和从数字最后一位开始反相到中间位置得到的数相比较，判断是否一致
这里不需要确切地通过计算这个数的位数找到中间位置，只需要比较x/10和反转后的结果的大小关系即可。