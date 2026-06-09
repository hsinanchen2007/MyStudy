### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
    	int i_max = 0;
    	int f_x = 1;
    	if(x != 1){
        	while(f_x <= bound){
        		f_x *= x;
        		i_max++;
        	}
        	f_x /= x;
        	i_max--;
    	}

//    	//for debug
//    	cout << "i_max = " << i_max << endl;

    	int j_max = 0;
    	int f_y = 1;
    	if(y != 1){
        	while(f_y <= bound){
        		f_y *= y;
        		j_max++;
        	}
        	f_y /= y;
        	j_max--;
    	}

//    	//for debug
//    	cout << "j_max = " << j_max << endl;

    	set<int> s_powerful;
    	for(int i=0;i<=i_max;++i){
    		f_x = pow(x, i);
    		for(int j=0;j<=j_max;++j){
    			f_y = pow(y, j);
    			if(f_y <= (bound - f_x)){
    				s_powerful.insert(f_x + f_y);
    			}
    		}
    	}

    	vector<int> v_powerful;
    	for(auto& iter:s_powerful){
    		v_powerful.push_back(iter);
    	}
    	return v_powerful;
    }
};
```