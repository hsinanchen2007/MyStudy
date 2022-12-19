### 解题思路
 算法思想:
 为每一个频率都维护一个栈,元素在新增的时候会出现低频率-->高频率的切换 
 频率的出现是由低向高,且是连续的, 如果最大频率是5, 一定处在频率是 4,3,2,1的栈
 此时不需要把低频率的元素删除,因为当出栈时候,元素有高频率-->低频率的切换,且元素的相对顺序没有变化
  使用一个map维护一个频率->stack映射表
  使用一个map维护元素出现的频率
  使用一个变量代表最大频率,因为只要有最高频率,其他的频率都可以知道,因为频率是有元素新增的时候,
 逐渐变大的, 当出栈时候,只需要判断当前最大频率维护的栈是否为空,如果为空,最大频率-1即可

### 代码

```java
class FreqStack {

    private int maxFreq;

    private Map<Integer,Integer> freq;//维护每个元素出现的频率

    private Map<Integer, Deque<Integer>> map;//维护频率--->栈的映射
    public FreqStack() {
        map =new HashMap<>();
        freq = new HashMap<>();
        maxFreq=0;
    }

    public void push(int x) {

        int f=freq.getOrDefault(x,0)+1;
        freq.put(x, f);//更新频率
        if(f>maxFreq){//实时更新最大频率
            maxFreq=f;
        }
        //不存在时,初始化之后开始操作
        map.computeIfAbsent(f, z -> new ArrayDeque<>()).push(x);
    }

    public int pop() {

        Integer k = map.get(maxFreq).pop();
        if(map.get(maxFreq).isEmpty()){//最大频率维护的栈为空时
            maxFreq--;
        }
        freq.put(k,freq.get(k)-1);
        return k;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
```