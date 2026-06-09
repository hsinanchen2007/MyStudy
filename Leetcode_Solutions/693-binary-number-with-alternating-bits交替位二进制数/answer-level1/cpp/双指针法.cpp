执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.9 MB, 在所有 C++ 提交中击败了92.57%的用户

```
class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int temp1,temp2 = -1;
        
        while(n>0){//将十进制n转为二进制
            
            temp1 = n%2;//指针1指向下二进制的下一位数
            
            if(temp1 == temp2)//两个指针不相等时候返回false
                return false;
            temp2 = temp1;//指针2指向指针1

            n=n/2;
        }
        
        return true;
    }
};
```
