### 解题思路
问题转化为数组中元素与下一个比它大的元素之间的距离
        Solution1: 暴力法 ---》两重循环
        Solution2： 维护一个递减栈
        数据结构：index+data 
        注意点：遍历整个数组，每遍历一个元素x,去和递减栈里的元素比较：
                1.若递减栈为空： x直接入栈
                2.递减栈不为空，栈顶元素小于x： 
                                            1）x.index-栈顶元素.index = 距离 
                                            2）栈顶元素出栈，继续比较直到栈顶元素大于x或者
                                            栈为空，此时x入栈

### 代码

```java
//定义数据结构
class Elem{
    public int index;
    public int data;
    public Elem(int index, int data){
        this.index = index;
        this.data = data;
    }
}

class Solution {
    public int[] dailyTemperatures(int[] T) {
        int [] res = new int[T.length];
        Stack<Elem> stack = new Stack<>();
        for(int i = 0 ; i<T.length ; ++i){
            Elem e = new Elem(i,T[i]);
            //栈为空
            if(stack.empty()||stack.peek().data>=T[i]) stack.push(e);
            else{
                while(!stack.empty()){
                    //栈顶元素小于e
                    if(stack.peek().data<T[i]){
                        Elem temp = stack.pop();
                        res[temp.index] = e.index-temp.index;
                    }else{
                        stack.push(e);
                        break;
                    }
                }
                //如果栈为空
                if(stack.empty()) stack.push(e);
            } 
        
        }
        return res;

    }
    
}

```