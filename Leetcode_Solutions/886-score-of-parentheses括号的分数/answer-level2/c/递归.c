```
static int get_score(char **s);
int scoreOfParentheses(char *s)
{
    return get_score(&s);
}

static int get_score(char **s)
{
    int score = 0;
    while (**s != 0) {
        if (**s == '(') {
            *s += 1;
            score += get_score(s);
        } else {
            *s += 1;
            score *= 2;
            return (score == 0) ? 1 : score;
        }
    }

    return score;
}
```