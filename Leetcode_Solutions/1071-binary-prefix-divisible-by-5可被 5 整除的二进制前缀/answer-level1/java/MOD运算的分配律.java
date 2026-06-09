# 思路
1. 遍历求值，对于i, mod 保存 A[0...i-1] 所表示数值 MOD5 的结果
2. MOD运算对于加法的分配律：(a+b) MOD c=(a MOD c+ b MOD c) MOD c

# 代码
```
public List<Boolean> prefixesDivBy5(int[] A) {
    List<Boolean> answer = new ArrayList<>();
    int temp = 0, mod = 0;
    for (int i = 0; i < A.length; i++) {
        // <<的优先级低于+;MOD运算的分配律
        temp = (mod << 1) + A[i];
        mod = temp % 5;
        answer.add((mod == 0) ? true : false);
    }
    return answer;
}
```
# 总结
时间复杂度O(n);空间复杂度O(n)