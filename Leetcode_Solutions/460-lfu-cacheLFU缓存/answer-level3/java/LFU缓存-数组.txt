PS应该不会只有我一个人用的是数组解决的吧
定义三个数组，分别存放关键字，值，频率
get和put时，频率+1，同时根据频率更新三个数组
简单粗暴，时间复杂度较高，104ms
```
public class LFUCache {
	int[] keys;
	int[] values;
	int[] frequency;
	int count=0;
	int max;
	
    public LFUCache(int capacity) {
    	keys=new int[capacity];
    	values=new int[capacity];
    	frequency=new int[capacity];
    	max=capacity;
    }
    public int search(int key) {
    	int index=-1;
    	//搜索索引
    	for(int i=0;i<count;i++){
    		if(keys[i]==key){
    			index=i;
    			break;
    		}    			
    	}
		return index;
    }
    //根据索引更新三个数组
    public int update(int index){
    	if(index==-1)
    		return -1;
    	//更新频率对应位置
    	frequency[index]++;
    	int j=index-1;
    	for(;j>=0&&frequency[j]<=frequency[index];j--){   	
    		swap(frequency,j,index);
    		swap(keys,j,index);
    		swap(values,j,index);
    		index--;
    	}
		return values[j+1];   
    }
    
        
    public int get(int key) {
    	//没有元素时，直接返回
    	if(count==0)
    		return -1;
    	//搜索索引
    	int index=search(key);
    	//返回更新后的索引
    	return update(index);
    }
    
    private void swap(int[] nums, int i, int j) {
		// TODO Auto-generated method stub
    	int tmp=nums[i];
    	nums[i]=nums[j];
    	nums[j]=tmp;	
	}
    
	public void put(int key, int value) {
		int index=search(key);
		//如果数组中已经存在该元素，更新值并更新索引
		if(index!=-1){
			values[index]=value;
			update(index);
			return;
		}
		//如果最大存0个元素，那么就不用存了
		if(max==0)
			return;
    	//检测当前缓存是否溢出
    	if(count==max){
    		//删除最后一个元素，替换为新的元素
    		keys[max-1]=key;
    		values[max-1]=value;
    		frequency[max-1]=0;    		
    		index=max-1;    		
    	}else{
    		//添加到缓存的count位置
    		keys[count]=key;
    		values[count]=value;
    		frequency[count]=0; 
    		index=count++;   		
    	}
    	//更新索引
    	update(index);
    }
}
```
