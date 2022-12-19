首先考虑这个问题需要通过子问题的不同情况来进行判断，所以可以使用动态规划；
因为题目中存在s或者p为空串的情况，所以声明一个全为false的[s.length + 1][p.length + 1]的数组，
并在进行正式的状态转移方程之前，对s是空串的情况进行初始化，即
```
matchArray[0][0] = true;
    for(let j = 1; j < pLen ; j++){
        if(p[j-1] === '*'){
            matchArray[0][j] = matchArray[0][j-2];
        }
    }
```
之所以当为*时，需要等于 p(j-2)时的子串匹配状态， 是因为*代表前一个字符为0个或者连续多个的情况，在s为空的情况下，我们只考虑前一个字符为0个的情况，这种情况即为p(j-2)子串时的状态
即 ab* 状态等于 a


然后我们考虑状态转移方程，由题目可知如果当前进行匹配的两个字符相等或者p的字符为.'时，
当前的状态由 `matchArray[i-1][j-1]` 决定，即
abac 和 ab.c 状态等于 abc 和 ab.的状态，c不需要考虑
```
if(s[i-1] === p[j-1] || p[j-1] === '.'){
                matchArray[i][j] = matchArray[i-1][j-1];
```

然后当当前p为*时，有两种情况
1.前一个p字符与当前值s相等或者前一个的p为'.'时，**（前一个p字符可能为0个，也可能为多个）**
当前状态为
（1）上一个s子串`(matchArray[i-1][j])`匹配状态的延续，**（为0个前一个p字符）**
（2）或者如果不需要上一个字符则可以将其与 p(j-2)即p的上上个子串`(matchArray[i][j-2])`进行匹配**（为多个前一个p字符）**
所以得到  `matchArray[i][j] = matchArray[i-1][j] || matchArray[i][j-2];`
2.当上一个p字符与当前s字符不相等时，（必须为0个）
我们需要将其视为上一个字符有零个，即与上上个字符状态进行比较
`matchArray[i][j] = matchArray[i][j-2];`

所以综上得到：
```
for(let i = 1 ; i < sLen ; i++){
        for(let j = 1 ; j < pLen ; j++){
            if(s[i-1] === p[j-1] || p[j-1] === '.'){
                matchArray[i][j] = matchArray[i-1][j-1];
            }else if(p[j-1] === '*'){
                if(s[i-1] === p[j-2] || p[j-2] === '.'){
                    matchArray[i][j] = matchArray[i-1][j] || matchArray[i][j-2];
                }else{
                    matchArray[i][j] = matchArray[i][j-2];
                }
            }
        }
    }

```
