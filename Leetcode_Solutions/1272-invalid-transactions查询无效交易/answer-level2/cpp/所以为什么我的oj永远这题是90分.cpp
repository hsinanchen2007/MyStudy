我只是想来找几个用例看看我哪儿错了 可是为什么我leetcode都过了 我oj还是90分呜呜呜呜呜

### 代码

```cpp
class Solution {
public:

    struct transaction {
	    string name;
	    int time;
	    int amount;
	    string city;
    };
    void stringToStruct(vector<string>&transactions, transaction*List,int n ) {
	    for (int i = 0; i < n; i++) {
		    string str = transactions[i];
		    int pos = str.find(','), prepos = 0;
		    List[i].name = str.substr(prepos, pos - prepos);
		    prepos = pos + 1;
		    pos = str.find(',', prepos);
		    List[i].time = stoi(str.substr(prepos, pos - prepos));
		    prepos = pos + 1;
		    pos = str.find(',', prepos);
		    List[i].amount = stoi(str.substr(prepos, pos - prepos));
		    List[i].city = str.substr(pos+1);
		    //cout << List[i].name << " " << List[i].time << " " << List[i].amount << " " << List[i].city << endl;
		}
    }
    void address(vector<string>&ans, transaction*List,int n){
        for(int i = 0;i<n;i++){
            string str = List[i].name+","+to_string(List[i].time)+","+to_string(List[i].amount)+","+List[i].city;
            if (List[i].amount > 1000) {
                ans.push_back(str);
            }
            else{
                for(int j = 0;j<n;j++){
                    if (i != j && List[i].name == List[j].name&&abs(List[i].time - List[j].time) <= 60&&List[i].city!=List[j].city) {
                        ans.push_back(str);
                        break;
                }
            }
            }
            
        }
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        transaction* List = new transaction[transactions.size()];
	    stringToStruct(transactions, List, transactions.size());
        vector<string>ans;
        address(ans,List,transactions.size());
        return ans;
    }
};
```