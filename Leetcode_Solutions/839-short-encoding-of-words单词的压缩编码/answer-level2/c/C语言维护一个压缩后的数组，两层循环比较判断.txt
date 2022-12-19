### 解题思路

执行用时 :1344 ms, 在所有 C 提交中击败了28.87%的用户  
内存消耗 :7.6 MB, 在所有 C 提交中击败了100.00%的用户  

对于输入的原始words字符串数组，["time", "me", "bell"]，
维护一个new_words字符串数组，里面存放压缩后的单词["time","bell"]。

两层循环，遍历每个words里的单词，看是否和new_words里的单词有相同的尾部(准确的说是一个以另一个为尾部)，用flag标记比较结果。
如果有的话，且words里的单词比new_words的单词长时，将new_words里的字符串用words里的字符串替代。
如果没有则将words里的这个单词加入到new_words里。

### 代码

```c
int minimumLengthEncoding(char ** words, int wordsSize){
    bool flag=false;
    int i, j, k1, k2, res=0, new_wordsSize=0;
    char **new_words = (char**)malloc(sizeof(char*)*wordsSize);
    for(i=0; i<wordsSize; i++){
        for(j=0; j<new_wordsSize; j++){
            flag = true;
            k1=strlen(words[i]);
            k2=strlen(new_words[j]);
            // 判断是否是一样的尾部
            while(k1>=0 && k2>=0){
                if(words[i][k1--] != new_words[j][k2--]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                if(k1>=0){  // 如果一样的尾部但words里的单词比new_words的单词长，则替换
                    res += (k1-k2);
                    new_words[j] = words[i];
                }
                break;
            }
        }
        // 如果是新单词，则加入到new_words里
        if(!flag){
            res += (strlen(words[i])+1);
            new_words[new_wordsSize++] = words[i];
        }
    }
    return res;
}

```