```
class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        map<char,int>hash;
        for(int i=0;i<guess.size();++i){//将guess中的元素计数；
            if(hash.find(guess[i])==hash.end()) hash[guess[i]]=1;
            else hash[guess[i]]++;
        }
        int sum=0,num=0;
        for(int i=0;i<solution.size();++i){
            if(hash.find(solution[i])!=hash.end()&&hash[solution[i]]>0){
                sum++;//找到所有的相同元素对，无论位置是否对得上；
                hash[solution[i]]--;
            }
            if(solution[i]==guess[i]) num++; //找到所有“猜中”的元素组数，用sum减去num就是“伪猜中”组数；
        }
        return {num,sum-num};
    }
};
```
