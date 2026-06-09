### 解题思路
深度优先搜索, 具体思路见官方说明
**成绩较差,只是提供一种java解决Pair类问题的思路**
![image.png](https://pic.leetcode-cn.com/b209bb3d34d717656dfc285998419406e13341bb311d1abcb8f1eda57dfd53f6-image.png)

由于java中没有Pair类,导致状态判断时会非常麻烦
*	1. 最简单的处理手段应该是自定义一个Pair类
*	2. 常用方法为利用Map.Entry接口实现Pair类功能(不知道为什么,我对map.entry很抵触)

本例中利用java中的集合类来完成该功能
针对x桶的存水量stage_x,建立一组set集合,用以存放该stage_x下,所有遍历过的stage_y.
* 例: 
遍历过的状态为:
	*{<1,2>, <1,3>, <1,4>,<2,2>}*
在本例中被记录为:
	*{<1,{2,3,4}>,<2,{2}>}*

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if (z > x + y) return false;
		Stack<int[]> stack= new Stack<int[]>(); //遍历栈
		stack.push(new int[]{0,0});//初始化,两桶均为0
		HashMap<Integer,HashSet<Integer>> map = new HashMap<Integer,HashSet<Integer>>(); //判断状态是否被遍历过
		
		while(!stack.isEmpty()) {
			int[] stage =stack.pop(); //stage 存放当前x,y桶中的水量
			if(stage[0]==z || stage[1]==z || stage[0]+stage[1]==z)
				return true;
			
			//判断是否遍历过该状态
			HashSet<Integer> stage_y = map.get(stage[0]); //首先得到stage_x对应的stage_y的集合
			if(stage_y==null)
				stage_y=new HashSet<Integer>();
			if(!stage_y.contains(stage[1])) { //判断stage_y集合,是否包含stage[1]
				//将当前状态装入map中
				stage_y.add(stage[1]); //更新stage[0]对应的stage_y集合
				map.put(stage[0], stage_y); //更新map
				
				//x装满
				stack.push(new int[] {x,stage[1]});
				//x倒空
				stack.push(new int[] {0,stage[1]});
				
				//y装满
				stack.push(new int[] {stage[0],y});
				//y倒空
				stack.push(new int[] {stage[0],0});
				
				//x倒向y
				if(stage[0]>y-stage[1])//x 中的水多于y桶的剩余
					stack.push(new int[] {stage[0]-y+stage[1],y});
				else
					stack.push(new int[] {0,stage[0]+stage[1]});
				
				//y倒向x
				if(stage[1]>x-stage[0])//y 中的水多于x桶的剩余
					stack.push(new int[] {x,stage[1]-x+stage[0]});
				else
					stack.push(new int[] {stage[0]+stage[1],0});
			}
			
			
		}
		return false;	
    }
}
```