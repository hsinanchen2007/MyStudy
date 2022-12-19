### 解题思路
此处撰写解题思路

### 代码

```c
int maxNumberOfBalloons(char * text){
    int nums[128] = {0};

    for (int i = 0; text[i] != '\0'; i++) {
        nums[text[i]]++;
    }

    char *word = "balloon";
    int min = nums[word[0]];

    for (int j = 0; word[j] != '\0'; j++) {
        if (nums[word[j]] == 0) {
            return 0;
        }

        if (word[j] == 'l' || word[j] == 'o') {
            min = (min > nums[word[j]] / 2) ? nums[word[j]] / 2 : min;
        } else {
            min = (min > nums[word[j]]) ? nums[word[j]] : min;
        }
    }
    
    return min;
}
```