### 解题思路
嗯嗯，创建两个26个单元空间保存出现的字符，再遍历比较就欧克
![1.png](https://pic.leetcode-cn.com/2d59bef8678892c6e552fcef7a3973d1ba4671ad0ee6b7778ff8c55a65742090-1.png)

### 代码

```c
bool isAnagram(char * s, char * t){
    bool flag = true;
    int len_s = 0;
    int len_t = 0;
    while (s[len_s]!='\0') {
        len_s++;
    }
    while (t[len_t]!='\0') {
        len_t++;
    }
    if  (len_s==0&&len_t==0) flag = true;
    else if (len_t==0) flag = false;
    else if (len_s==0) flag = false;
    else if (len_s!=len_t) flag = false;
    else {
        int arr_s[26] = {0};
        int arr_t[26] = {0};  
        while (len_s!=0) {
            arr_s[s[len_s-1]-'a']++;
            arr_t[t[len_s-1]-'a']++;
            len_s--;
        }
        int index = 0;
        while (index<26) {
            if (arr_s[index]!=arr_t[index] ) {
                flag = false;
                break;
            }
            index++;
        }
    }
    return flag;
}
```