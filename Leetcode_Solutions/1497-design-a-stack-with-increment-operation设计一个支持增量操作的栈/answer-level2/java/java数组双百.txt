* 这道题的最优解应该是用数组模拟
* 只需要维护一个cur指针，一个max指针即可
```java
class CustomStack {
    int[] stack;
    int max;
    int cur;
    public CustomStack(int maxSize) {
        stack=new int[maxSize];
        max=maxSize-1;
        cur=-1;
    }

    public void push(int x) {
        if (cur<max){
            cur++;
            stack[cur]=x;
        }else {
            return;
        }
    }

    public int pop() {
        if (cur==-1) return -1;
        int res=stack[cur];
        cur--;
        return res;

    }

    public void increment(int k, int val) {
        for (int i = 0; i <Math.min(cur+1,k) ; i++) {
            stack[i]+=val;
        }
    }
}
```