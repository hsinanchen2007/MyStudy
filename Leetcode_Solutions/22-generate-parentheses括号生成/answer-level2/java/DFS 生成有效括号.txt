### 解题思路
此处撰写解题思路

### 代码

```c
//递归回溯求解，注意减枝
void generate(int left, int right, int n, char *str, int index, char **result, int *returnSize) {
  if (left == n && right == n) {  //左右括号都用完
    result[(*returnSize)] = (char *)malloc(sizeof(char) * (2 * n + 1));
    str[index] = '\0';
    strcpy(result[(*returnSize)++], str);
    return;
  }

  if (left < n) {  //当左括号没用完时
    str[index] = '(';
    generate(left + 1, right, n, str, index + 1, result, returnSize);
  }
  if (left > right && right < n) {  //右括号数量必须小于左括号，否则一定不合法，且右括号没有用完
    str[index] = ')';
    generate(left, right + 1, n, str, index + 1, result, returnSize);
  }
}

char **generateParenthesis(int n, int *returnSize) {
  char *str = (char *)malloc(sizeof(char) * (2 * n + 1));
  char **result = (char **)malloc(sizeof(char *) * 2500);
  *returnSize = 0;
  generate(0, 0, n, str, 0, result, returnSize);
  return result;
}

java：
class Solution {
    List<String> res = new ArrayList<>();
    public List<String> generateParenthesis(int n) {
        dfs(n, n, "");
        return res;
    }

    private void dfs(int left, int right, String curStr) {
        if (left == 0 && right == 0) { // 左右括号都不剩余了，递归终止
            res.add(curStr);
            return;
        }

        if (left > 0) { // 如果左括号还剩余的话，可以拼接左括号
            dfs(left - 1, right, curStr + "(");
        }
        if (right > left) { // 如果右括号剩余多于左括号剩余的话，可以拼接右括号
            dfs(left, right - 1, curStr + ")");
        }
    }

}

```