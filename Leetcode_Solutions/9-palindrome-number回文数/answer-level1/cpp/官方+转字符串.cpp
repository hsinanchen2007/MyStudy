### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        // //官方答案
        // //负数和0结尾的数，都不行
        // if(x<0||x%10==0&&x!=0){ //与或关系最好加上括号，这里逻辑上都可以
        //     return false;
        // }

        // int r=0;
        // while(x>r){  //while判断是否翻转了一半以上
        //     r=10*r+x%10;
        //     x/=10;
        // }a
        // return x==r||x==r/10;  //返回这我真是想不到包括单双，而且直接就返回了！！


        //字符串写法
        if(x<0||x%10==0&&x!=0){ 
            return false;
        }
        char a[20];
        int end=0;
        int i = 0;
        while(x!=0){
            a[i++]=x%10;
            x=x/10;
        }
        end = i-1;
        for(i=0;(end-i)>=i;i++){//终止条件，循环一半
            //if(a[i]==a[end-i] && end!=(2*i)) continue;
            if(a[i]!=a[end-i]) return false;
            else  continue; //这里想了半天，走了一遍才想通
        }               //就是遍历，然后一旦不一样就return false，相同就不管。
        return true;


    }
};
```