### 解题思路
本题最大的收获是对进制的理解又“深刻”了一些，其实根本谈不上深刻，因为这本来就是及其基础的知识：
当进制是n(如26)时，它的每位数字的范围是0~n-1(如0~25)。是的就是那么基础又简单的问题成为本题最大的障碍！

另外，在[字母移位](https://leetcode-cn.com/problems/shifting-letters/solution/zi-mu-yi-wei-by-leetcode/)中获得了本题的核心思路：

*因为对第 i 个字母及后面字母的移位都会导致第 i 个字母移位，所以第 i 个字母共移位 shifts[i] + shifts[i+1] + ... + shifts[shifts.length - 1] 次。

假设第 i 个字母移位 X 次，那么第 i + 1 个字母移位 X - shifts[i] 次。*

简化表达也就是说S[i]只会被S[i+1]到S[Slength]对应的移动步长(shifts[i])影响

经过短短几天的练习我发现这些程序设计题其实就是将具体问题巧妙地归结到一个适合的基本知识点，如[寻找重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/fu-luo-yi-de-de-wu-gui-he-tu-zi-xun-huan-jian-ce-g/)就十分巧妙地(至少对我来说)被归结为了环形链表问题，本题的字母循环移位也同样采用了进制上知识。

### 代码

```c
char * shiftingLetters(char * S, int* shifts, int shiftsSize){
    long X=0,i;
    for(i=0;i<shiftsSize;i++) X+=shifts[i];  //X是每个s[i]移动的步长
    i=0;
    while(S[i]!='\0'){
        // printf("X=%d\tS[%d]=%c\n",X,i,S[i]);
        int temp=S[i]-'a'; //temp用来记录s[i]小写字母减去97('a')之后代表的数字，用来定位移位后最终是拿个字母
        S[i]=(X%26+temp)%26+'a';
        X-=shifts[i];
        i++;
    }
    return S;
}
```