遍历数组，将数坐标压栈，若数比栈顶大，则找到升高的温度，再出栈，坐标相减，计算出天数，若比栈顶小，压栈。
最后栈里的坐标为不存在温度升高的天数。数组对应为0
```
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] res = new int[T.length];
        Stack<Integer> st = new Stack<>();
        if(T.length==0){
            return res;
        }
        
        for(int i=0;i<T.length;i++){
            while(!st.empty()&&T[st.peek()]<T[i]){
                res[st.peek()]=i-st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            res[st.pop()]=0;
        }
        return res;
    }
}
```
法二：暴力遍历，双循环。
```
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] res = new int[T.length];
        for(int i=0;i<T.length;i++){
            res[i]=0;
            for(int j=i+1;j<T.length;j++){
                if(T[j]>T[i]){
                    res[i]=j-i;
                    break;
                }
            }
        }
        return res;
    }
}
```

