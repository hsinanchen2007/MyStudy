此题比较容易，滑动窗的套路题，下面是代码，思路参见注释
执行结果：通过
显示详情 
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :5.9 MB, 在所有 C 提交中击败了100.00%的用户
```
int equalSubstring(char * s, char * t, int maxCost)
{
    int begin = 0, end = 0, max = 0, cost = maxCost;
    int len = strlen(s);
    while (end < len) {
        while ((end < len) && (cost >= 0)) { /* 只要还有cost，就继续往窗里放字符 */
            cost -= abs(s[end] - t[end]);
            end++;
            if ((cost >= 0) && (end - begin > max)) {
                max = end - begin; /* 满足cost>=0条件直接记录最大长度 */
            }
        }
        cost += abs(s[begin] - t[begin]); /* 左边移出窗外，恢复cost值 */
        begin++;
    }
    return max;
}
```
