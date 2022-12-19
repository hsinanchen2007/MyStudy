int g_count = 0;
int g_max = 0;

void DfsStep(char **buf, char *tempBuf, int left, int right)
{
    int i;

    if (buf == NULL || tempBuf == NULL) {
        return;
    }

    if (right == g_max / 2) {
        buf[g_count] = (char *)malloc(sizeof(char) * (g_max + 1));
        for (i = 0; i < g_max; i++) {
            buf[g_count][i] = tempBuf[i];
        }
        buf[g_count][g_max] = '\0';
        g_count++;
        return;
    }

    if (left < g_max / 2) {
        tempBuf[left + right] = '(';
        DfsStep(buf, tempBuf, left + 1, right);
    }
    if (right < left) {
        tempBuf[left + right] = ')';
        DfsStep(buf, tempBuf, left, right + 1);
    }
}

char **generateParenthesis(int n, int *returnSize)
{
    if (n == 0 || returnSize == NULL) {
        return NULL;
    }

    char **buf = (char **)malloc(sizeof(char *) * 2048);
    char tempBuf[1024] = { 0 };

    *returnSize = 0;
    g_count = 0;
    g_max = 2 * n;

    DfsStep(buf, tempBuf, 0, 0);
    *returnSize = g_count;
    return buf;
}