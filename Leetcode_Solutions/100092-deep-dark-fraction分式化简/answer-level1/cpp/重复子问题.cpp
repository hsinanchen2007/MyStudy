可以观察发现，这个问题中除了最左边单独的整数，其他的分式都是固定的。其中每个重复的分式部分可以简化为1/(x+a/b) = b/(bx+a)。
```cpp
class Solution {
public:
    vector<int> count(vector<int>& cont){
        int index = cont.size() - 1;
        int a = 1, b = cont[index];
        
        for(int i = index - 1; i >= 1; i--){ // 循环迭代重复的部分
            int tmp = a;
            a = b;
            b = b * cont[i] + tmp;
        }
        
        return {a, b};
    }
    
    vector<int> fraction(vector<int>& cont) {
        if(cont.size() == 1){ // 当只有一项时
            return {cont[0], 1};
        }
        else{
            vector<int> right = count(cont);
            return {cont[0] * right[1] + right[0], right[1]};
        }
    }
};
```