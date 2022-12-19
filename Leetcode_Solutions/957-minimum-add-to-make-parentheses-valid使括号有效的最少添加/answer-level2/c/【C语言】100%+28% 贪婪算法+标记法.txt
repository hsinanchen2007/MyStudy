### 解题思路
1.思路比较简单：
(1)使用贪婪算法：
A.如果S[i] == '('，那么在i之后的元素中搜索')'（位置为S[j]），找到后，将S[i]和S[j]标记为'X'。
B.如果S[i] == ')'，那么在i之前的元素中搜索'('（位置为S[j]），找到后，将S[i]和S[j]标记为'X'。
(2)经过贪婪算法将能“天然匹配”的括号标记为'X'后，S中剩余的括号就是需要添加取匹配的。因此，只需要遍历S中剩余的括号即可得到需要添加的括号数。
2.corner condition：
（1）.对于)))((((类型的括号，一开始没考虑进去；
3.知识点总结：
贪婪算法+标记法。
4.耗时：32mins，还比较满意，本来15mins可以搞定的。主要耗时点：
（1）对于)))(((类型的括号，一开始设计算法的时候没有考虑进去，多花去了15mins-----读题（示例）不准；
（2）对于贪婪算法中，找到匹配的括号后要break，一开始没有break------算法实现时不够专注；
![image.png](https://pic.leetcode-cn.com/418de0fa5446f7996ee2a85553563f61a3bc5ef21890c8ac50ecf6e238b47e4a-image.png)

......

### 代码

```c

int minAddToMakeValid(char * S){
    int count = 0;
    int i = 0;
    int j = 0;
    int len = strlen(S);
    for(i = 0; i < len; i++) {
        if(S[i] == '(') {
            for(j = i + 1; j < len; j++) {
                if(S[j] == ')') {
                    S[i] = S[j] = 'X';
                    break;
                }
            }
        }
        //printf("%s\n",S);
        if(S[i] == ')') {
            for(j = 0; j < i; j++) {
                if(S[j] == '(') {
                    S[i] = S[j] = 'X';
                    break;
                }
            }
        }
        //printf("%s\n",S);
    }

    for(i = 0; i < len; i++) {
        if(S[i] == '(' || S[i] == ')') {
            count++;
        }
    }
    return count;
}
```