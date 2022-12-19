由于我是在探索卡片中写的，所以没看到内存情况，只能看到执行用时37ms，战胜了47.99%的提交记录。
一开始把数组内容全部初始化为0，没想到怎么解决。参考了评论区[@hrong](/u/hrong/)的初始化逻辑。
我看到评论区和题解里面有一些很神奇的搞法，比如一个数组，或者一个set解决一切……可以说是非常的厉害了。当然我的搞法也比较神奇。本题解完全基于用例规格产生，规格一变就搞不定了。
我看到一些看上去比较标准的做法用到了列表等。可能我以后会通过看jdk源码之类的方式来看下正经解法应该怎样。
```
class MyHashSet {
	int[][] numbers;

    /** Initialize your data structure here. */
    public MyHashSet() {
        numbers=new int[1000][1001];  
        //初始化数组，其中每行第一列是该bucket的数字个数
        //数组的大小完全基于测试用例的规格产生
        for(int i=0;i<1000;i++){
        	for(int j=0;j<1001;j++){
        		numbers[i][j]=-1;
        	}
        }
        //将数组初始化为-1
    }
    
    public void add(int key) {
        //把key分到第key%1000个桶中
    	int bucketNo=key%1000;
    	numbers[bucketNo][0]+=1;  //计数
    	numbers[bucketNo][numbers[bucketNo][0]+1]=key;
    }
    
    public void remove(int key) {
    	int bucketNo=key%1000;
    	if(numbers[bucketNo][0]==-1){
    		//说明这个桶里面还没有被放入key，就什么也不做
    	}else{
    		for(int i=1;i<=numbers[bucketNo][0]+1;i++){
    			if(numbers[bucketNo][i]==key){
    				numbers[bucketNo][i]=-1;  //相当于移除该处的key
    			}
    		}
    	}
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        int bucketNo=key%1000;
        if(numbers[bucketNo][0]==-1){
    		
    	}else{
    		for(int i=1;i<=numbers[bucketNo][0]+1;i++){
    			if(numbers[bucketNo][i]==key){
    				return true;
    			}
    		}
    	}
        return false;
    }
}
```
