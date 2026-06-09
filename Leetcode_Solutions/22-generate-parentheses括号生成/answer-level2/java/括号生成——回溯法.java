### 题目

给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

### 解题思路

回溯法，限制条件右括号数不能大于左括号数。

### 代码

```java
class Solution {

    public static void backtrack(List<String> seqList, int n, String seq, int leftnum,int rightnum){
        if(leftnum==n&&rightnum==leftnum){
            seqList.add(seq);
        }
        if(leftnum<n){
            seq+="(";
            backtrack(seqList,n,seq,leftnum+1,rightnum);
            seq = seq.substring(0,seq.length()-1);
        }
        if(rightnum<leftnum){
            seq+=")";
            backtrack(seqList,n,seq,leftnum,rightnum+1);
            seq = seq.substring(0,seq.length()-1);
        }
    }

    public List<String> generateParenthesis(int n) {
        List<String> seqList= new ArrayList<String>();
        String seq = "";
        backtrack(seqList,n,seq,0,0);
        return seqList;
    }
}
```