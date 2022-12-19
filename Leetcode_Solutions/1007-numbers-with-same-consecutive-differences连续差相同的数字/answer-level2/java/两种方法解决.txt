### 方法1：DFS
定义helper(List<Integer> resultList, int temp, int count, int N, int K, int levelAns)
resultList：收集结果的
temp：每一轮的的seed数字，从1-9
count：当前数的位数，要求为N，当count达到N时，搜索结束，需要开始返回
N：目标数的位数
K：目标数之间相差的差值
levelAns：没一层的的值，送到下一层的时候需要*10

考虑两种情况：
如N=3,K=7
当temp-K>=0 如当前的temp为8 K为7，满足题意，送8-7=1进下一层，下一层是8*10+1（8-7）
当temp + K < 10 时，如temp=3, 3+7不满足题意，不进循环，因为3后面的数比它大K（7）只能是10
310的10超了，越界了


```
public int[] numsSameConsecDiff(int N, int K) {
    if (N == 1) return new int[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    List<Integer> resultList = new ArrayList<>();
    for (int i = 1; i <= 9; i++) {
        helper(resultList, i, 0, N, K, 0);
    }
    int[] resArr = new int[resultList.size()];
    for (int i = 0; i < resultList.size(); i++) {
        resArr[i] = resultList.get(i);
    }
    return resArr;
}

private void helper(List<Integer> resultList, int temp, int count, int N, int K, int levelAns) {
    levelAns += temp;
    count++;
    if (count == N) {
        resultList.add(levelAns);
        return;
    }
    if (temp - K >= 0) {
        helper(resultList, temp - K, count, N, K, levelAns * 10);
    }
    if (temp + K < 10 && K != 0) {
        helper(resultList, temp + K, count, N, K, levelAns * 10);
    }

}
```


### 方法2：DP TODO