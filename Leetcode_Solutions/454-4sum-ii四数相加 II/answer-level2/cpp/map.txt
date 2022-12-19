### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
   int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    	int possibility = 0;
    	map<int, int> sum_ab_record;
    	for(auto& iter_A:A){
    		for(auto& iter_B:B){
    			int sum = iter_A + iter_B;
    			sum_ab_record[sum]++;
    		}
    	}
    	for(auto& iter_C:C){
    		for(auto& iter_D:D){
    			int target = -(iter_C + iter_D);
    			//if(sum_ab_record[target])
                if(sum_ab_record.count(target))
                {
    				possibility += sum_ab_record[target];
    			}
    		}
    	}

//    	//分治：判断A+B和C+D的结果是否相反——妈屄仍旧超时
//    	vector<int> sum_A_B;
//    	for(auto& iter_A:A){
//    		for(auto& iter_B:B){
//    			sum_A_B.push_back(iter_A + iter_B);
//    		}
//    	}
//    	vector<int> sum_C_D;
//    	for(auto& iter_C:C){
//    		for(auto& iter_D:D){
//    			sum_C_D.push_back(iter_C + iter_D);
//    		}
//    	}
//    	for(auto& iter:sum_A_B){
//    		vector<int> sum_C_D_bak(sum_C_D);
//    		while(std::find(sum_C_D_bak.begin(), sum_C_D_bak.end(), -iter) != sum_C_D_bak.end()){
//    			possibility++;
//    			auto ind = std::find(sum_C_D_bak.begin(), sum_C_D_bak.end(), -iter);
//    			sum_C_D_bak.erase(ind);
//    		}
//    	}

//    	//暴力法，超时
//    	for(auto& iter_A:A){
//    		for(auto& iter_B:B){
//    			for(auto& iter_C:C){
//    				for(auto& iter_D:D){
//    					if(!(iter_A+iter_B+iter_C+iter_D)) {
//    						possibility++;
//    					}
//    				}
//    			}
//    		}
//    	}
    	return possibility;
    }
};
```