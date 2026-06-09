看了官方题解，然后增加注释。
主要是2种方法，第一种是深度优先搜索，如果左右括号都用完则满足结果，否则的话往下搜索。
要考虑left可以一直入，right需要大于left。为什么呢？因为不满足的情况都是因为right比left更早进入到字符串中。
```
public List<String> generateParenthesis(int n) {
    List<String> resultList = new ArrayList<>();
    dfs(resultList, "", n, n);
    return resultList;
}


public void dfs(List<String> resultList, String str, int left, int right) {
    //深度优先搜索，在末尾设置一个返回或者弹出的临界值，然后回溯。
    if (left == 0 && right == 0) {
        resultList.add(str);
    }
    //考虑放入左括号，可以随意放入
    if (left > 0) {
        dfs(resultList, str + '(', left - 1, right);
    }
    //不满足情况的例子都是因为右括号早于左括号放入，因此right必须在left之后放入
    if (right > left) {
        dfs(resultList, str + ')', left, right - 1);
    }
}
```


第二种方法也是官方题解的开闭括号方法，本质是一种动态规划，动态规划的根本是状态转移方程，即当前的状态如何由前面的状态得到。对于这一题，我们知道对于任何满足条件的字符串，必然是满足 '(' + in + ')' +other。
比如当前需要的是n对，那么我们可以知道 in和other的对数和是n-1，因此in和other就是动态规划的前一个状态。
in和other是什么意思呢？in和other表示某个满足条件的子字符串。
in和other都是满足条件的，比如都是()，组成后的结果是'('+'()'+)'+'()',这是一种结果，总长度为3*2
 也可以是'('+''+')'+'()()'，这个时候in为""，other为'()()'，所以对于in和other有多种组合，但是总长度一定是n-1。
同时，比如说n-1为3，in为1，other为2，other有()()和(()),因此需要遍历other的list。
根据这样子的分析，我们可以写出以下的代码

```
public List<String> generateParenthesis(int n) {        
        //下标为i的list存储长度为i对括号的结果
        List<List<String>> allResultList = new ArrayList<>();

        //初始化，如果为n=0则返回空串
        List<String> resultList = new ArrayList<>();
        resultList.add("");
        allResultList.add(resultList);

        for (int i = 1; i <= n; i++) {
            resultList = new ArrayList<>();
            for (int inLen = 0; inLen < i; inLen++) {
                //这表示inList的长度为inLen，otherList的长度为i-in-1，和为i-1，这样子
                List<String> inList = allResultList.get(inLen);
                List<String> otherList = allResultList.get(i - inLen - 1);
                //in和other有多种组合
                for (int inIndex = 0; inIndex < inList.size(); inIndex++) {
                    for (int otherIndex = 0; otherIndex < otherList.size(); otherIndex++) {
                        resultList.add('(' + inList.get(inIndex) + ')' + otherList.get(otherIndex));
                    }
                }
            }
            allResultList.add(resultList);
        }

        return allResultList.get(n);
    }
```

总结：看起来听复杂的，想清楚后其实挺好理解的，慢慢看一下

