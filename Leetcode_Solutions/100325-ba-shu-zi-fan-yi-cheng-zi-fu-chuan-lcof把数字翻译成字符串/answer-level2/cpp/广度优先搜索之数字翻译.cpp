# 1. 思路
看到这道题的第一个思路就是bfs算法，首先确定一个前缀，前缀有两种可能，单个数或者两位数，两位数限与10到25。剩下的部分，递归调用即可。
# 2. 代码
1. 递归终止条件，如果num为0，返回1。注意这里不是返回0，因为进入此层递归时，已经算是一种翻译方法。
2. 从地位开始，得到数字的两个前缀，一位数前缀直接递归计算，只有再[10,25]范围内的两位数才能作为前缀递归计算。
3. 累计两种前缀的所有翻译方法
```c++ []
class Solution {
public:
    int translateNum(int num) {
        if(num == 0) return 1;
        int a = num % 10;
        int b = num % 100;
        int answer = translateNum(num/10);
        if(b>=10 && b<=25){
            answer += translateNum(num/100);
        }
        return answer;
    }
};
```
# 3. 总结
一开始的思路很重要，思路对了，接下来就是把思路翻译成代码了。