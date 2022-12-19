#### 这个思想的本质是弗洛伊德环检测算法(Floyd Cycle detection algorithm), 链表问题中判断链表是否有环就是用的这个算法
#### 该算法证明了:使用两个指针slow和fast, 两个指针开始时均在头节点处(S点)，slow指针（龟）一次向后移动一个一步，fast指针（兔）一次向后移动两步。若存在环，则slow和fast必能相遇；反之若slow到达链表尾时两个指针仍不能相遇，则不存在环。 
#### 使用快慢指针的思想寻找计算过程中的循环, 每次循环处理一次slow, 处理两次fast; 细节:循环中单独判断fast是否等于1, 等于1的话直接返回true
```java
class Solution {
    public boolean isHappy(int n) {
        //initialize
        int slow=n, fast=n;
        do{
            slow = core(slow);
            fast = core(fast);
            fast = core(fast);
            //加上这句就能超越100%了
            if(fast==1)
                return true;
        }while(slow!=fast);
        return slow==1;
    }
    public int core(int n){
        int res = 0;
        while(n>0){
            int digit = n%10;
            res = res + digit * digit;
            n = n/10;
        }
        return res;
    }
}
```