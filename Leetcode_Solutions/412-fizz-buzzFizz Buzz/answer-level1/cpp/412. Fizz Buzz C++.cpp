### 解题思路
1.判断是否是能够被3整除，若能则将Fizz加入ans，判断能否能够被5整除，若能则将Buzz加入ans。
2.判断若既不能被3整除，也不能被5整除则将数字转换成string类型。
3.循环判断并不断将ans压入result再清除ans中的字符串。

### 代码

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
            vector<string> result;
    string answer = "";

    for(int i = 1; i <= n;i++){
        if(i % 3 == 0){
            answer += "Fizz";
        }

        if(i % 5 == 0){
            answer += "Buzz";
        }

        if(i % 3 != 0 && i % 5 != 0){
            answer = to_string(i);
        }

        result.push_back(answer);
        answer = "";
    }

    return result;
    }
};
```