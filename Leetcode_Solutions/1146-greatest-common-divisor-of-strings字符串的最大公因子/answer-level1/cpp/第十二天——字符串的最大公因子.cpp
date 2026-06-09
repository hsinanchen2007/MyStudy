### 解题思路
![image.png](https://pic.leetcode-cn.com/5d70151e7b1921ee322e526d3201b3a884c0ad698c27fa7a2098b73fc53dd4eb-image.png)

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int M = str1.size();
        int N = str2.size();
        int n = N;
        int flag = 0;  //标记位
        string res;

        while(n >= 1){
            if((!(M%n)) && (!(N%n))){  //(!(M%n)) 不等于!M%n，优先级问题
                flag = 0;
                res = str2.substr(0, n);
                for(int i = 0; i < N/n; i++)
                    if(str2.substr(i*n, n) != res) flag++;
                for(int i = 0; i < M/n; i++)
                    if(str1.substr(i*n, n) != res) flag++;
                if(!flag) return res;
            }
            n--;
        }
        return "";
    }
};
```

