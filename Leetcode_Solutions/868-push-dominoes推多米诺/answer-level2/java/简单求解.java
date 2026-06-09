### 解题思路
简单求解，没有官方思路那么巧妙，所以情况分得比较多。时间复杂度与空间复杂度都是O（N）

### 代码

```java
class Solution {
    public String pushDominoes(String dominoes) {
        char[] chars = dominoes.toCharArray();
        int l, k = 0, r = -1;
        for (int i = 0; i < dominoes.length(); i++) {
            if(chars[i] == '.')
                continue;
            else if(chars[i] == 'L'){
                if(r != -1){
                    l = i - 1;
                    while(r < l){
                        chars[r++] = 'R';
                        chars[l--] = 'L';
                    }
                    r = -1;
                }else{
                    for (int j = i - 1; j >= k; j--) {
                        chars[j] = 'L';
                    }
                }
                k = i + 1;
            }else if(chars[i] == 'R'){
                if(r != -1){
                    for (int j = i - 1; j >= r; j--) {
                        chars[j] = 'R';
                    }
                }
                r = i + 1;
            }
        }
        if(r != -1){
            for(; r < dominoes.length(); r++){
                chars[r] = 'R';
            }
        }
        return new String(chars);
    }
}
```