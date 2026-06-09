class Solution {
public:

    unordered_map<string,multiset<string>> travel;//multiset 对于插入的元素是自动排序的，如果插入的是string，就按照字典顺序进行排序，所以直接插入就好了。第二点：multiset中是允许元素重复的，所以其中可以插入相同的元素并进行排序。
    vector<string> res;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int size = tickets.size();
        if(size <= 0){
            return res;
        }
        for(auto ticket : tickets){
            travel[ticket[0]].insert(ticket[1]);
 //           if(travel[ticket[0]].size() > 1){//求size，这个就不用带*
 //               cout<<ticket[0] + "'s size is " + to_string(travel[ticket[0]].size())<<endl;
 //           }
        }

        DFS("JFK");

      return vector<string>(res.rbegin(), res.rend());//倒序输出
    }

    void DFS(string start){
        while(travel[start].size() > 0){
            string dest = *travel[start].begin();
            travel[start].erase(travel[start].begin());
            DFS(dest);   
        }
        res.push_back(start);
    }

};