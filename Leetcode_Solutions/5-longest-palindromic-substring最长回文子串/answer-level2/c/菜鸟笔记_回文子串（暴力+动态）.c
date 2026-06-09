### 解题思路
1. 暴力破解会超时
2. 第一次做动态规划，感觉是个好东西！

### 代码

```c
//2020.3.7 10：00

/*方法一：暴力（timeout）
bool isPalindrome(char* s, int head, int rear){
   int len = strlen(s);
    while (head <= rear && rear > 0 && head < len){
        if (s[head] != s[rear]){
            break;
        }
        else{
            head++;
            rear--;
        }
    }
    if (head > rear){
        return true;
    }
    else{
        return false;
    }
}
char * longestPalindrome(char * s){
    int head = 0;
    int rear = 1;
    int len = strlen(s);

    if (len == 1 || len == 0){
        return s;
    }

    int max = 0;
    int maxtag = 0;

    while (s[head] != '\0'){
        while (rear < len){
            if (s[head] == s[rear]){//前后相等，判断是否为回文子串
                if (isPalindrome(s, head, rear)){
                    if ((rear-head)>max){
                        max = rear - head;
                        maxtag = head;
                    }
                }

            }
            rear++;
        }
        head++;
        rear = head+1;

    }
    s[maxtag+max+1] = '\0';
    
    return s+maxtag;

}
*/
//方法二：动态规划
char * longestPalindrome(char * s){
    int start = 0;
    int p[1000][1000] = {0};
    int len;
    char* ans = "";
    int max = 0;
    int sl = strlen(s);
    int tag = 0;
    for (len = 1; len <= sl; len++){
        printf("%d\n", len);
        for (start = 0; start < sl; start++){
            int end = start + len - 1;
            if (end >= sl){
                break;
            }
            p[start][end] = (len == 1 || ((len == 2 || p[start+1][end-1]) && s[start] == s[end]));
            if ((end-start+1 > max) && p[start][end]){
                max = end-start+1;
                tag = start;
                printf("max = %d, tag = %d\n", max, tag);
            }
        }
    }
    s[tag+max] = '\0';
    ans = s+tag;

    return ans;











}
```