
# 状态机法

可以将单词状态设为1，其他状态视作0；
从状态1转换到状态0时，单词计数加一。
到末尾时，末尾视作状态0。

```c++
class Solution {
public:
    int countSegments(string s) {
        int last_status = 0; // 0= other , 1= alpha;
        int count = 0;

        for(auto c: s){
            int cur_status = !isspace(c);
            if((!cur_status) && last_status) count++;
            last_status = cur_status;

        }
        if(last_status) count++;
        return  count;

    }
};
```