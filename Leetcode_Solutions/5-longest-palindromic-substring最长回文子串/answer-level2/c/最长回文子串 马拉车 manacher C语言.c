
马拉车 原理 简单的插入 # 不用判 回文子串到底是奇数还是偶数。
头尾放奇怪字符，0x01 0x02 等不可见字符串，拦截访问溢出。相比@$等能好一点，其实还是可能会出问题。
中间应该还可以有些优化的地方，另外有些地方没有check 返回值异常， 应用到工程中需要自行完善。

```c
// test caces
#define ARRAY_COUNT(arr) (sizeof(arr) / sizeof(arr[0]))
const char *input[] = {
    NULL,
    "",
    "aba",
    "abac",
    "caba",
    "cabba",
    "abbac",
    "abbaccab",
    "abbaccabd",
    "dabbaccab",
    "dabbaccabbba234",
};

struct manacher {
    char *s;
    int *len;
    int total;
    int first_c;
    int first_r;
    int max;
};

// for debug.
void manacher_display(struct manacher *m)
{
    printf("max=%d. first match: center=%d, radius=%d\n", m->max, m->first_c, m->first_r);
    for (int i = 0; i < m->total; i++) {
        printf(" %c", m->s[i]);
    }
    printf("\n");

    for (int i = 0; i < m->total; i++) {
        printf("%2d", m->len[i]);
    }
    printf("\n");
}

int manacher_create(struct manacher *m, const char *src)
{
    const char *p_src;
    char *ret = NULL, *p_dst;
    int len, extra_len = 5;
    // should check input here.
    len = strlen(src);
    memset(m, 0, sizeof(struct manacher));
    m->s = (char *)calloc(sizeof(char), (len << 1) + extra_len);
    m->len = (int *)calloc(sizeof(int), (len << 1) + extra_len);
    // should check OOM.
    p_dst = m->s;
    *p_dst++ = 0x1;  // unvisable char.
    *p_dst++ = '#';
    for (p_src = src; *p_src != 0; p_src++) {
        *p_dst++ = *p_src;
        *p_dst++ = '#';
    }
    *p_dst = 0x02;  // another unvisable char.
    m->total = p_dst - m->s + 1;
    return 0;
};

int manacher_update_max(struct manacher *m)
{
    int r, max = 0;
    // fill head & tail.
    m->len[0] = m->len[1] = m->len[m->total - 1] = m->len[m->total - 2] = 1;
    for (int i = 2; i < m->total - 2; i++) {
        for (r = 1; m->s[i - r] == m->s[i + r];) {
            r++;
        }
        m->len[i] = r;
        if (r > max) {
            m->first_c = i;
            m->first_r = r;
            max = r;
        }
    }
    m->max = max - 1;
    // manacher_display(m);
    return m->max;
}

void manacher_display_first(struct manacher *m)
{
    char *p_start = m->s + (m->first_c - m->first_r + 2);
    char *p_end = m->s + (m->first_c + m->first_r);
    for (; p_start < p_end; p_start += 2) {
        printf("%c", *p_start);
    }
    printf("\n");
}

char *manacher_strdup_first(struct manacher *m)
{
    char *p_start = m->s + (m->first_c - m->first_r + 2);
    char *p_end = m->s + (m->first_c + m->first_r);
    char *ret = calloc(sizeof(char), p_end - p_start);
    // check oom here.
    for (int i = 0; p_start < p_end; p_start += 2, i++) {
        ret[i] = *p_start;
    }
    return ret;
}

void manacher_destroy(struct manacher *m)
{
    if (m->s != NULL) {
        free(m->s);
    }
    if (m->len != NULL) {
        free(m->len);
    }
}

int manacher_test(const char *s)
{
    struct manacher m;
   // must check input is valid
    if (s == NULL || strlen(s) == 0) {
        return -1;
    }
    manacher_create(&m, s);
    manacher_update_max(&m);
    manacher_display_first(&m);
    manacher_destroy(&m);
    return 0;
}

char *longestPalindrome(char *s)
{
    static char err[] = "";
    char *ret = NULL;
    struct manacher m;
    // must check input is valid
    if (s == NULL || strlen(s) == 0) {
        return err;
    }
    manacher_create(&m, s);
    manacher_update_max(&m);
    ret = manacher_strdup_first(&m);
    manacher_destroy(&m);
    return ret;
}

```
