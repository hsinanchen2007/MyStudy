### 解题思路
这道题用List链表解答，用到的函数有list.add()[给链表增加元素]，list.remove()[移除链表中指定位置的元素]。
首先判断输入的n与m他们是否为0，如果是直接返回，不是进行下一步
创建list链表集合，把n个数字添加进去
判断c也就是第一次要移除的元素位置，eg:m=3,n=5要移除的是位置为2的元素2。用(3-1)%5
然后进入循环，当list中元素大于1个数字时一直循环，移除位于位置c的list中元素，然后c要从这个删除的数字开始往下数m-1个数字，所以用c+m-1，然后在和list.size()求余数（注意：此时的list.size已经比原来小1了）。然后在删除，知道链表中只剩下1个数字为止。
输出链表中唯一剩下的一个数字。
### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        if(n==0||m==0) return 0;
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<n;i++){
            list.add(i);
        }
        int c = (m-1)%n;
        while(list.size() != 1){
            list.remove(c);
            c = (c+m-1)%list.size();
        }
        return list.get(0);
    }
}
```