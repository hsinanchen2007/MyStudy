### 解题思
题目没有看懂。。。。。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int i, cnt = 1, len = strlen(seq);
    int *re = (int*)calloc(len, sizeof(int));
    *returnSize = len;
    for(i = 0;i < len;++i)
    {
        if(seq[i] == '('){
            cnt ^= 1;
            re[i] = cnt;
        }
        else{
            re[i] = cnt;
            cnt ^= 1;
        }
    }
    return re;
}

JAVA：

public class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[] ans = new int [seq.length()];
        int idx = 0;
        for(char c: seq.toCharArray()) {    //成为数组
            ans[idx++] = c == '(' ? idx & 1 : ((idx + 1) & 1);
        }
        return ans;
    }
}
