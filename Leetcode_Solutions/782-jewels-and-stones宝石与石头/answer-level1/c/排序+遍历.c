```
static int compare(const void *a, const void *b)
{
    char *t_a = (char *)a;
    char *t_b = (char *)b;
    return *t_a - *t_b;
}

int numJewelsInStones(char * J, char * S){
    int count = 0;
    int jLen = strlen(J);
    int sLen = strlen(S);
    qsort(J, jLen, sizeof(char), compare);
    qsort(S, sLen, sizeof(char), compare);

    int next = 0;
    for (int i = 0; i < jLen; i++) {
        while (next < sLen) {
            if (S[next] == J[i]) {
                count++;
                next++;
            } else if (S[next] > J[i]) {
                break;
            } else {
                next++;
            }
        }
    }

    return count;
}

```
