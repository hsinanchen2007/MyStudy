整体思路是维护一个单调递减的栈。因为需要对栈进行操作所以用时并没有太大的优势。
不过因为栈需要保存的信息不多，空间复杂度不会超过o(n)，即少于线性。所以内存消耗较少。
也算是为大家提供另外一种思路。
具体的代码如下：
```
public int candy(int[] ratings) {
        int ans = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        for(int i=1;i<ratings.length;i++){
            if(ratings[i]<ratings[i-1]){
                if(stack.peek()==1){
                    ans+=stack.size();//如果上一个分发的糖果已经为1了，那么需要补充之前的分发的糖果数目。
                    stack.push(1);
                }
                else{
                    stack.push(stack.peek()-1);//暂时分发stack.peek()-1个糖果，并不是最优解。在后面的计算中会减掉。
                }
            }
            else{
                int peek;
                if(ratings[i]>ratings[i-1]){
                    if(stack.size()>1){
                        peek=2;//之前是递减的情况，所以最优情况为最后一位分到了1个糖果。新的栈的第一位是1。
                    }
                    else{
                        peek = stack.peek()+1;//一直是递增，只需要比上一个多一个糖果即可。
                    }
                }
                else{
                    peek = 1;
                }
                //还记得我们之前假设的分发糖果数目为stack.peek()-1吗，接下来这行把多分的糖果拿回来了。
                ans -= (stack.size()-1)*(stack.peek()-1);
                while (!stack.isEmpty()){
                    ans += stack.pop();
                }
                stack.push(peek);
            }
        }
        //同样的，stack里可能还有糖果，所以需要再计算一次。
        ans -= (stack.size()-1)*(stack.peek()-1);
        while (!stack.isEmpty()){
            ans += stack.pop();
        }
        return ans;
    }
```
