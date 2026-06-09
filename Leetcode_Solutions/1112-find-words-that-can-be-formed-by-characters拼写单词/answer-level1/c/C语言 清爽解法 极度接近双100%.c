### 解题思路
- 一次遍历`chars`，一次遍历`words`，24ms的99.73%，8.2MB的100%

- 围绕hash表的理念来解，将`chars`生成一个hash表，一共26个int空间对应26个字母，不出现的为0，出现的为1，重复则++

- **重点**：hash表要保留着让所有`word`都能用来查找，因此创建一个同等大小的`count`计数数组
    1. 遍历单个`word`过程中，长度超过`chars`长度的直接跳过；
    2. 判断字符在hash表中是否出现（hash值不为0），如果出现重复，判断`count`值是否超过hash，超过说明该字母在`chars`中的重复个数不足
    3. 如果判断没问题，`count`值+1；如果循环中无`break`，`max`加上该`word`的长度
    4. 一轮`word`遍历后，下一轮`word`遍历前，**`count`必须置零**！

- 其他的细节在下面代码中有讲解。希望有人能把这一点点0.027的时间差优化，时间效率上提到100%

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    int nums = strlen(chars);
    if (wordsSize == 0 || nums == 0) return 0;  //一者为空直接出局
    int max = 0, j = 0;
    int map[26], count[26]; //hash表 与 计数数组
    memset(map, 0, sizeof(map)); //hash表初始化
    for (int c = 0; c < nums; c++) { //生成hash值
        map[chars[c] - 'a']++;
    }
    for (int i = 0; i < wordsSize; i++) {
        int len = strlen(words[i]);
        if (len > nums) continue;  //单个word长度超过字母表长度，无效
        memset(count, 0, sizeof(count)); //计数数组归零
        for (j = 0; j < len; j++) {
            if (map[words[i][j] - 'a'] <= count[words[i][j] - 'a']) break; //hash值为0 或 重复字母不足
            count[words[i][j] - 'a']++;  //计数+1，代表字母重复一次
        }
        if (j == len) max += len; //当上面循环有break存在时，无效
    }
    return max;
}
```