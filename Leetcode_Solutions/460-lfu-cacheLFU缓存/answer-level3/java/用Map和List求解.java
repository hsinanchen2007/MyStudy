![image.png](https://pic.leetcode-cn.com/6c4682ee107b2b8a70daf327a7629cdef5175613bce8120c5a55defeccafdf38-image.png)
因为题目提供了键值对，因此想到map存储cache的键值对，插入和删除操作很方便。
然后题目涉及到cache键值的使用频率和最不经常使用的键值，因此采用map2存储键的使用频率和可变长list存储最近使用的键。
当插入时，判断cache中键值的数量是否已达最大容量以及可能会忽略的cache中是否已存在要插入的键。
1⃣️若均不满足，则直接插入。注意插入map1时要在map2和list中同步更新。
2⃣️若已存在该键，覆盖其值，同步更新map2和list。
3⃣️否则，对map1中的键进行判断，将使用最少的键删除，注意删除时要同步更新map2和list。
源代码如下：

class LFUCache {

    Map<Integer,Integer> mymap1 = new HashMap<Integer,Integer>();//记录Cache中存在的键和值
    Map<Integer,Integer> mymap2 = new HashMap<Integer,Integer>();//记录键的使用次数
    List<Integer> mytime = new ArrayList<Integer>();//记录最近使用的键
    private int num=0;//记录当前cache键值对的数量
    private int capacity;//cache容量
    public LFUCache(int capacity) {
        this.capacity = capacity;
    }
    
    public void myaddoperation(int key) {
    	if (!mymap2.containsKey(key)) {
			mymap2.put(key,1);
		}else {
			mymap2.put(key,mymap2.get(key)+1);
		}
        if (mytime.contains(key)) {
        	mytime.remove(mytime.indexOf(key));
            mytime.add(key);
		}else {
			mytime.add(key);
		}
	}
    
    public void myremoveoperation(int key) {
    	mymap1.remove(key);
		mymap2.remove(key);
        mytime.remove(mytime.indexOf(key));
	}
    public int get(int key) {
    	if (capacity==0) {
			return -1;
		}
        if(mymap1.containsKey(key)){
        	myaddoperation(key);
            return mymap1.get(key);
        }else{
            return -1;
        }
        
    }
    
    public void put(int key, int value) {
    	if (capacity==0) {
			return ;
		}
        if(num<capacity&&!mymap1.containsKey(key)){
            num++;
            mymap1.put(key,value);
            myaddoperation(key);
        }else{
        	if (mymap1.containsKey(key)) {
				mymap1.put(key, value);
				myaddoperation(key);
	            return ;
			}
        	for (int mykey:mymap1.keySet()) {
				if (!mymap2.containsKey(mykey)) {
					myremoveoperation(mykey);
	                mymap1.put(key,value);
	                myaddoperation(key);
	                return ;
				}
			}
            int imin = Integer.MAX_VALUE;
            int iminkey = 0;
			for (int mykey:mymap2.keySet()) {
				if(mymap2.get(mykey)<imin){
                    imin = mymap2.get(mykey);
                    iminkey = mykey;
                }
			}
			List<Integer> mylist2 = new ArrayList<Integer>();
			for (int mykey:mymap2.keySet()) {
				if (mymap2.get(mykey)==imin) {
					mylist2.add(mykey);
				}
			}
            if(mylist2.size()<=1){
            	myremoveoperation(iminkey);
                mymap1.put(key,value);
                myaddoperation(key);
            }else{
                for(int i=mytime.size()-1;i>=0;i--){
                    if(mylist2.contains(mytime.get(i))&&mylist2.size()>1){
                        mylist2.remove(mylist2.indexOf(mytime.get(i)));
                    }
                    if(mylist2.size()==1){
                        break;
                    }
                }
                myremoveoperation(mylist2.get(0));
                mymap1.put(key,value);
                myaddoperation(key);
            }
        }
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
第一次困难题打卡，mark一下～

