想法还是很简单的，在一层一层遍历triangle的过程中，只要考虑每一层的边界点和中间节点即可，
对于中间节点，选择到达这个节点路径最短的上层节点。
还有不懂的可以看图片，字有点丑


![TIM图片20200105154133.jpg](https://pic.leetcode-cn.com/f2e9b21b75dce65ba0eaee98eaeae7fb06b1b2bfef533b15f4c0089bfce3c461-TIM%E5%9B%BE%E7%89%8720200105154133.jpg)

```
    public int minimumTotal1(List<List<Integer>> triangle) {	        
	        if(triangle.size()==0) return 0;
	        
	        List<Integer>sumlists=new  ArrayList<Integer>(triangle.get(0));
	        for(int i=1;i<triangle.size();i++) {
	        	//int temp=sumlists.get(sumlists.size()-1);	// 记录sumlist最后一个数，以免之后的for循环覆盖	        	
	        	int preInt=sumlists.get(0);  // 记录前一个数，以免被覆盖
	        	int curInt=0;
	        	sumlists.set(0, sumlists.get(0)+triangle.get(i).get(0)); // sumlist的第一个数，仍然是三角形的左边这一条边
	        	for(int j=1;j<triangle.get(i).size()-1;j++) {	        		
	        		curInt=sumlists.get(j);
	        		sumlists.set(j, Math.min(preInt,curInt)+triangle.get(i).get(j));
	        		preInt=curInt;
	        	}
	        	sumlists.add(preInt+triangle.get(i).get(triangle.get(i).size()-1));// sumlist的最后个数，仍然是三角形的右边左边这一条边
	        }
	         // 找出最小的这个值
	        int ans=sumlists.get(0);
	        for(int i=1;i<sumlists.size();i++) {
	        	if(ans>sumlists.get(i)) {
	        		ans=sumlists.get(i);
	        	}
	        }
	        return ans;
	    }
```
