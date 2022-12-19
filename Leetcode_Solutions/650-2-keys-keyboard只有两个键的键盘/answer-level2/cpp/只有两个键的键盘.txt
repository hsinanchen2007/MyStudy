一次过，过来看了其他大佬的题解，发现没有我这种方法的，因为方法的整体效率还不错，特地来写题解。
思路： 
* 除却第一次复制粘贴一个 A 之外，后面可以分析出，如果可以复制粘贴，肯定复制粘贴新的 A 串会比粘贴上一个复制的 A 串效率要高
* 那么如何判断是否可以完成复制粘贴呢，可以简单分析出，（n - 当前 A 串长度）% (当前 A 串长度) == 0 则可以复制粘贴。
代码：
```C++
class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
            return 0 ;
        int count = 1 ,ant = 1,fuzhi = 1; // 依次代表 当前 A 串长度，复制粘贴总次数，复制串的长度 
        int flag = 1 ; // 复制之后就得粘贴，否则会死循环
        while(n!=count){
            if((n-count)%count==0 && flag == 0){
                fuzhi = count ; 
                flag = 1 ;
            }else {
                count +=fuzhi ;
                flag = 0 ;
            }
            ant++ ;
           // printf("%d %d %d\n",ant,fuzhi,count) ;
        }
        return ant ; 
    }
};
```
本人最近也在刷 Leetcode ，一般自己的一些思路想法会写在我的 Github 上：[C++ 刷 Leetcode](https://github.com/Fightjiang/leetcode-study)
嘻嘻，欢迎大家来 start ，fork ,issues