### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int [] output = new int[T.length];
        Stack<Integer> stack = new Stack<>();
        for(int i=0;i<T.length;i++){
            while (!stack.isEmpty()&&T[i]>T[stack.peek()]){
                int index = stack.pop();
                output[index] = i-index;
            }
            stack.push(i);
        }
        return output;
    }
}
```