### 解题思路
此处撰写解题思路
不能包含：3，4，7
可能包含：0，1，8
一定包含至少一个：2，5，6，9
### 代码

```cpp
class Solution {
public:
    int rotatedDigits(int N) {
        
        int num = 0;
        for(int i = 1; i<=N;++i)
        {
            string str = to_string(i);
            bool flag = false;
            for(auto & ch: str)
            {  
                if(ch=='2'||ch=='5'||ch=='6'||ch=='9')
                {
                    flag = true;
                }
                if(ch=='4'||ch=='7'||ch=='3'){
                    flag = false;
                    break;
                }
                    

            } 
            if(flag==true)
               num++;       
        }
        return num;
    }
};
```