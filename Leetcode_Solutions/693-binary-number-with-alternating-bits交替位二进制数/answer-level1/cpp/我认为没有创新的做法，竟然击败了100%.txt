### 解题思路
就是判断

![image.png](https://pic.leetcode-cn.com/c32a66c6c556cb08a42206f76a1b8b172294d22efcd49ae158cdb80c4edcb280-image.png)




### 代码

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
       int flag = n&1;
      
        bool B ;
       if(flag == 0){
           B = false;
       }
       else{
           B = true;
       }
      
       while(n){    
           if(B == true){
               int temp = n&1;
               cout<<n<<endl;
               if(temp != 1) return false;
               B = false;
               n >>= 1;
           }
            if(B == false){
                cout<<n<<endl;
                int temp = n&1;
                cout<<temp;
                if(temp != 0) return false;
                B = true;
                n >>= 1;
            }
       } 
       return true;
    }
};
```