### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.6 MB, 在所有 C++ 提交中击败了100.00%的用户


递归，代码很简单的样子。
### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {

        if(1 == n )  
            return "1";
        else
            return convert(countAndSay(n-1));

    
    
    return "err";
    }

    string convert(string str){
        int i = 0;
        int count = 1;
        char number =0;
        string new_str;

        while( i < (int)(str.size()) ){
            number = str[i];
            while(str[i+1] == number){
                count++;
                i = i+1;
            }
            //发生转变，保存记录
            new_str += (char)(count+48);
            new_str += (char)(number);

        
            //重新计数
            count = 1;
            i++;

        }
    return new_str;
    }
};


```