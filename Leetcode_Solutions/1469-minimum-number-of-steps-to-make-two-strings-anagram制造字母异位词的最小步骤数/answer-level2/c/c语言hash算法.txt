使用C语言hash的思想，创建两个临时数组来存放各个字符串的字母个数

```
#define ALPHABET_NUM 26

int minSteps(char * s, char * t){
    int length = strlen(s);
    int count;
    int sCount[ALPHABET_NUM] = {0};
    int tCount[ALPHABET_NUM] = {0};

    for (int i = 0; i < length; i++) {
        sCount[s[i] - 'a']++;
        tCount[t[i] - 'a']++;
    }

    count = 0;
    for (int i = 0; i < ALPHABET_NUM; i++) {
        if (sCount[i] > 0) {
            count += sCount[i] > tCount[i] ? sCount[i] - tCount[i] : 0;
        }
    }

    return count;
}
```
![image.png](https://pic.leetcode-cn.com/b348e72094ec663fba3b250f1b931e0712a220c97032eecc89e4cb83875cc8e3-image.png)


