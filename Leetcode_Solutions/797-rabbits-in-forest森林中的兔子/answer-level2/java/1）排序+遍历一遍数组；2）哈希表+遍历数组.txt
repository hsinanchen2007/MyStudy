排序+遍历一遍数组
![2020021701.PNG](https://pic.leetcode-cn.com/799860fa169922f40bf899a975ed4989c481e1320091e7418a4facbd82c619e5-2020021701.PNG)
哈希表+遍历数组
![2020021702.PNG](https://pic.leetcode-cn.com/6f4fab16b6db68a293b512bc34bbd081722ea6b136fbd3efc09e51fca0c54b3a-2020021702.PNG)

### 解题思路
最少数量:
回答数为0的兔子,说明该颜色兔子只有一只;
回答数为n(n>0)的兔子,说明该颜色兔子有(n+1)只;
但是,回答数为n(n>0)的众多兔子当中,存在互指(如三兄弟A1，A2，A3中,A2是A1和A3共有的兄弟),即在不为0的报数中,存在重复报数的情况,
为了得到最小的兔子数量,需要把重复计数的兔子去掉,
所以,首先对报数均为n(n>0)的兔子进行计数cnt,若cnt<(n+1);
则报数为n的颜色的兔子个数为(n+1);
若cnt>n,怎报数为n的颜色的兔子个数为：(cnt/(n+1))*(n+1)+(n+1);
所以,综上,最少数量兔子的计数公式为：
num = cnt/(n+1);
mod = cnt%(n+1);
当mod!=0时,minNum = num*(n+1)+(n+1);
当mod==0时,minNum = num*(n+1);
### 代码

```java
class Solution {
    public int numRabbits(int[] answers) {
//排序+遍历一遍数组
    	// int out =0;
    	// int cnt =0;
    	// Arrays.sort(answers);
    	// int left=0;
    	// int right=0;
    	// while(right<answers.length) {
    	// 	if(answers[right]==answers[left]) {
    	// 		cnt++;
    	// 		if(cnt==answers[left]+1) {
    	// 			out += answers[left]+1;
    	// 			cnt=0;
    	// 		}
    	// 	}else if(answers[right]!=answers[left]) {
    	// 		if(cnt!=0) {
    	// 			out += answers[left]+1;
    	// 		}
    	// 		cnt=1;
    	// 		left=right;
    	// 	}
    	// 	right++;
    	// }
    	// if(cnt!=0) {
    	// 	out += answers[left]+1;
    	// }
    	// return out;
//哈希表+遍历数组
        int out =0;
    	Map<Integer,Integer> recMap = new HashMap<>();
    	for(int i=0;i<answers.length;i++) {
    		if(!recMap.containsKey(answers[i])) {
    			recMap.put(answers[i], 1);
    		}else if(recMap.containsKey(answers[i])) {
    			recMap.put(answers[i], recMap.get(answers[i])+1);
    		}
    	}
    	for(int num:recMap.keySet()) {
    		if(recMap.get(num)<=(num+1) ) {
    			out += num+1;
    		}else if(recMap.get(num)>(num+1) ) {
    			out +=  recMap.get(num)/(num+1)*(num+1);
    			if(recMap.get(num)%(num+1)!=0) {
    				out +=(num+1);
    			}
    		}
    	}
    	return out;
    }
}
```