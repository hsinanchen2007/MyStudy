* 下界是缺失的字符类型 $N_{c}$ 。

* 如果长度 $l$ 小于 6，那么通过添加 $6-l$ 个字符使密码合法，因为最长长度是 5 。添加一个字符就可以打破连续三字符，所以不需要考虑连续，结果 $\max(6-l, N_c)$ 。

* 如果长度 $l$ 小于等于 20， 那么通过替换进行去连续，一个长度为 $s$ 的连续串，需要 $s/3$ 次替换。（需要 $（s-2)/2$ 次插入或 $x-2$ 次删除，所以不考虑）。替换次数为 $N_m$，结果 $\max(N_m, N_c)$ 。

* 长度大于 20 必须要使用删除 $l - 20$ 次，删除后还需要修改去除连续，结果是$\max(N_m, N_c)+l-20$ 。

* 在删除的同时尽量消除连续以减少后续修改的数量。如果串中的连续串长度全部是 $3n+2$ 的形式，那么必须消除3个，才能减少一次修改，总共消除 $N_r$ 次, 结果 $\max(N_m - N_r/3, N_c)+l-20$ 。

* 然而连续子串的长度还可以是 $3n$ 与 $3n+1$ 的形式，我们发现对于 $3n$ 形式的子串，只需要删除一个字符就能减少一次未来的修改。而连续子串的长度变为 $3n+2$ 的形式。而 $3n+1$ 形式的连续子串需要删除两个字符，从而减少一次未来的修改，并变为 $3n+2$ 的形式。 

* 统计 $3n$ 与 $3n+1$ 型子串的个数 $N_0$ 与 $N_1$ ，先转化 $3n$ 型，如果能全转化，那么后续少修改 $N_0$ 次，否则转化 $N_r$ 个，未来少修改 $N_r$ 次。然后转化 $3n+1$ 型，全转化还需要 $2 N_1$ 次删除，如果能全转化，那么后续少修改 $N_1$ 次，否则转化 $N_r/2$ 个，未来少修改 $N_r/2$ 次。

* 全部转化为 $3n+2$ 型后，结果如之前所述。

```c
int strongPasswordChecker(char * s){

    bool has_digit = false, has_lower = false, has_upper = false;
    int  len = 0;
    char c;

    int cnt_mod[3] = {0, 0, 0}; /* 统计 3n,3n+1,3n+2 型连续子串的数量 */
    int n_modify = 0; /* 修改次数 */

    while (c = s[len]) {
        /* 统计字符类型 */
        switch (c) {
            case '0' ... '9': has_digit = true; break;
            case 'a' ... 'z': has_lower = true; break;
            case 'A' ... 'Z': has_upper = true; break;
        }

        /* 连续子串长度 */
        int i = len;
        while (s[++i] == c);
        int l = i - len;

        if (l >= 3) {
            n_modify += l / 3; /* 后续修改数等于重复长度/3 */
            cnt_mod[l % 3]++;
        }

        len = i;

    }

    /* 缺少的字符类型数目, 下界 */
    int n_missing_ctype = !has_digit+ !has_upper+ !has_lower;

    /* 过短，插入缺少的字符数量 */
    if (len < 6) return max(6-len, n_missing_ctype);

    /* 长度合法，修改去除连续子串 */
    if (len <= 20) return max(n_modify, n_missing_ctype);

    /* 过长，还可以删除 len - 20 个字符 */
    int n_remove = len - 20;
    
    /* 3n 型子串无法完全变为 3n+2 型，
        每个需要 1 次删除，
        只能把 n_remove 个变为 3n+2 型
        减少 n_remove 次后续修改
        */
    if (n_remove < cnt_mod[0]) 
        return max(n_modify - n_remove, n_missing_ctype) + len - 20;

    /* 3n 型全部变为 3n+2 型 */
    n_remove -= cnt_mod[0];
    n_modify -= cnt_mod[0];

    /* 3n+1 型无法完全变为 3n+2 型， 
        每个需要 2 次删除， 
        减少 n_remove/2 次后续修改
        */
    if (n_remove < cnt_mod[1] * 2)
        return max(n_modify - n_remove/2, n_missing_ctype) + len - 20;
    
    n_remove -= cnt_mod[1] * 2;
    n_modify -= cnt_mod[1];

    return max(n_modify - n_remove/3, n_missing_ctype) + len - 20;
}
```