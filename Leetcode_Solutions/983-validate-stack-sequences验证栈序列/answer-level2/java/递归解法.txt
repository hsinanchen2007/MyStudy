执行用时 :1 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :37.1 MB, 在所有 java 提交中击败了97.67%的用户
```
//可以根据第一个push进去的数(X)来分
//因为要pop出第一个数X，之前的数必须全部pop出去
//popped中X之前的数肯定先于X之后的数push进去
//以此为依据来判断
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        if(pushed.length != popped.length)
            return false;
        return validateStackSequencesHelper(pushed, popped, 0, popped.length, 0);
    }

    private boolean validateStackSequencesHelper(int[] pushed, int[] popped, int start, int end, int k){
        int index, i;

        if(start == end)
            return true;
        index = -1;
        for(i = start; i < end; i++)
            if(popped[i] == pushed[k])
                index = i;
        if(index == -1)
            return false;
        return validateStackSequencesHelper(pushed, popped, start, index, k + 1)
            && validateStackSequencesHelper(pushed, popped, index + 1, end, k + index - start + 1);
    }
}
```
