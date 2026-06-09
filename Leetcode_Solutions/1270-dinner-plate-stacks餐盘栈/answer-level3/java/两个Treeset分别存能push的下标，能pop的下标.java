## 解题思路
push了就肯定能pop
pop了就肯定能push
维护当前用了多少空间nowused = 栈个数 * capacity ——来O1反应出能不能push、pop
利用TreeSet的自动排序，增删 logn, 比遍历On好得多
因为只删除顶（可以理解为链尾）用链表删除O1，数组都行，这题不影响
```
import java.util.*;

/**
 * @author VVlhw
 * @date 2020/1/26 - 9:06
 */
class DinnerPlates {
    private int cap;
    //实时维护一个总空间来看有没有位置，省去遍历    100000*20000=2e9
    private long nowused;
    //infinite，所以我们用这个能动态增加,关键随机访问
    private List<MyStack> list;
    //S代表必然有得push，S2是必然有得pop
    private TreeSet<Integer> S = new TreeSet<>();
    private TreeSet<Integer> S2 = new TreeSet<>();

    private class MyStack {
        LinkedList<Integer> mystack;
        public MyStack() {
            //涉及删除 用链表
            mystack = new LinkedList<>();
        }

        public boolean isFull() {
            return mystack.size() >= cap;
        }

        public void AddLast(int val) {
            mystack.addLast(val);
        }

        public boolean isEmpty() {
            return mystack.size() == 0;
        }

        public int DeleteLast() {
            return mystack.removeLast();
        }
    }





    public DinnerPlates(int capacity) {
        //只是初始化每个栈capacity容量
        //局部内部类 不能用访问说明符，限定在这个局部块中
//        class MyStack {
//            List<Integer> mystack = new ArrayList<>(capacity);
//        }
//        List<MyStack> list = new ArrayList<>();
        cap = capacity;
        list = new ArrayList<>();
        //一开始0个
        nowused = list.size() * cap;
    }

    public void push(int val) {
        //尽可能找到左边还没满的放,一定能放,因为有infinite个
        //优化：你能放push，要么就是新开的 or 有栈pop过，那我用一个set（插入删除logn）存这些下标，
        if (nowused < 1L * list.size() * cap) {
//            for (int i = 0; i < list.size(); i++) {
//                if (!list.get(i).isFull()) {
//                    list.get(i).AddLast(val);
//                    break;
//                }
//            }
            //Treeset自动排序，first就是左边第一个能放的
            list.get(S.first()).AddLast(val);
            //放了肯定有得pop
            S2.add(S.first());
            nowused++;
            if (list.get(S.first()).isFull())
                S.pollFirst();
        }
        else {
            list.add(new MyStack());
            //肯定不满 除非capacity=0 新的 这个if一定成立
            if (!list.get(list.size() - 1).isFull()) {
                list.get(list.size() - 1).AddLast(val);
                //加了就有得pop
                S2.add(list.size() - 1);
            }
            nowused++;
            //看看加完是不是满，不满就它有的继续push 加入S
            if (!list.get(list.size() - 1).isFull())
                S.add(list.size() - 1);
        }

    }

    public int pop() {
        //尽可能找到右边还有的pop,全空就pop不了,返回-1
        //优化：你pop走了就一定有空位 一定能进S集合里面，能否快速找到，又弄一个最大堆？
        if (nowused == 0) return -1;
        int val = -1;
//        for (int i = list.size() - 1; i >= 0; i--) {
//            if (!list.get(i).isEmpty()) {
//                val = list.get(i).DeleteLast();
//                S.add(i);
//                break;
//            }
//        }
        //最大 即最右
        val = list.get(S2.last()).DeleteLast();
        //删了必然有得push
        S.add(S2.last());
        nowused--;
        //如果空了 就没得pop了
        if (list.get(S2.last()).isEmpty())
            S2.pollLast();
        return val;
    }

    public int popAtStack(int index) {
        //还要弄个越界处理index
        //就pop index那个栈,若它空就-1
        if (index < 0 || index >= list.size() || list.get(index).isEmpty()) return -1;
        //pop就有得push
        S.add(index);
        nowused--;
        int val = list.get(index).DeleteLast();
        if (list.get(index).isEmpty())
            S2.remove(index);
        return val;
    }

    public static void main(String[] args) {
        DinnerPlates dp = new DinnerPlates(2);
        dp.push(1);
        dp.push(2);
        dp.push(3);
        dp.push(4);
        dp.push(5);
        dp.popAtStack(0);
        dp.push(20);
        dp.push(21);
        dp.popAtStack(0);
        dp.popAtStack(2);
        dp.pop();
        dp.pop();
        dp.pop();
        dp.pop();
        dp.pop();
    }
}

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates obj = new DinnerPlates(capacity);
 * obj.push(val);
 * int param_2 = obj.pop();
 * int param_3 = obj.popAtStack(index);
 */
```
