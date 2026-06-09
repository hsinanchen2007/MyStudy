#### 思路
1. 使用TreeMap 保存<值，数量>
2. getMin方法，调用TreeMap的getFirstKey即可获得最小值
3. 其他方法，push和pop的时候注意修改map就可以了
4. 这个方法。。写起来不太费脑子，也就导致了时间复杂度不太好。。
#### 代码
```java
class MinStack {


        TreeMap<Integer,Integer> map=new TreeMap<>();
        Stack<Integer> stack;

        public MinStack() {
            stack=new Stack<>();
        }

        public void push(int x) {
            stack.push(x);
            if (map.containsKey(x)){
                map.put(x,map.get(x)+1);
            }else {
                map.put(x,1);
            }
        }

        public void pop() {
            Integer pop = stack.pop();
            Integer value = map.get(pop);
            if (value==1){
                map.remove(pop);
            }else{
                map.put(pop,value-1);
            }

        }

        public int top() {
            return stack.peek();
        }

        public int getMin() {
           return map.firstKey();
        }
}
```
