```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,1);
	vector<int> tmp;
	if(rowIndex<=1) return res;
	else{
		tmp = getRow(rowIndex-1);
		for(int i=0;i<tmp.size()-1;i++){
			res[i+1] = tmp[i] + tmp[i+1]
		}
	}
	return res;
    }
};
```