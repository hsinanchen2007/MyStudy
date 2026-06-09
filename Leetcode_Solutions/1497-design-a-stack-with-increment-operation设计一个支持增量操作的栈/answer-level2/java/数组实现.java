### 解题思路
用Java数组实现就好，注意pos初试指向-1就好

### 代码

```java
class CustomStack {

    int[] arr;
   int pos;
    public CustomStack(int maxSize) {
      arr=new int[maxSize];
      pos=-1;
    }
    
    public void push(int x) {
    	if(pos==arr.length-1){
    		return ;
    	}
    	if(pos+1<arr.length){
    		arr[pos+1]=x;
    		pos=pos+1;
    	}

    }
    
    public int pop() {
     if(pos==-1)
    	 return -1;
     else {
    	 int temp=arr[pos];
    	 pos--;
    	 return temp;
     }  	 
    }
    
    public void increment(int k, int val) {
        if(k>pos){
        	for(int i=0;i<=pos;i++){
        		arr[i]=arr[i]+val;
        	}
        	
        }
        else{
        	for(int i=0;i<k;i++){
        		arr[i]=arr[i]+val;
        	}
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */
```