之所以用前缀和和单调栈的,请参考以下两个链接(将本题转化为最大宽度坡问题))
- https://leetcode-cn.com/problems/longest-well-performing-interval/solution/qian-zhui-he-dan-diao-zhan-python3-by-smoon1989/
- leetcode-cn.com/problems/longest-well-performing-interval/solution/can-kao-liao-ji-ge-da-shen-de-ti-jie-zhi-hou-zong-/

```java
class Solution {
	//假设传入[9,9,6,0,6,6,9]
    public int longestWPI(int[] hours) {
    	int res=0;
    	// 修改hours 初始化单调栈
    	for(int i=0;i!=hours.length;i++) {
    		if(hours[i]>8) {
    			hours[i]=1;//劳累
    		}else {
    			hours[i]=-1;//不劳累
    		}
    	}//此时hours转化为1 -1形式的数组[1, 1, -1, -1, -1, -1, 1]
    	
    	//构建前缀和数组
    	int[]prefixSum=new int[hours.length+1];//多的一个是首位,表示一个元素也没有的前缀和
    	prefixSum[0]=0;
    	for(int i=1;i!=prefixSum.length;i++) {
    		prefixSum[i]+=hours[i-1]+prefixSum[i-1];
    	}//此时hours存前缀和[0, 1, 2, 1, 0, -1, -2, -1]
    	
    	//单调栈(栈底朝栈顶方向递减)
    	Stack<Integer> stack =new Stack<Integer>();
    	stack.add(0);//从0开始构建单调栈,0是什么都不存的状态
    	for(int i=1;i!=prefixSum.length;i++) {
    		if(prefixSum[i]<prefixSum[stack.peek()]) {
    			stack.add(i);
    		}
    	}//此时栈中存:[0,5,6], 其对应到前缀和数组,一定是零和负数
        //当然也有可能只有0,则说明前缀和都是正数,所以结果中i就位0,j为len-1

    	// 当prefixSum[j]>prefixSum[i]时,条件成立,此时的j-i为候选res
    	// 相当于找 最大宽度坡
    	//从后往前遍历找j, 并从栈中弹i
    	for(int j=prefixSum.length-1;j!=-1;j--) {
    		// 当[j]比栈顶元素大时, 不断pop找出最小的i
    		while(!stack.isEmpty()&&prefixSum[j]>prefixSum[stack.peek()]) {
    			res=Math.max(res, j-stack.pop());
    		}
    		//若栈为空或者栈顶元素比当前元素[j]还大或等于:[i]>=[j]
            //直接j--, 继续下轮循环
    	}
    	return res;
    }
}
```
