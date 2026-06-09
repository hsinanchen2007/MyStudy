### 解题思路
这种题目和原站的233题相同，不过那个是hard，这个是medium，不知道为啥。
感觉就是找好规律了，从低位往高位走，就可以了。

### 代码

```cpp
class Solution {
public:
    //这个题目就是一个找规律的题目
    int countDigitOne(int n) {
        long current_index = 0;
        //上一次的结果
        long last_num = 1;
        //剩余的数字，主要处理为1的时候的情况
        int rest_num = 0;
        int count = 0;
        while(n != 0){
            int num = n % 10;
            //当为1的时候
            if(num == 1) count = count + (num * current_index + rest_num + 1);
            else if (num > 1) count = count + (num * current_index + last_num);
            rest_num = rest_num + num * last_num;
            current_index = 10 * current_index + last_num;
            last_num = last_num * 10;
            n = n / 10;
        }
        return count;
    }
};
```