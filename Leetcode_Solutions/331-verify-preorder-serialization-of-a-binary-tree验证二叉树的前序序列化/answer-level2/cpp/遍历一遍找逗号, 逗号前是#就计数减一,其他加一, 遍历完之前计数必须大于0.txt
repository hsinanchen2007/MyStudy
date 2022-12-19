字符串最后一个字符是'\0', 不是'#', 要特别处理一下
```
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int count = 1;
        for(int i = 0; i < preorder.length(); i++){
            if(preorder[i+1] == ',' || preorder[i+1] == 0){
                if(preorder[i] == '#'){
                    count--;
                    if(count == 0 && i != preorder.length()-1)
                        return false;
                }else{ 
                    count++;
                }
            }
        }
        return count == 0;
    }
};
```
