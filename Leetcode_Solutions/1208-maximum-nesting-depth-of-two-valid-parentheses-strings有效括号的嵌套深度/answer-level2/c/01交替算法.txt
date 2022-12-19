如果让最后拆分的深度最小，一定是把所有不为1的平分了。
比如，((((((6)))))) 深度是6，拆分后一定是两组(((3)))
如果是((((((6))))))((((4))))，那么应该是两组(((3)))((2)),
或者说(((3)))(1),(((3)))(((3))). 最好的办法就是把所有深度不为1的都平分了，
实际上只要间隔一个进行分组即可。
单数位的记为0，偶数位的记为1.
维护一个cnt，遇到'('加一，遇到')'减一。
代码如下。

```
int* maxDepthAfterSplit(char * seq, int* returnSize)
{
    int slen = strlen(seq);
    int cnt = 0;
    *returnSize = slen;
    int *result = (int *)malloc(sizeof(int) * slen);
    for (int i = 0; i < slen; i++) {
        if (seq[i] == '(') {
            result[i] = cnt % 2;
            cnt++;
        } else {
            cnt--;
            result[i] = cnt % 2;
        }
    }
    return result;
}
```
