```
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name == typed){
            return true;
        }
        int len = typed.size();
        int cnt = 0;
        for(int i = 0; i < len; i++){
            if(name[cnt] == typed[i]){
                cnt++;
                if(cnt == name.size()){
                    return true;
                }
            }
        }
        return false;
    }
};

```
![1.png](https://pic.leetcode-cn.com/b9d2a716b93f99592b7ac26e41f232724eb033d62327c2bfeed33306063505c5-1.png)

### 看了评论区一位大佬的建议，将代码修改如下
### 针对以下测试用例
"leon"
"lleoonnnfff"

```
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name.size() > typed.size()){
            return false;
        }
        if(name == typed){
            return true;
        }
        int len = typed.size();
        int cnt = 0;

        for(int i = 0; i < len; i++){
            if(name[cnt] == typed[i]){
                cnt++;
                if(cnt == name.size()){
                    i++;
                    while(i + 1 < len){
                        if(typed[i] != typed[i + 1]){
                            return false;
                        }
                        i++;
                    }
                    return true;
                }
            }
        }
        return false;
    }
};
```
![2.png](https://pic.leetcode-cn.com/3fb93fbebcfa2b40ed85d2fe7d9cdad607ab480a000c8127a471a5f1c14ce919-2.png)
