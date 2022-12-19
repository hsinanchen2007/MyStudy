暴力解决

​	循环就完事了，需要注意的是，题目要求输出的是index，而不是结果，所以解答的时候要稍微注意下.  

```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] res = new int[T.length];

        for(int i =0;i < T.length;i++){
            int current = T[i];
            res[i]=0;
            for( int j = i+1;j<T.length;j++){
                if(T[j]>current){
                    res[i] = j-i;
                    break;
                }else{
                    continue;
                }
            }
        }
        return res;
    }
}
```
使用堆栈
从上面暴力解法的solution中， 我们留意到，我们在遍历后续元素进行了多余的遍历，例如，当index=2，current=75时，我们分别拿71，69，72与current比较，但均比current小，res[2]无法取得结果，需要继续遍历与current比较，但是在这个过程中，我们能够知道71，69的结果是72，即res[3],res[4]分别为2，1，所以在这个过程中我们进行了多余的遍历与比较，增加了时间开销，因此我们不妨将暂时获取得不到res的元素存放在堆栈中，当能得到res时，出栈，利用堆栈后进先出的特性（就近比较），这样我们仅仅需要遍历一边数组就可以得到答案，具体步骤如下：

1. 令res为返回的数组结结果, current=73, stack 为空,T[0]入栈(下标);
2. current = 74, index = 1, T[1] = 74>73? 是, **res[0] = 1-0=1**, T[0] 出栈; 
3. stack 为空, T[1]入栈;
4. current = 75, index = 2, T[2]=75>74? 是, **res[1] =2-1=1**, T[1]出栈; 
5. stack为空, T[2] 入栈; 
6. current = 71, index = 3, T[3] = 71>75 ? 否. T[3] 入栈; 
7. current = 69, index = 4,  T[4] = 69>71? 否. T[4] 入栈; 
8. current = 72, index = 5,  T[5] = 72>69? 是. **res[4] = 5-4 = 1**, T[4] 出栈；
9. current = 72, index = 5, T[5] = 72>71? 是. **res[3] = 5-3 = 2**, T[3] 出栈;
10. current = 72, index = 5, T[5]=72>75? 否, T[5]入栈; 
11. current = 76, index = 6, T[6] =76 >72? 是,  **res[5] = 6-5=1**, T[5] 出栈；
12. current = 76, index = 6, T[6] = 76 >75? 是, **res[2] = 6-2 = 4**,T[2] 出栈;
13. stack为空, T[6] 入栈;
14. current = 63, index = 7, T[7]=63>76? 否; T[7] 入栈;
15. 数组到达边界，弹出栈元素**res[7] =0;res[6]=0**. 

```java
class Solution{
    public int[] dailyTemperatures(int[] T) {
        int[] res = new int[T.length];
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i <T.length ; i++) {
            int current = T[i];
            while (!stack.isEmpty()&&current>T[stack.peek()]){
                int lastIndex = stack.peek();
                int last = T[lastIndex];
                if (current>last){
                    res[lastIndex] = i- lastIndex;
                    stack.pop();
                }
            }
            stack.push(i);
        }
        while (!stack.isEmpty()){
            int index = stack.pop();
            res[index] = 0;
        }
        return res;
    }
}
```