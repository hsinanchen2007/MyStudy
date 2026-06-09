### 解题思路
双指针

### 代码

```c
bool oneEditAway(char* first, char* second){
    int firstLen = strlen(first);
    int secondLen = strlen(second);
    int firstIdx = 0;
    int secondIdx = 0;
    int count = 0;

    if (firstLen - secondLen > 1 || secondLen - firstLen > 1) {
        return false;
    }

    for (; firstIdx < firstLen && secondIdx < secondLen; firstIdx++, secondIdx++) {
        if (first[firstIdx] == second[secondIdx]) {
            continue;
        }
        if (firstLen < secondLen) {
            firstIdx--;
        } else if (firstLen > secondLen) {
            secondIdx--;
        }
        count++;
        if (count > 1) {
            return false;
        }
    }

    return true;
}
```