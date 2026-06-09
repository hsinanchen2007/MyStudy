### 解题思路
需要理解树的前序的特点：
```
 A
/ \   前序的结果为 A,B,C
B C
```
根据题目的描述，如果节点是叶子，其子节点分别用‘#’，表示。因此，我们观察这种前序的特点：

```
 A
/ \   前序的结果为 A,#,#
# #


   A
  / \   前序的结果为 A,B,#,#,#
  B #
 / \
 # #

   A
  / \   前序的结果为 A,#,C,#,#
  # C
   / \
   # #

```
从这里我们可以看到，如果一个节点后面跟着两个‘#’，那么这个节点就是一个叶子。

我们验证一个前序是否合法，可以通过尝试把所有叶子摘光，看是不是序列刚好也就空了便是；注意摘掉一个叶子后，叶子的位置需要用"#"代替。

剩下的代码就比较好写了，直接push，pop即可。

注意，题目有两个小坑：
1. 题目没有说只有数字且只有一位，因此需要考虑用分隔符识别支付串的方式，而不是简单的去找数字；
2. 发现leetcode的函数调用还是会消耗性能的，即便只有几行代码，因此后来我把pop和push直接用代码来表示了，效率从65%提升为100%了。


### 代码

```c

bool isValidSerialization(char * preorder){
    int sLen = strlen(preorder);
    int len = 0;
    char **list = NULL;
    char *token;
    char *plusStr = "#";

    if (sLen < 1) {
        return false;
    }

    list = malloc(sizeof(char*)*(sLen + 2));
    memset(list,0,sizeof(char*)*(sLen + 2));

    token = strtok(preorder,",");
    if (token == NULL) {
        return false;
    }

    bool moved = false;

    while(token != NULL) {        
        moved = false;
        if ((len >= 2) && (token[0] == '#'))  {
            while ((list[len-2][0]!= '#')&&(list[len-1][0] == '#')) {
                moved = true;
                len -= 2; // pop(), pop(), 表示pop两次的效果
                if (len < 2) {
                    break;
                }
            }
            list[len++] = plusStr; // PUSH()
        } else {
            list[len++] = token;  // PUSH()
        } 
        token = strtok(NULL,",");
    }

    if ((len == 1) && (list[0][0] == '#')) {
        len = 0;
    }
    
    return (len == 0)? true:false;
}
```