首先进行边界判断，如果size为0或者1则不需要压缩，直接返回。然后对满足条件的进行压缩。首先记录当前字符，以及当前的storeIndex。从第一位开始往后找，如果后一位与当前字符相同则count++，如果不同则需要将数字写入到数组中。同时将count置为1，storeIndex++。
代码如下：
```
void modifyVector(vector<char> &s, int *storeIndex, int count, char c)
{
    s[(*storeIndex)++] = c;
    if(count != 1) {
        string countString = std::to_string(count);
        for (int i = 0; i < countString.size(); i++) {
            s[(*storeIndex)++] = (std::to_string(count))[i];
        }
    }
}


int compressVector(vector<char> &s) {
    long size = s.size();
    if(size == 0 || size == 1) return 1;
    char currentChar = s[0];
    int count = 1;
    int storeIndex = 0;
    for (int i = 1; i < size; i++) {
        if (currentChar == s[i]) {
            count++;
        }else {
            modifyVector(s, &storeIndex, count, currentChar);
            count = 1;
            currentChar = s[i];
        }
    }
    
    modifyVector(s, &storeIndex, count, currentChar);
    return storeIndex;
}

```

