# 找环问题
秘诀就是：能提前判断是快乐数，就返回，不要等到快慢指针再相等！！
```
class Solution {
    public int nextNum(int n) {
        int ret = 0;
        int tmp = 0;
        while (n != 0){
            tmp = n % 10;
            ret += tmp * tmp;
            n /= 10;
        }
        return ret;
    }
    
    public boolean isHappy(int n) {
        int fast = n;
        int slow = n;
        while (true) {
            slow = nextNum(slow);   // 慢指针
            fast = nextNum(nextNum(fast));
            if (slow == 1 || fast == 1){   // 等于1说明是快乐数，提前返回！！
                return true;
            } else if (slow == fast) {   // 存在循环，说明不是
                return false;
            } 
        }
    }
}
```
