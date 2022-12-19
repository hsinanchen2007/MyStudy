
# 几点坑需要注意
- 输入capacity可能为零，此时按题意是不能put任何元素
- 注意构造函数里实现capacity的处理
- put一次也相当于一次访问，频数也要加一
- 接上，新元素put后，频数按1处理

```
typedef int KEY;
typedef int VALUE;
typedef int FREQ;
typedef list<KEY>::iterator ITER;

class LFUCache {
	int capacity;
	int least_count;
	map<KEY,VALUE>mKV;
	map<FREQ, list<KEY> > mFL;
	map<KEY, FREQ> mKF;
	map<KEY, ITER> mKI;
public:
    LFUCache(int capacity):capacity(capacity),least_count(0) {
        cout<<"capacity="<<capacity<<endl;
    }
    
    int get(int key) {
    	int ret = _get(key);
    	cout <<"get("<<key<<"):" << ret << endl;
    	return ret;
    }

    int _get(int key) {
    	
    	if (mKV.count(key) == 0){
    		return -1;
    	}
    	FREQ freq = mKF[key];
    	FREQ freq_next = freq + 1;
    	ITER it = mKI[key];
    	list<KEY> & l = mFL[freq];
    	l.erase(it);
    	if (l.empty() && least_count == freq){
    		least_count = freq_next;
    	}
    	list<KEY> & l_next = mFL[freq_next];
    	l_next.push_back(key);    	
    	mKF[key] = freq_next;
    	mKI[key] = prev(l_next.end());
    	return mKV[key];
    }
    
    void put(int key, int value) {    	
    	_put(key, value);

    }
    void _put(int key, int value) {  
    	if (capacity == 0){
            return;
        }
    	cout <<"put("<<key<<","<<value<<"):";  	
    	if (mKV.count(key) == 0){
    		// new element; someone may be deleted
			FREQ freq = 1;
    		if (mKV.size() == capacity){
    			KEY key_to_erase = mFL[least_count].front();
    			cout <<"key_to_erase="<<key_to_erase<<",";
    			ITER iter_to_erase = mFL[least_count].begin();
    				cout <<"iter_to_erase,";
    			mKI.erase(key_to_erase);
    							cout <<"mKI.erase(key_to_erase),";
    			mFL[least_count].pop_front();
    			    			cout <<"mFL[least_count].pop_front();,";
    			mKV.erase(key_to_erase);
    			    			cout <<"mKV.erase(key_to_erase),";
    			mKF.erase(key_to_erase);
    			    			cout <<"mKF.erase(key_to_erase),";
    		
    			
    		}

    		mKF[key] = freq;
    		least_count = freq;
    		mFL[freq].push_back(key);
	    	mKI[key] = prev(mFL[freq].end());

    	}
    	else{
			//mKF[key] nothing;
			// ITER it = mKI[key];
			// FREQ freq = mKF[key];
			// mFL[freq].erase(it);
			// mFL[freq].push_back(key);
			// mKI[key] = prev(mFL[freq].end());

			FREQ freq = mKF[key];
	    	FREQ freq_next = freq + 1;
	    	ITER it = mKI[key];
	    	list<KEY> & l = mFL[freq];
	    	l.erase(it);
	    	if (l.empty() && least_count == freq){
	    		least_count = freq_next;
	    	}
	    	list<KEY> & l_next = mFL[freq_next];
	    	l_next.push_back(key);    	
	    	mKF[key] = freq_next;
	    	mKI[key] = prev(l_next.end());

    	}
    	mKV[key] = value;    	
		cout << endl;
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
