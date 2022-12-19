# 计数法
1. 首先对字符串进行排序
2. 然后遍历整个字符串，将每个字符都和前一个进行比较
3. 如果和前一个不相等，则++num；相等则--num
4. 若num和字符串长度相等则返回true，反之flase


```
class Solution {
public:
    bool isUnique(string astr) {
        if(astr.size() == 0)
            return true;
        sort(astr.begin(), astr.end());
        int num = 1;
        char x = astr[0];
        for(int i = 1; i < astr.size(); i++){
            if(astr[i] != x){
                ++num;
                x = astr[i];
            }
            else
                --num;
        }
        return num == astr.size() ? true : false;
    }
};
```
