![2020022702.PNG](https://pic.leetcode-cn.com/0216e1faf6422b27a551d9f35b9487d309c2b3859a3825b6e8fcb29289610379-2020022702.PNG)

### 解题思路
维护两个栈：
//维护两个栈来完成找到温度升高超过某日温度所需要的天数
//声明:数组out记录结果;
//声明栈stackTemp:记录温度;
//声明栈stackIndex:记录被压入栈stackTemp的温度对应的索引;
//先遍历一遍数组T:
//-1) 当stackTemp栈为空或者stackTemp栈顶元素表示的温度大于等于当前温度时,将当前温度和索引压入相应的栈中
//-2) 当stackTemp栈非空并且stackTemp栈顶元素表示的温度小于当前温度时,不断将栈stackTemp弹出元素,
//并且,stackIndex也相应弹出元素,记index=stackIndex.poll(),同时,计算(i-index)的值,并将该值赋给out[index];
//遍历完数组T后:
//判断stackIndex是否为空:
//-1)若栈stackIndex为空,直接返回结果out;
//-2)若栈stackIndex非空,则将stackIndex的元素不断弹出,记index=stackIndex.poll(),并将相应的out[index]赋值为0;
//最后返回out;
### 代码

```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
    	int[] out = new int[T.length];
    	Deque<Integer> stackTemp = new LinkedList<>();
    	Deque<Integer> stackIndex = new LinkedList<>();
    	int i=0;
    	while(i<T.length) {
    		if(stackTemp.peek()==null||stackTemp.peek()>=T[i]) {
    			stackTemp.push(T[i]);
    			stackIndex.push(i);
    			i++;
    		}else {
    			while(stackTemp.peek()!=null&&stackTemp.peek()<T[i]) {
    				stackTemp.poll();
    				int index = stackIndex.poll();
    				out[index] = i-index;
    			}
    		}
    	}
    	while(stackIndex.peek()!=null) {
    		int index=stackIndex.poll();
    		out[index]=0;
    	}
        return out;
        //##########
        //耗时:1131ms,击败:5.02%用户;
        //内存消耗:42.5MB,击败:54.78%用户;
        // int[] out = new int[T.length];
    	// boolean active = true; 
    	// for(int i=0;i<T.length;i++) {
    	// 	active = true;
    	// 	for(int k=i;k<T.length;k++) {
    	// 		if(T[k]>T[i]) {
    	// 			active = false;
    	// 			out[i] =k-i;
    	// 			break;
    	// 		}
    			
    	// 	}
    	// 	if(active) {
    	// 		out[i]=0;
    	// 	}
    	// }
        // return out;
    }
}
```