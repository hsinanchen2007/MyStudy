思路：
有三根柱子，A:盘子所在的柱子,B:辅助柱子，C:目的柱子，即最后把盘子放到这根柱子。辅助柱子不是固定的，比如，你要把盘子从柱子B移动到柱子C，那么这种情况下，柱子A就是辅助柱子。即，把盘子(盘子数大于1)从一根柱子移动到另一根柱子时，永远需要另一根柱子来辅助完成这个操作。
如果A柱子上只有一个盘子，那么我们只要把盘子从A移动到C即可。
如果A柱子上有n(n > 1)个盘子，那么，我们可以把上面的n-1个盘子放到辅助柱子B上，然后把柱子A剩下的最后一个盘子(这个盘子是原来n个盘子中最大的那个，因为他在最下面)移动到柱子C上，最后把刚才放到柱子B上的n-1个盘子放到柱子C上。

```
class Solution {
    public void hanota(List<Integer> A, List<Integer> B, List<Integer> C) {
        hanota(A.size(), A, B, C);
    }
    
    //有三根柱子，A:盘子所在的柱子,B:辅助柱子，C:目的柱子，即最后把盘子放到这根柱子。
    private void hanota(int n, List<Integer> A, List<Integer> B, List<Integer> C) {
        //如果A柱子只剩一个盘子，那么直接移动到C柱子即可
        if (n == 1) {
            removeTo(A, C);
            return;
        }
        //把A柱子上面的n-1个盘子，借助辅助柱子C，放到柱子B上
        hanota(n - 1, A, C, B);
        //此时A柱子剩下那个盘子是n个盘子中最大的那个，把他移动到C柱子上
        removeTo(A, C);
        //最后把刚才放在B柱子上的n-1个盘子，借助柱子A辅助，放到柱子C上
        hanota(n - 1, B, A, C);
    }
    
    //从l1移动到l2
    private void removeTo(List<Integer> l1, List<Integer> l2) {
        l2.add(l1.remove(l1.size() - 1));
    }
}
```
